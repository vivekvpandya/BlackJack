#include "networkoperationmanager.h"

NetworkOperationManager::NetworkOperationManager()
{

}

void NetworkOperationManager::connectToHost(const QHostAddress &address, quint16 port)
{
    connectionSocket.connectToHost(address,port);
}

quint16 NetworkOperationManager::multicastDatagram(const QByteArray &datagram, const QHostAddress &host, quint16 port)
{
   return multicastSocket.writeDatagram(datagram,host,port);
}
