// This product is designed for service engineers to make there job of data collection and testing easy.
// This product offers user an ability to control all parameters while setting serial port to open and collect data from.
// This product also offers an ability to check whether incoming data is correct or wrong.
// Additionally this offers a feature of storing / recording incoming data in a file with its valid time stamp
// - Aakash Patwardhan 28th August 2024

#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Here i am creating an object for thread which is reading incoming serial data continuosly.
    SerialObj   =   new SerialThread(this);
    connect( SerialObj, SIGNAL(Signal_SendInData(QString, bool)), this, SLOT(slot_readSerial(QString, bool)) );

    // Initialising action message for user.
    ui  ->  label_actionMsg ->  setText( "Select All Configurations and Open Serial Port :)" );

    // This function sets initial setup for UI.
    slot_initialSetup();
}

MainWindow::~MainWindow()
{
    delete ui;
}

// This slot is used to fill up UI elemenst like dropdown and basically as name suggests initialsetup.
void MainWindow::slot_initialSetup()
{
    Q_FOREACH(QSerialPortInfo port, QSerialPortInfo::availablePorts())
    {

        ui -> comboBox_comPort  -> addItem(port.portName());

    }

    QStringList DiffBaudRates = {"4800", "9600", "19200", "38400", "115200"};
    QStringList DiffParity    = {"None", "Odd", "Even"};
    QStringList DiffFlowCtrl  = {"NO FLOW", "HARDWARE FLOW", "SOFTWARE FLOW"};
    QStringList DiffStopBits  = {"ONE", "TWO", "ONE & HALF"};
    QStringList DiffDataBits  = {"FIVE", "SIX", "SEVEN", "EIGHT"};

    ui -> comboBox_speed        -> addItems(DiffBaudRates);
    ui -> comboBox_parity       -> addItems(DiffParity);
    ui -> comboBox_dataBits     -> addItems(DiffDataBits);
    ui -> comboBox_stopBits     -> addItems(DiffStopBits);
    ui -> comboBox_flowControl  -> addItems(DiffFlowCtrl);

}

// This slot is used to fill users selected config into structure and passing it to serialThread.
void MainWindow::slot_fillStruct()
{
    CurrSerialInfo.Curr_BaudRate    = ui -> comboBox_speed         ->  currentText();
    CurrSerialInfo.Curr_DataBits    = ui -> comboBox_dataBits      ->  currentText();
    CurrSerialInfo.Curr_FlowControl = ui -> comboBox_flowControl   ->  currentText();
    CurrSerialInfo.Curr_Parity      = ui -> comboBox_parity        ->  currentText();
    CurrSerialInfo.Curr_Port        = ui -> comboBox_comPort       ->  currentText();
    CurrSerialInfo.Curr_StopBit     = ui -> comboBox_stopBits      ->  currentText();

    // Calling a function which will set serial port for thread who is going to read serial data continuosly
    SerialObj   ->  setupSerialPort(CurrSerialInfo);
}

// This slot is used to read the data coming from serialthread and representing it in UI.
void MainWindow::slot_readSerial(QString CurrInData, bool isDataValid)
{
    qDebug() << __LINE__ << CurrInData << isDataValid;

    // Filling correct data in text-edit
    ui  ->  Corr_Data_Display -> append(CurrInData);
}

// This button indicates that user has done filling all the configurations for serial port to open.
void MainWindow::on_pushButton_open_clicked()
{
    // Toggeling between open and close of current serial port
    isPortOpen  = !isPortOpen;

    if(isPortOpen)
    {
        // Updating btn title
        ui  -> pushButton_open  -> setText("CLOSE");

        // Updating action message for user
        ui  ->  label_actionMsg ->  setText( "If you want to record incoming data select checkbox :)" );

        // Calling function which is taking user info and filling structure
        slot_fillStruct();
    }

    else
    {
        // Updating btn title
        ui  -> pushButton_open  -> setText("OPEN");

        // Updating action message for user
        ui  ->  label_actionMsg ->  setText( "Open Serial Port By Clicking On OPEN Btn :)" );

        // Calling function which will close current comport which is open
        SerialObj   ->  closeSerialPort();
    }


}

