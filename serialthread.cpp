#include "serialthread.h"

SerialThread::SerialThread(QObject *Pointer)
{
    // qDebug() << __LINE__ << "Constructor of SerialThread";
}

SerialThread::~SerialThread()
{
    // qDebug() << __LINE__ << "Destructor of SerialThread";
}

void SerialThread::setupSerialPort(mySerial CurrSerial)
{
    qDebug() << __LINE__ << "Current Serial Configurations Selected By User - "
             << CurrSerial.Curr_Port << CurrSerial.Curr_BaudRate << CurrSerial.Curr_FlowControl << CurrSerial.Curr_Parity
             << CurrSerial.Curr_StopBit << CurrSerial.Curr_DataBits;

    bool ok  =  false;
    int  BR  =  (CurrSerial.Curr_BaudRate).toInt(&ok);

    // Setting PortName
    MyPort.setPortName(CurrSerial.Curr_Port);

    // Setting BaudRate
    MyPort.setBaudRate(BR);

    // Setting Parity Bytes
    if(CurrSerial.Curr_Parity == "Even")
    {
        MyPort.setParity( QSerialPort::EvenParity );
    }

    else if(CurrSerial.Curr_Parity == "Odd")
    {
        MyPort.setParity( QSerialPort::OddParity );
    }

    else if(CurrSerial.Curr_Parity == "None")
    {
        MyPort.setParity( QSerialPort::NoParity );
    }

    else
    {
        qDebug() << __LINE__ << "This Case is Not Possible for Parity";

        // NOTE :: There is also something called UNKOWNPARITY but it is strongly not recommended by QT
    }

    // Setting Flow Control
    if(CurrSerial.Curr_FlowControl == "NO FLOW")
    {
        MyPort.setFlowControl(QSerialPort::NoFlowControl);
    }

    else if(CurrSerial.Curr_FlowControl == "HARDWARE FLOW")
    {
        MyPort.setFlowControl(QSerialPort::HardwareControl);
    }

    else if(CurrSerial.Curr_FlowControl == "SOFTWARE FLOW")
    {
        MyPort.setFlowControl(QSerialPort::SoftwareControl);
    }

    else
    {
        qDebug() << __LINE__ << "This Case is Not Possible for Flow Control";

        // NOTE :: There is also something called UNKOWNFLOWCONTROL but it is strongly not recommended by QT
    }

    // Setting Current Stop Bit
    if(CurrSerial.Curr_StopBit == "ONE")
    {
        MyPort.setStopBits(QSerialPort::OneStop);
    }

    else if(CurrSerial.Curr_StopBit == "TWO")
    {
        MyPort.setStopBits(QSerialPort::TwoStop);
    }

    else if(CurrSerial.Curr_StopBit == "ONE & HALF")
    {
        MyPort.setStopBits(QSerialPort::OneAndHalfStop);
    }

    else
    {
        qDebug() << __LINE__ << "This Case is Not Possible for Stop Bits";

        // NOTE :: There is also something called UNKOWNSTOPBITS but it is strongly not recommended by QT
    }

    // Setting Current Data Bits
    if(CurrSerial.Curr_DataBits == "FIVE")
    {
        MyPort.setDataBits(QSerialPort::Data5);
    }

    else if(CurrSerial.Curr_DataBits == "SIX")
    {
        MyPort.setDataBits(QSerialPort::Data6);
    }

    else if(CurrSerial.Curr_DataBits == "SEVEN")
    {
        MyPort.setDataBits(QSerialPort::Data7);
    }

    else if(CurrSerial.Curr_DataBits == "EIGHT")
    {
        MyPort.setDataBits(QSerialPort::Data8);
    }

    else
    {
        qDebug() << __LINE__ << "This Case is Not Possible for Data Bits";

        // NOTE :: There is also something called UNKOWNDATABITS but it is strongly not recommended by QT
    }


    // If serial port defined by us is open,
    if (MyPort.open(QIODevice::ReadWrite))
    {
        // Connect the readyRead signal to the readData slot
        // Note : readyRead signal is sent by QSerialPort only when there is data coming on serial port.

        connect(&MyPort, &QSerialPort::readyRead, this, &SerialThread::readData_Serial);

        qDebug() << MyPort.portName() << " Serial port has been opened" << MyPort.canReadLine();

        // canReadLine() - Returns true if a line of data can be read from the serial port; otherwise returns false.

    }

    else
    {
        qDebug() << "Failed to open serial port for reading Incoming Data. " << MyPort.portName();
    }

}

// This will close current running serial port as per Users request
void SerialThread::closeSerialPort()
{
    // Closing Current Port Which is Open
    if(MyPort.isOpen())
    {
        MyPort.close();
    }
}

// This function is reading the incoming data from serial port and checking whether is it correct or wrong
// Based on its finding this function is sending current data and its validation bool to mainWindow
void SerialThread::readData_Serial()
{
    while(MyPort.bytesAvailable())
    {
        QByteArray CurrentByte = MyPort.read(1);

        if(CurrentByte.startsWith('$'))
        {
            MyData_incoming.clear();
        }

        MyData_incoming.append(CurrentByte);


        CurrentByte.clear();

        if (MyData_incoming.startsWith(QByteArray::fromHex("5aa5")) && MyData_incoming.length() == 78)
        {
            qDebug() << __FILE__ << __LINE__ << MyData_incoming.toHex(' ');
            QString incomingData  = QString::fromUtf8(MyData_incoming.toBase64());

            isDataCorrect         = true;

            emit Signal_SendInData(incomingData, isDataCorrect);

            MyData_incoming.clear();
        }

        if (MyData_incoming.endsWith("\r\n") && MyData_incoming.startsWith('$'))
        {

            char* MyData_char     = MyData_incoming.data();
            QString MyData_String = MyData_char;

            isDataCorrect         = true;

            emit Signal_SendInData(MyData_String, isDataCorrect);

            MyData_incoming.clear();

        }

        if(MyData_incoming.endsWith(0XAA))
        {
            qDebug() << __FILE__ << __LINE__ << MyData_incoming.toHex(' ');

            QString incomingData  = QString::fromUtf8(MyData_incoming.toBase64());

            isDataCorrect         = false;

            emit Signal_SendInData(incomingData, isDataCorrect);

            MyData_incoming.clear();

        }

    }

    // When you study this function you will see that there are still some drawbacks in this function mainly while checking NMEA data
    // As it is only checking starting and ending characters of the same and not checking checksum or actual data's correctness
    // This function needs continues testing both with correct and wrong data for whether it is identifying and classifying both of them
    // correctly or not. It is strongly recommended to check and verify this portion of code before actually using it with edge cases
    // - Aakash Patwardhan 28th August 2024

}
