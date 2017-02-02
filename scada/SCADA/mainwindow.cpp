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
    sample_palette = new QPalette();
    serialPort = new QSerialPort();
    serialPort->setBaudRate(QSerialPort::Baud115200);
    serialPort->setDataBits(QSerialPort::Data8);
    serialPort->setFlowControl(QSerialPort::NoFlowControl);
    serialPort->setParity(QSerialPort::NoParity);
    serialPort->setStopBits(QSerialPort::OneStop);
    state = stop;
    email = "";
    ui->setAlarm->setDisabled(true);
    emailSent = false;
    halarm = false;
    lalarm = false;
    alarmCanBeSet = false;



    setupPlot();


    connect(ui->exitButton,SIGNAL(clicked(bool)),this,SLOT(on_exitButton_clicked()));
    connect(ui->connectButton,SIGNAL(clicked(bool)),this,SLOT(connect2controller()));
    connect(ui->startMotor,SIGNAL(clicked(bool)),this,SLOT(StartStopMotor()));
    connect(serialPort,SIGNAL(readyRead()),this,SLOT(RecieveData()));
    connect(ui->horizontalSlider,SIGNAL(valueChanged(int)),this,SLOT(zadanaChanged()));
    connect(ui->zadaj,SIGNAL(clicked(bool)),this,SLOT(zadajPolozenie()));
    connect(ui->saveEmailBtn,SIGNAL(clicked(bool)),this,SLOT(saveAdress()));
    connect(ui->Hslider,SIGNAL(valueChanged(int)),this,SLOT(hSliderChanged()));
    connect(ui->Lslider,SIGNAL(valueChanged(int)),this,SLOT(lSliderChanged()));
    connect(ui->applyAlarmbtn,SIGNAL(clicked(bool)),this,SLOT(applyAlarams()));
    connect(ui->setAlarm,SIGNAL(stateChanged(int)),this,SLOT(alarmStatusChanged()));
    connect(this,SIGNAL(EmailSig()),this,SLOT(sendEmail()));
}

MainWindow::~MainWindow()
{
    delete ui;
    delete serialPort;
    delete sample_palette;
    //file->close();
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
            QString temp = "rrrrrrrrrrrrrrrrrrrr";
            serialPort->write(temp.toStdString().c_str());
            ui->startMotor->setText("Zatrzymaj silnik");
        }
        else
        {
            state = stop;
            QString temp = "ssssssssssssssssssss";
            serialPort->write(temp.toStdString().c_str());
            ui->startMotor->setText("Uruchom silnik");
        }
    }
    else
        statusBar()->showMessage("Brak połączenia z urządzeniem",5000);


}

