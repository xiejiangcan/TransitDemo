#ifndef CUDPSERVER_H
#define CUDPSERVER_H

#include <QObject>
#include <QUdpSocket>

class CUdpServer : public QObject
{
    Q_OBJECT
private:
    QUdpSocket* m_socket;
    QHostAddress m_address;
    quint16 m_port;

    bool m_isConnected;

public:
    explicit CUdpServer(QObject *parent = nullptr);
    CUdpServer(QHostAddress address, quint16 port, QObject* parent = nullptr);

    ~CUdpServer();

    void setParams(QHostAddress address, quint16 port);

    bool writeData(const QByteArray& data);
    bool writeData(const QByteArray& data,
                   const QHostAddress address,
                   const quint16 port);

    bool isConnected();

signals:
    void acceptData(QByteArray data);

public slots:
    void readPendingDatagrams();
    void onFoundhost();
    void onConnected();
    void onDisconnected();
    void onError(QAbstractSocket::SocketError error);
};

#endif // CUDPSERVER_H
