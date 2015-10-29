#include "networkoperationmanager.h"

NetworkOperationManager::NetworkOperationManager()
{

}

void NetworkOperationManager::connectToHost(const QHostAddress &address, quint16 port)
{
    connectionSocket.connectToHost(address,port);
}

qint64 NetworkOperationManager::multicastDatagram(const QByteArray &datagram, const QHostAddress &host, quint16 port)
{
   return multicastSocket.writeDatagram(datagram,host,port);
}

bool NetworkOperationManager::isConnected()
{
    return connectionSocket.isValid();
}

QString NetworkOperationManager::networkConnectionError()
{
    return connectionSocket.errorString();
}

