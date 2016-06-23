#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMovie>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    int getInputValue(QString name);


private slots:
    void on_actionUs_triggered();

    void on_actionQT_triggered();
    void noticeBox();
    void kiemTraNguoiDung();

    void on_actionB_i_1_triggered();

    void on_actionB_i_2_triggered();

    void on_actionB_i_3_triggered();

    void on_pushButton1_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_actionExit_triggered();

    void on_actionExit_2_triggered();

private:
    Ui::MainWindow *ui;

};

#endif // MAINWINDOW_H
