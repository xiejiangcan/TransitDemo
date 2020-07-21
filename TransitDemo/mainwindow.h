#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <cmessagetransit.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void initParams(QString path = "");

private slots:
    void on_PB_reset_clicked();
    void onShowLog(QString log);

private:
    Ui::MainWindow *ui;
    CMessageTransit* m_transit;
};

#endif // MAINWINDOW_H
