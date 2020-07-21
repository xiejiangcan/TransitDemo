#include "cmessagetransit.h"

CMessageTransit::CMessageTransit(QString sourceAddress, quint16 sourcePort,
                                 QString targetAddress, quint16 targetPort,
                                 quint16 hostPort, QObject *parent)
    : QObject(parent)
{
    m_accept = new CMessageAccept(sourceAddress, sourcePort, this);
    m_sender = new CMessageSender(targetAddress, targetPort, hostPort, this);
    m_sender->start();
}

CMessageTransit::~CMessageTransit()
{
    if(m_sender->isRunning()){
        m_sender->stop();
        m_sender->wait();
    }
}

bool CMessageTransit::enqueue(const QByteArray& data)
{
    m_messages.enqueue(data);
    QString log = "accept the data : " + data + " from source";
    emit showLog(log);
    return true;
}

bool CMessageTransit::dequeue(QByteArray &data, bool isBusy)
{
    if(m_messages.isEmpty())
        return false;
    data = m_messages.dequeue();
    QString target = isBusy ? "host device" : "data center";
    QString log = "send the data : " + data + "to " + target;
    emit showLog(log);
    return true;
}

void CMessageTransit::setParams(QString sourceAddress, quint16 sourcePort,
                                QString targetAddress, quint16 targetPort,
                                quint16 hostPort)
{
    m_accept->setParams(sourceAddress,  sourcePort);
    m_sender->setParams(targetAddress, targetPort, hostPort);
}
