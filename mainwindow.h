#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_btnClose_clicked();
    void UpdateTime();


    void on_btnAddSec_clicked();

    void on_btnSubSec_clicked();

    void on_btnZeroMsec_clicked();

    void on_btnClose_2_clicked();

    void on_btnClose_3_clicked();

    void on_btnClose_4_clicked();

    void on_btnClose_5_clicked();

    void on_btnGetDateTime_clicked();

    void on_btnSetDateTime_clicked();

private:
    Ui::MainWindow *ui;
    QTimer * timer_1s;

};

#endif // MAINWINDOW_H
