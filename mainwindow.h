#ifndef MAINWINDOW_H
#define MAINWINDOW_H

// Adding Internal QT libraries
#include <QMainWindow>
#include <QSerialPort>
#include <QSerialPortInfo>

// Adding External User Defined libraries
#include "serialthread.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    // Adding structures objects
    mySerial    CurrSerialInfo;

    // This bool will check whether serial port is on/off
    bool isPortOpen = false;

private slots:
    void slot_initialSetup();                   // This slot is used to fill up UI elemenst like dropdown and basically as name suggests initialsetup.
    void slot_fillStruct();                     // This slot is used to fill users selected config into structure and passing it to serialThread.
    void slot_readSerial(QString, bool);        // This slot is used to read the data coming from serialthread and representing it in UI.

    void on_pushButton_open_clicked();          // This btn indicates that user has finished filling config for serial port to open

private:
    // Creating object of UI
    Ui::MainWindow *ui;

    // Creating objects of External User Defined Classes
    SerialThread   *SerialObj;

};
#endif // MAINWINDOW_H
