#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QSerialPortInfo>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    foreach (const QSerialPortInfo &info, QSerialPortInfo::availablePorts())
    {
        ui->COMcomboBox->addItem(info.portName());
    }
    ui->COMcomboBox->setCurrentIndex(0);

    serialPort = new QSerialPort();
    serialPort->setBaudRate(QSerialPort::Baud115200);
    serialPort->setDataBits(QSerialPort::Data8);
    serialPort->setFlowControl(QSerialPort::NoFlowControl);
    serialPort->setParity(QSerialPort::NoParity);
    serialPort->setStopBits(QSerialPort::OneStop);



    connect(ui->exitButton,SIGNAL(clicked(bool)),this,SLOT(on_exitButton_clicked()));
    connect(ui->connectButton,SIGNAL(clicked(bool)),this,SLOT(connect2controller()));
}

MainWindow::~MainWindow()
{
    delete ui;
    delete serialPort;
}



void MainWindow::on_exitButton_clicked()
{
    close();
}

void MainWindow::connect2controller()
{
    portName = ui->COMcomboBox->currentText();
    serialPort->setPortName(portName);

    if(serialPort->isOpen())
    {
        serialPort->close();
        ui->connectButton->setText("Połącz");
        statusBar()->showMessage("Rozłączono",5000);
    }
    else
    {
        serialPort->open(QIODevice::ReadWrite);
        if(serialPort->isOpen())
        {
           ui->connectButton->setText("Rozłącz");
           statusBar()->showMessage("Nawiązano połączenie z urządzeniem",5000);
        }
        else
        {
            ui->connectButton->setText("Połącz");
            statusBar()->showMessage("Nie można nawiązać połączenia z urządzeniem",5000);
        }


    }

}
