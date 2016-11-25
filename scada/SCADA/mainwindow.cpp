#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QSerialPortInfo>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    wartosc_zadana = 0;
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
    state = stop;



    connect(ui->exitButton,SIGNAL(clicked(bool)),this,SLOT(on_exitButton_clicked()));
    connect(ui->connectButton,SIGNAL(clicked(bool)),this,SLOT(connect2controller()));
    connect(ui->startMotor,SIGNAL(clicked(bool)),this,SLOT(StartStopMotor()));
    connect(serialPort,SIGNAL(readyRead()),this,SLOT(RecieveData()));
    connect(ui->horizontalSlider,SIGNAL(valueChanged(int)),this,SLOT(zadanaChanged()));
    connect(ui->zadaj,SIGNAL(clicked(bool)),this,SLOT(zadajPolozenie()));
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

void MainWindow::StartStopMotor()
{
    if(serialPort->isOpen())
    {
        if(state==stop)
        {
            state = start;
            QString temp = "rrrrrrrrrr";
            serialPort->write(temp.toStdString().c_str());
            ui->startMotor->setText("Zatrzymaj silnik");
        }
        else
        {
            state = stop;
            QString temp = "ssssssssss";
            serialPort->write(temp.toStdString().c_str());
            ui->startMotor->setText("Uruchom silnik");
        }
    }
    else
        statusBar()->showMessage("Brak połączenia z urządzeniem",5000);


}

void MainWindow::RecieveData()
{
    //statusBar()->showMessage("Daane",5000);
    r_data.append(serialPort->readAll());
    if(r_data.size()==10)
    {
        int i = 1;
        QString temp = r_data;
        QString str;
        ui->textEdit->append(temp);
        switch(r_data.at(0))
        {
            case 'x':
                while(r_data.at(i)!='k'&& (i<10))
                {
                    str += r_data.at(i);
                    i++;
                }
                x1 = str.toDouble();
                ui->textEdit->append(str);
                break;
            case 'y':
                while(r_data.at(i)!='k'&& (i<10))
                {
                    str += r_data.at(i);
                    i++;
                }
                ui->textEdit->append(str);
                x2 = str.toDouble();
                break;
        }
        r_data.clear();
    }

}

void MainWindow::zadanaChanged()
{
    wartosc_zadana = ui->horizontalSlider->value();
    ui->zadanaLabel->setText(QString::number(wartosc_zadana));

}

void MainWindow::zadajPolozenie()
{
    if(serialPort->isOpen())
    {
        QString zadana_str = "w"+QString::number(wartosc_zadana);
        while(zadana_str.length()<10)
            zadana_str += "k";
        serialPort->write(zadana_str.toStdString().c_str());
        ui->textEdit->append(zadana_str);
    }
    else
    {
        statusBar()->showMessage("Brak połączenia z urządzeniem!",5000);
    }
}
