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
}

MainWindow::~MainWindow()
{
    delete ui;
}

// This slot is used to fill up UI elemenst like dropdown and basically as name suggests initialsetup.
void MainWindow::slot_initialSetup()
{

}

// This button indicates that user has done filling all the configurations for serial port to open
void MainWindow::on_pushButton_open_clicked()
{

}

