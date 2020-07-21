#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    m_busy = false;
    m_host = new CUdpServer(QHostAddress::LocalHost, 8002, this);
    m_center = new CUdpServer(QHostAddress::LocalHost, 8003, this);
    connect(m_center, &CUdpServer::acceptData, this, &MainWindow::onAcceptData);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    m_busy = !m_busy;
}

void MainWindow::onAcceptData(QByteArray data)
{
    Q_UNUSED(data)
    if(!m_busy)
        m_center->writeData("not busy", QHostAddress::LocalHost, 8004);
}
