#include "cmessagesender.h"
#include "cmessagetransit.h"

CMessageSender::CMessageSender(QString address, quint16 targetPort,
                               quint16 hostPort, QObject *parent)
    : QThread(parent)
    , m_hostPort(hostPort)
    , m_stop(false)
{
    m_busy = false;
    m_parent = qobject_cast<CMessageTransit*>(parent);
    m_sender = new CUdpServer(QHostAddress::LocalHost, 8004, this);
    connect(m_sender, &CUdpServer::acceptData, this, &CMessageSender::onAcceptData);
}

void CMessageSender::setParams(QString address, quint16 targetPort, quint16 hostPort)
{
    m_hostPort = hostPort;
    m_sender->setParams(QHostAddress::LocalHost, targetPort);
}

void CMessageSender::onAcceptData(QByteArray data)
{
    Q_UNUSED(data);
    m_busy = false;
}

void CMessageSender::sendMessage()
{
    QByteArray data;
    if(!m_parent->dequeue(data, m_busy))
        return;
    if(m_busy){
        m_sender->writeData(data, QHostAddress::LocalHost, 8002);
        m_busy = false;
    }else{
        m_sender->writeData(data, QHostAddress::LocalHost, 8003);
        m_busy = true;
    }
}

void CMessageSender::stop()
{
    m_stop = false;
}

void CMessageSender::run()
{
    m_stop = true;
    while(m_stop){
        sendMessage();
        msleep(100);
    }
}
