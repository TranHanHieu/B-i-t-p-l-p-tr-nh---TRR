#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"bai1.h"
#include"bai2.h"
#include"bai3.h"
#include<QString>
#include<QMessageBox>
#include<QDebug>
#include<QTimer>
#include<QInputDialog>
#include<QMovie>
#include<QPixmap>

bool test=false;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->pushButton1->setAutoFillBackground(true);
    ui->pushButton_2->setAutoFillBackground(true);
    ui->pushButton_3->setAutoFillBackground(true);
    ui->pushButton1->setStyleSheet("background-color: rgb(252,218,213);color: rgb(223,0,41);");
    ui->pushButton_2->setStyleSheet("background-color: rgb(252,218,213);color: rgb(223,0,41);");
    ui->pushButton_3->setStyleSheet("background-color: rgb(252,218,213);color: rgb(223,0,41);");
    setWindowTitle(QString::fromUtf8("Bài tập lập trình môn toán rời rạc! by Hieukoy vs Tranharo"));
    QMovie *movie = new QMovie("tuyetroi.gif");
    ui->label_2->setMovie(movie);
    movie->start();


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionUs_triggered()
{
    QString s=QString::fromUtf8("Về chúng tôi");
    QMessageBox::about(this, tr("%1").arg(s),
            QString::fromUtf8(
               "<center><h2>ZzZ</h2>"
               "Bài tập bộ môn toán rời rạc"
               "<br><br>"
               "<b>- Đại Học Thủy lợi - TLU</b>"
               "<br><br>"
               "<b>Trưởng nhóm:</b>  Hoàng Trần Hảo"
               "<br><br>"
               "<b>Thành viên của nhóm:</b>  Trần Hán Hiếu"
               "<br><br>"
               "<b>Hà Nội ,2016</b>"
               "<br>"
               "<b>GitHub của tôi:</b>  <a href='https://github.com/hoanghaockpt195'>https://github.com/hoanghaockpt195</a>"
               "<br></br>"

               "<br>......</br>"
               "<br></br>"
               "<br></br>"
               "<b>Facebook của Hảo:</b>  <a href='https://fb.com/hoangtranhao95'>https://fb.com/hoangtranhao95</a>"
               "<br></br>"
               "<br></br>"
               "<br></br>"
               "<b>Facebook của Hiếu:</b>  <a href='https://fb.com/hanhieu97'>https://fb.com/hanhieu97</a>"


               "<br><br></center>"
               ));
}

void MainWindow::on_actionQT_triggered()
{
    qApp->aboutQt();
}


int MainWindow::getInputValue(QString name)
{   bool ok=false;
    QString s=QString::fromUtf8("Xin nhập...");
    int value = QInputDialog::getInt(this, tr("%1").arg(s),name, 2,1,3,1,&ok);
    if(ok)
        return value;
    else
        return -1;

}
void MainWindow::noticeBox()
{


    int value=getInputValue(QString::fromUtf8("Nhập vào bài tập bạn muốn 1->3 "));
    if(value==1)
        on_actionB_i_1_triggered();
    else
        if(value==2)
        on_actionB_i_2_triggered();
        if(value==3)
            on_actionB_i_3_triggered();
        if(value==-1)
            QMessageBox::critical(this,QString::fromUtf8("Lỗi"),QString::fromUtf8("Xin nhập lại!"),QMessageBox::Ok);


}
void MainWindow::kiemTraNguoiDung()
{
    if(test==false)
    {
        QTimer *timer;
        timer=new QTimer(this);
        timer->setSingleShot(true);
        //sau 6,5 giây tự động bắt chọn chương trình!

        timer->singleShot(6500,this,SLOT(noticeBox()));
    }

}

void MainWindow::on_actionB_i_1_triggered()
{
    Bai1 a;
    a.exec();
    test=true;
}

void MainWindow::on_actionB_i_2_triggered()
{
    Bai2 a;
    a.exec();
    test=true;
}

void MainWindow::on_actionB_i_3_triggered()
{
    Bai3 a;
    a.exec();
    test=true;
}

void MainWindow::on_pushButton1_clicked()
{
    on_actionB_i_1_triggered();
}

void MainWindow::on_pushButton_2_clicked()
{
    on_actionB_i_2_triggered();
}

void MainWindow::on_pushButton_3_clicked()
{
    on_actionB_i_3_triggered();
}

void MainWindow::on_actionExit_2_triggered()
{
    this->close();

}

void MainWindow::on_actionExit_triggered()
{
    this->close();
}
