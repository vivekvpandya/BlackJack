#ifndef NETWORKOPERATIONMANAGER_H
#define NETWORKOPERATIONMANAGER_H
#include <QUdpSocket>
#include <QTcpSocket>

class NetworkOperationManager
{
public:
    NetworkOperationManager();
    qint64 multicastDatagram(const QByteArray &datagram, const QHostAddress &host, quint16 port);
    void connectToHost(const QHostAddress &address, quint16 port); // This is for TCPSocket

private:
    QUdpSocket multicastSocket;
    QTcpSocket connectionSocket;


};

#endif // NETWORKOPERATIONMANAGER_H
