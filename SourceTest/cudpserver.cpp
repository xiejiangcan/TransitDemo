#include "cudpserver.h"

#include <QDebug>

CUdpServer::CUdpServer(QObject *parent)
    : QObject(parent)
    , m_isConnected(false)
{
    m_socket = new QUdpSocket(this);
}

CUdpServer::CUdpServer(QHostAddress address, quint16 port, QObject* parent)
    : QObject(parent)
    , m_address(address)
    , m_port(port)
    , m_isConnected(false)
{
    m_socket = new QUdpSocket(this);
    m_socket->bind(address, port);
    connect(m_socket, &QUdpSocket::readyRead, this, &CUdpServer::readPendingDatagrams);
}

CUdpServer::~CUdpServer()
{

}

void CUdpServer::setParams(QHostAddress address, quint16 port)
{
    m_address = address;
    m_port = port;
    m_socket->bind(address, port);
}

bool CUdpServer::writeData(const QByteArray& data)
{
    qint64 ret = m_socket->writeDatagram(data, m_address, m_port);
    return ret == data.size();
}

bool CUdpServer::writeData(const QByteArray& data,
                           const QHostAddress address,
                           const quint16 port)
{
    qint64 ret = m_socket->writeDatagram(data, address, port);
    return ret == data.size();
}

bool CUdpServer::isConnected()
{
    return m_isConnected;
}

void CUdpServer::readPendingDatagrams()
{
    QByteArray data;
    while (m_socket->hasPendingDatagrams()) {
        QByteArray datagram;
        int size = m_socket->pendingDatagramSize();
        datagram.resize(size);
        QHostAddress sender;
        quint16 senderPort;

        m_socket->readDatagram(datagram.data(), datagram.size(),
                               &sender, &senderPort);
        data += datagram;
    }
    emit acceptData(data);
}

void CUdpServer::onConnected()
{
    m_isConnected = true;
}

void CUdpServer::onDisconnected()
{
    m_isConnected = false;
}

void CUdpServer::onFoundhost()
{
    m_isConnected = false;
}

void CUdpServer::onError(QAbstractSocket::SocketError error)
{
    Q_UNUSED(error)
    qDebug() << "Error: address is: " << m_address.toString() << " port is: "
             << m_port << " error is: " << m_socket->errorString();
}
