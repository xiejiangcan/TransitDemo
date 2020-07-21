#ifndef CMESSAGESENDER_H
#define CMESSAGESENDER_H

#include <QThread>
#include "cudpserver.h"

class CMessageTransit;
class CMessageSender : public QThread
{
    Q_OBJECT
private:
    CUdpServer* m_sender;
    CMessageTransit* m_parent;
    quint16 m_hostPort;
    bool m_busy;
    bool m_stop;

public:
    CMessageSender(QString address, quint16 targetPort,
                   quint16 hostPort, QObject *parent = nullptr);

    void setParams(QString address, quint16 targetPort,
                   quint16 hostPort);
    void stop();

protected:
    void run();

public slots:
    void onAcceptData(QByteArray data);

private:
    void sendMessage();
};

#endif // CMESSAGESENDER_H
