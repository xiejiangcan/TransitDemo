#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QSettings"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    initParams();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::initParams(QString path)
{
    if(path.isEmpty())
        path = "config.ini";

    QSettings configRead(path, QSettings::IniFormat);

    ui->LE_sourceIP->setText(configRead.value("/ConnectConfig/SourceAddress", "192.168.111.101").toString());
    ui->LE_sourcePort->setText(configRead.value("/ConnectConfig/SourcePort", "8001").toString());
    ui->LE_targetIP->setText(configRead.value("/ConnectConfig/TargetAddress", "192.168.111.101").toString());
    ui->LE_targetPort->setText(configRead.value("/ConnectConfig/TargetPort", "8003").toString());
    ui->LE_hostPort->setText(configRead.value("/ConnectConfig/HostPort", "8002").toString());

    m_transit = new CMessageTransit(ui->LE_sourceIP->text(), ui->LE_sourcePort->text().toInt(),
                                    ui->LE_targetIP->text(), ui->LE_targetPort->text().toInt(),
                                    ui->LE_hostPort->text().toInt(), this);

    connect(m_transit, &CMessageTransit::showLog, this, &MainWindow::onShowLog);
}
void MainWindow::on_PB_reset_clicked()
{
    m_transit->setParams(ui->LE_sourceIP->text(), ui->LE_sourcePort->text().toInt(),
                         ui->LE_targetIP->text(), ui->LE_targetPort->text().toInt(),
                         ui->LE_hostPort->text().toInt());
}

void MainWindow::onShowLog(QString log)
{
    ui->TE_message->append(log);
}
