#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "cudpserver.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();
    void onAcceptData(QByteArray data);

private:
    Ui::MainWindow *ui;
    CUdpServer* m_host;
    CUdpServer* m_center;
    bool m_busy;
};

#endif // MAINWINDOW_H