void MainWindow::RecieveData()
{
    r_data.append(serialPort->readAll());
    if(r_data.size()==20)
    {
        QString temp = r_data;
        int i = 1;
        int i2 = 0;
        QString str;
        switch(r_data.at(0))
        {
            case 'x':
                while(r_data.at(i)!='y'&& (i<20))
                {
                    str += r_data.at(i);
                    i++;
                }
                ui->x1_disp->display(str);
                //ui->textEdit->append(str);
                x1 = str.toDouble();
                i++;
                i2 = 0;
                str.clear();
                while(r_data.at(i)!='\0'&& (i<20))
                {
                    str += r_data.at(i);
                    i++;
                    i2++;
                }
                x2 = str.toDouble();
                ui->x2_disp->display(str);
                //*stream << str << "\n";
                str.clear();

                if(x1 > hlimit)
                {
                    if(alarmCanBeSet)
                    {
                        if(!halarm)
                        {
                            halarm = true;
                            sample_palette->setColor(QPalette::WindowText, Qt::red);
                            ui->label_3->setPalette(*sample_palette);

                        }
                        if(ui->notification->isChecked())
                        {
                            if(x1 > hlimit*1.1)
                            {
                                if(!emailSent)
                                {
                                    emailSent = true;
                                    statusBar()->showMessage("Wysłano wiadomosc (H)",5000);
                                    //emit EmailSig();
                                }
                            }
                            else
                            {
                                 if(emailSent)
                                    emailSent = false;
                            }

                        }
                    }
                }else
                {
                    if(alarmCanBeSet)
                    {
                        if(halarm)
                        {
                            halarm = false;
                            sample_palette->setColor(QPalette::WindowText, Qt::black);
                            ui->label_3->setPalette(*sample_palette);
                        }
                    }
                }

                if(x1 < llimit)
                {
                    if(alarmCanBeSet)
                    {
                        if(!lalarm)
                        {
                            lalarm = true;
                            sample_palette->setColor(QPalette::WindowText, Qt::blue);
                            ui->label_6->setPalette(*sample_palette);
                        }
                        if(ui->notification->isChecked())
                        {
                            if(x1 < llimit*1.1)
                            {
                                if(!emailSent)
                                {
                                    emailSent = true;
                                    statusBar()->showMessage("Wysłano wiadomosc (L)",5000);
                                    //emit EmailSig();
                                }
                            }
                            else
                            {
                                 if(emailSent)
                                    emailSent = false;
                            }

                        }
                    }
                }
                else
                {
                    if(alarmCanBeSet)
                    {
                        if(lalarm)
                        {
                            lalarm = false;
                            sample_palette->setColor(QPalette::WindowText, Qt::black);
                            ui->label_6->setPalette(*sample_palette);
                        }
                    }
                }
                break;
        }
        double key = QDateTime::currentDateTime().toMSecsSinceEpoch()/1000.0;
        static double lastPointKey = 0;
        if (key-lastPointKey > 0.01) // at most add point every 10 ms
        {
          // add data to lines:
          ui->CustomPlot->graph(0)->addData(key, x1);
           ui->CustomPlot->graph(1)->addData(key, wartosc_zadana);
          ui->CustomPlot2->graph(0)->addData(key, x2);
          // set data of dots:
          ui->CustomPlot->graph(2)->clearData();
          ui->CustomPlot->graph(2)->addData(key, x1);
          ui->CustomPlot2->graph(2)->clearData();
          ui->CustomPlot2->graph(2)->addData(key, x2);
          // remove data of lines that's outside visible range:
          ui->CustomPlot->graph(0)->removeDataBefore(key-8);
          ui->CustomPlot2->graph(0)->removeDataBefore(key-8);
          // rescale value (vertical) axis to fit the current data:
          ui->CustomPlot->graph(0)->rescaleValueAxis(true);
          ui->CustomPlot2->graph(0)->rescaleValueAxis(true);
          lastPointKey = key;
        }
        // make key axis range scroll with the data (at a constant range size of 8):
        ui->CustomPlot->xAxis->setRange(key+0.25, 8, Qt::AlignRight);
        ui->CustomPlot->replot();

        ui->CustomPlot2->xAxis->setRange(key+0.25, 8, Qt::AlignRight);
        ui->CustomPlot2->replot();
        r_data.clear();
    }

}

void MainWindow::zadanaChanged()
{
    wartosc_zadana = ui->horizontalSlider->value()/180.0*3.14;
    ui->zadanaLabel->setText(QString::number(wartosc_zadana));


}

void MainWindow::zadajPolozenie()
{
    if(serialPort->isOpen())
    {
        QString zadana_str = "w"+QString::number(wartosc_zadana);
        while(zadana_str.length()<20)
            zadana_str += "k";
        serialPort->write(zadana_str.toStdString().c_str());

    }
    else
    {
        statusBar()->showMessage("Brak połączenia z urządzeniem!",5000);
    }
}

