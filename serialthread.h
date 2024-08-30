#ifndef SERIALTHREAD_H
#define SERIALTHREAD_H

// Adding Internal QT libraries
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QDebug>
#include <QString>
#include <QThread>


// Adding External User Defined libraries
#include "SerialStructure.h"

class SerialThread : public QThread
{
    Q_OBJECT

public:
    explicit SerialThread(QObject *Pointer);
    ~SerialThread();

    QSerialPort MyPort;                         // Declaring Serial Port
    QByteArray  MyData_incoming;                // This ByteArray will contain incoming data from the user
    bool        isDataCorrect   = false;        // This is a flag to indicate is current data is true or false

public slots:
    void setupSerialPort(mySerial);             // This will setup all parameters of our port as per Users request
    void closeSerialPort();                     // This will close current running serial port as per Users request

private slots:
    void readData_Serial();                     // This function will actual starts reading from serial port when recvs ready read signal

signals:
    void Signal_SendInData(QString, bool);      // This Signal will emit current data from Thread to mainWindow
};

#endif // SERIALTHREAD_H
