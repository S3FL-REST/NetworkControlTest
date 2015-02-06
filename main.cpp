#include <QCoreApplication>

#include <QTcpSocket>
#include <QThread>

#include <QHostAddress>

#include <iostream>

#include "protocols/rest_network.h"

using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    rest_network dataTest;

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

            dataTest.SetLeftJoystick(i);
            dataTest.SetRightJoystick(-i);
            dataTest.SetRunMode(TELEOP);

            if (socket.state() != QAbstractSocket::ConnectedState) {
                qDebug() << "Socket Disconnected";
                continueSending = false;
                break;
            }

            qDebug() << dataTest.ToByteArray();

            //const char* send_data = dataTest.ToString().toStdString().c_str();
            socket.write(dataTest.ToByteArray());
            //socket.write(send_data);
            socket.flush();

            //qDebug() << i;
        }

    return -1;
}
