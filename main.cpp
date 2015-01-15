#include <QCoreApplication>

#include <QTcpSocket>
#include <QThread>

#include <QHostAddress>

#include <iostream>

#include "Protocols/rest_network.pb.h"

using namespace std;
using namespace rest_network;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    ControlNetworkData dataTest;

    QTcpSocket socket;
    socket.connectToHost("127.0.0.1", 3141);

    if (!socket.waitForConnected()) {
        qDebug() << "Unable to Connect";
        return -1;
    }

    bool continueSending = true;

    while (continueSending)
        for (int i = -255; i <= 255; i++) {
            a.thread()->msleep(10);

            dataTest.set_joy_left(i);
            dataTest.set_joy_right(-i);
            dataTest.set_mode(FULL_AUTON);

            if (socket.state() != QAbstractSocket::ConnectedState) {
                qDebug() << "Socket Disconnected";
                continueSending = false;
                break;
            }

            const char* send_data = dataTest.SerializeAsString().c_str();
            socket.write(send_data);
            socket.flush();

            qDebug() << i;
        }

    return -1;
}
