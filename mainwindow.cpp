#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QTimer>
#include <QTime>
#include <QDate>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setWindowFlags (Qt::WindowCloseButtonHint | Qt::WindowMinimizeButtonHint| Qt::WindowStaysOnTopHint | Qt::FramelessWindowHint);

    move(0, 0);
    this->setMaximumWidth(480);
    this->setMaximumHeight(320);
    this->setFixedSize(this->size());

    timer_1s = new QTimer(this);
    QObject::connect(timer_1s, SIGNAL(timeout()), this, SLOT(UpdateTime()));
    timer_1s->start(50);
    on_btnGetDateTime_clicked();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btnClose_clicked()
{
    this->close();
}

void MainWindow::UpdateTime()
{
    ui->lblDate->setText(QDate::currentDate().toString());
    ui->lblTime->setText(QTime::currentTime().toString("hh:mm:ss:zzz"));
}

void AdjustTimeSecond(int addSec)
{
    struct tm time = { 0 };

    QDate crrDate = QDate::currentDate();
    QTime crrTime = QTime::currentTime();
    crrTime = crrTime.addSecs(addSec);

    //QTime::currentTime().
    time.tm_year =  crrDate.year()- 1900;
    time.tm_mon  = crrDate.month() - 1;
    time.tm_mday = crrDate.day();
    time.tm_hour = crrTime.hour();
    time.tm_min  = crrTime.minute();
    time.tm_sec  = crrTime.second();

    if (time.tm_year < 0) time.tm_year = 0;

    time_t t = mktime(&time);
    stime(&t);
}

void MainWindow::on_btnAddSec_clicked()
{
    AdjustTimeSecond(1);
}

void MainWindow::on_btnSubSec_clicked()
{
    AdjustTimeSecond(-1);
}

void MainWindow::on_btnZeroMsec_clicked()
{
    AdjustTimeSecond(0);
}

void MainWindow::on_btnClose_2_clicked()
{
    ui->sbHour->setValue(0);
}

void MainWindow::on_btnClose_3_clicked()
{
    ui->sbMinute->setValue(0);
}

void MainWindow::on_btnClose_4_clicked()
{
    ui->sbSec->setValue(0);
}

void MainWindow::on_btnGetDateTime_clicked()
{
    ui->sbYear->setValue(QDate::currentDate().year());
    ui->sbMonth->setValue(QDate::currentDate().month());
    ui->sbDay->setValue(QDate::currentDate().day());
    ui->sbHour->setValue(QTime::currentTime().hour());
    ui->sbMinute->setValue(QTime::currentTime().minute());
    ui->sbSec->setValue(QTime::currentTime().second());
}

void MainWindow::on_btnSetDateTime_clicked()
{
    struct tm time = { 0 };

    time.tm_year = ui->sbYear->value() - 1900;
    time.tm_mon  = ui->sbMonth->value() - 1;
    time.tm_mday = ui->sbDay->value();
    time.tm_hour = ui->sbHour->value();
    time.tm_min  = ui->sbMinute->value();
    time.tm_sec  = ui->sbSec->value();

    if (time.tm_year < 0) time.tm_year = 0;

    time_t t = mktime(&time);
    stime(&t);
}
