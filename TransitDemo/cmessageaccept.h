#ifndef CMESSAGEACCEPT_H
#define CMESSAGEACCEPT_H

#include <QObject>

#include "cudpserver.h"

class CMessageTransit;
class CMessageAccept : public QObject
{
    Q_OBJECT
private:
    CUdpServer* m_accept;
    CMessageTransit* m_parent;

public:
    CMessageAccept(QString address, quint16 port, QObject *parent = nullptr);
    ~CMessageAccept(){}

    void setParams(QString address, quint16 port);

signals:

public slots:
    void onAcceptData(QByteArray data);
};

#endif // CMESSAGEACCEPT_H
