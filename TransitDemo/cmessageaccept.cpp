#include "cmessageaccept.h"
#include "cmessagetransit.h"

CMessageAccept::CMessageAccept(QString address, quint16 port, QObject *parent)
    : QObject(parent)
{
    m_parent = qobject_cast<CMessageTransit*>(parent);
    m_accept = new CUdpServer(QHostAddress::LocalHost, 8001, this);
    connect(m_accept, &CUdpServer::acceptData, this, &CMessageAccept::onAcceptData);
}

void CMessageAccept::onAcceptData(QByteArray data)
{
    m_parent->enqueue(data);
}

void CMessageAccept::setParams(QString address, quint16 port)
{
    m_accept->setParams(QHostAddress::LocalHost, port);
}