void MainWindow::setupPlot()
{
    ui->CustomPlot->addGraph(); // blue line
    ui->CustomPlot->graph(0)->setPen(QPen(Qt::blue));
    ui->CustomPlot->graph(0)->setBrush(QBrush(QColor(240, 255, 200)));
    ui->CustomPlot->graph(0)->setAntialiasedFill(false);
    ui->CustomPlot->addGraph(); // red line
    ui->CustomPlot->graph(1)->setPen(QPen(Qt::red));
    ui->CustomPlot->graph(0)->setChannelFillGraph(ui->CustomPlot->graph(1));
    ui->CustomPlot->yAxis->setRange(-4, 4);
    ui->CustomPlot->yAxis->setLabel("Położenie [rad]");

    ui->CustomPlot->addGraph(); // blue dot
    ui->CustomPlot->graph(2)->setPen(QPen(Qt::blue));
    ui->CustomPlot->graph(2)->setLineStyle(QCPGraph::lsNone);
    ui->CustomPlot->graph(2)->setScatterStyle(QCPScatterStyle::ssDisc);
    ui->CustomPlot->addGraph(); // red dot
    ui->CustomPlot->graph(3)->setPen(QPen(Qt::red));
    ui->CustomPlot->graph(3)->setLineStyle(QCPGraph::lsNone);
    ui->CustomPlot->graph(3)->setScatterStyle(QCPScatterStyle::ssDisc);

    ui->CustomPlot->xAxis->setTickLabelType(QCPAxis::ltDateTime);
    ui->CustomPlot->xAxis->setDateTimeFormat("hh:mm:ss");
    ui->CustomPlot->xAxis->setAutoTickStep(false);
    ui->CustomPlot->xAxis->setTickStep(2);
    ui->CustomPlot->axisRect()->setupFullAxesBox();


    // make left and bottom axes transfer their ranges to right and top axes:
    //connect(ui->CustomPlot->xAxis, SIGNAL(rangeChanged(QCPRange)), ui->CustomPlot->xAxis2, SLOT(setRange(QCPRange)));
    //connect(ui->CustomPlot->yAxis, SIGNAL(rangeChanged(QCPRange)), ui->CustomPlot->yAxis2, SLOT(setRange(QCPRange)));

    // setup a timer that repeatedly calls MainWindow::realtimeDataSlot:
    //connect(dataTimer, SIGNAL(timeout()), this, SLOT(realtimeDataSlot()));
   // dataTimer->start(0); // Interval 0 means to refresh as fast as possible

    ui->CustomPlot2->addGraph(); // blue line
    ui->CustomPlot2->graph(0)->setPen(QPen(Qt::blue));
    ui->CustomPlot2->graph(0)->setBrush(QBrush(QColor(240, 255, 200)));
    ui->CustomPlot2->graph(0)->setAntialiasedFill(false);
    ui->CustomPlot2->addGraph(); // red line
    ui->CustomPlot2->graph(1)->setPen(QPen(Qt::red));
    ui->CustomPlot2->graph(0)->setChannelFillGraph(ui->CustomPlot2->graph(1));
    ui->CustomPlot2->yAxis->setRange(-1, 1);
    ui->CustomPlot2->yAxis->setLabel("Prędkość [rad/s]");

    ui->CustomPlot2->addGraph(); // blue dot
    ui->CustomPlot2->graph(2)->setPen(QPen(Qt::blue));
    ui->CustomPlot2->graph(2)->setLineStyle(QCPGraph::lsNone);
    ui->CustomPlot2->graph(2)->setScatterStyle(QCPScatterStyle::ssDisc);
    ui->CustomPlot2->addGraph(); // red dot
    ui->CustomPlot2->graph(3)->setPen(QPen(Qt::red));
    ui->CustomPlot2->graph(3)->setLineStyle(QCPGraph::lsNone);
    ui->CustomPlot2->graph(3)->setScatterStyle(QCPScatterStyle::ssDisc);

    ui->CustomPlot2->xAxis->setTickLabelType(QCPAxis::ltDateTime);
    ui->CustomPlot2->xAxis->setDateTimeFormat("hh:mm:ss");
    ui->CustomPlot2->xAxis->setAutoTickStep(false);
    ui->CustomPlot2->xAxis->setTickStep(2);
    ui->CustomPlot2->axisRect()->setupFullAxesBox();
}


void MainWindow::saveAdress()
{
    email = ui->emailEdit->toPlainText();

}

void MainWindow::hSliderChanged()
{
    float hlimit_temp = ui->Hslider->value()/180.0*3.14;
    ui->HLabel->setText(QString::number(hlimit_temp));
}

void MainWindow::lSliderChanged()
{
    float llimit_temp = ui->Lslider->value()/180.0*3.14;
    ui->LLabel->setText(QString::number(llimit_temp));
}

void MainWindow::applyAlarams()
{
    hlimit = ui->Hslider->value()/180.0*3.14;
    llimit = ui->Lslider->value()/180.0*3.14;

    if(llimit >= hlimit)
    {
        ui->statusBar->showMessage("HLimit nie może być mniejszy od LLimit!",5000);
        ui->Hslider->setValue(0);
        ui->Lslider->setValue(0);
        hlimit = 0;
        llimit = 0;
        emit ui->Hslider->valueChanged(0);
        emit ui->Lslider->valueChanged(0);
        ui->setAlarm->setDisabled(true);
        /*halarm = false;
        lalarm = false;*/
    }
    else
        ui->setAlarm->setEnabled(true);



}

void MainWindow::alarmStatusChanged()
{
    if(ui->setAlarm->isEnabled())
    {
        if(ui->setAlarm->isChecked())
            alarmCanBeSet = true;
        else
        {
            emit ui->Hslider->valueChanged(0);
            emit ui->Lslider->valueChanged(0);
            alarmCanBeSet = false;
            halarm = false;
            lalarm = false;
            sample_palette->setColor(QPalette::WindowText, Qt::black);
            ui->label_6->setPalette(*sample_palette);
            ui->label_3->setPalette(*sample_palette);

        }
    }
    else
    {
        emit ui->Hslider->valueChanged(0);
        emit ui->Lslider->valueChanged(0);
    }

}

void MainWindow::sendEmail()
{
    smtp = new Smtp("testuser2846@gmail.com", "******", "smtp.gmail.com", 465);
    //connect(smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));
    smtp->sendMail("testuser2846@gmail.com", email , "ALARM!!!","Przekorczono wartości dopuszczalne");
    smtp->disconnect();
}
