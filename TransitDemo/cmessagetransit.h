#ifndef CMESSAGETRANSIT_H
#define CMESSAGETRANSIT_H

#include <QObject>
#include <QQueue>

#include "cmessageaccept.h"
#include "cmessagesender.h"

class CMessageTransit : public QObject
{
    Q_OBJECT
private:
    QQueue<QByteArray> m_messages;
    CMessageAccept* m_accept;
    CMessageSender* m_sender;

public:
    CMessageTransit(QString sourceAddress, quint16 sourcePort,
                    QString targetAddress, quint16 targetPort,
                    quint16 hostPort, QObject *parent = nullptr);

    ~CMessageTransit();

    void setParams(QString sourceAddress, quint16 sourcePort,
                   QString targetAddress, quint16 targetPort,
                   quint16 hostPort);

    bool enqueue(const QByteArray &data);
    bool dequeue(QByteArray &data, bool isBusy);

signals:
    void showLog(QString log);
};

#endif // CMESSAGETRANSIT_H
