#include "bai2.h"
#include "ui_bai2.h"
#include<QInputDialog>
#include<QDebug>
#include<QTimer>
#include<QMessageBox>
#include<QMovie>
int a,b;
Bai2::Bai2(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Bai2)
{


    ui->setupUi(this);
    setWindowTitle(QString::fromUtf8("Bài 2: Thuật Toán Euclid"));

    QTimer *time;
    /*ui->pushButtonA->hide();
    ui->pushButtonB->hide();
    ui->pushButtonX->hide();
    ui->label->hide();
    ui->label_2->hide();
    ui->label_3->hide();*/
    time=new QTimer(this);
    time->setSingleShot(true);
    QMessageBox::about(this,QString::fromUtf8("Giới thiệu : Thuật toán Euclid")
                       ,
                       QString::fromUtf8("<br>Trong lý thuyết số học , thuật toán Euclid là một thuật toán cổ để xác định ước số chung lớn nhất (ƯSCLNN-tắt tiếng Việt; hoặc tiếng Anh GCD – Greatest Common Divisor) của 2 phần tử thuộc vùng Euclid (ví dụ: các số nguyên). </br>"
                                         "<center><b><br>Lịch sử của thuật toán</br></b></center>"
                                         "<br>Thuật toán Euclid là một thuật toán cổ xuất hiện trong cuốn Euclid’s Elements khoảng năm 300 trước công nguyên. Euclid khởi đầu đã trình bày rõ ràng vấn đề về phương diện hình học, như vấn đề tìm ra một thước đo chung cho độ dài hai đường thẳng, và thuật toán của ông đã xử lý bằng cách lặp lại phép trừ đoạn dài hơn cho đoạn ngắn hơn. </br>"
                                         "<br></br>"
                                         "<br>Tuy thuật toán này được biết đến sóm hơn bởi Eudoxus of Cnidus (khoảng năm 375 trước công nguyên) và Aristotle (khoảng năm 330 trước công nguyên), nhưng Euclide vẫn là người có công lớn nhất nên thuật toán được mang tên ông.</br>"
                                         "<br></br>"
                                         "<center><br>...........</br></center>"
                                         "<br></br>"
                                         "<b>Đọc thêm tại:</b>  <a href='https://vi.wikipedia.org/wiki/Giải_thuật_Euclid'>https://vi.wikipedia.org/wiki/Giải_thuật_Euclid</a>"
                                         )

                       );
    time->singleShot(1000,this,SLOT(dung()));
    QMovie *movie = new QMovie("tuyetroi.gif");
    ui->label_4->setMovie(movie);
    movie->start();

}

Bai2::~Bai2()
{
    delete ui;
}
int Bai2::getInputValue(QString name)
{

    bool ok=false;
        QString s=QString::fromUtf8("Xin nhập...");
        int value = QInputDialog::getInt(this, tr("%1").arg(s),name, 2,-9999999,9999999,1,&ok);
        if(ok)
            return value;
        else
            return -1;
}
int Bai2::thuatToanEuclid(int a, int b)
{
    int x=a;
    int y=b;
    while(y!=0)
    {
        int r=x%y;
        x=y;
        y=r;
    }
    return x;
}

void Bai2::dung()
{
    a=getInputValue(QString::fromUtf8("Nhập vào a:"));
    b=getInputValue(QString::fromUtf8("Nhập vào b:"));
    while(a==-1||b==-1){
        if(QMessageBox::question(this,QString::fromUtf8("Thoát?"),QString::fromUtf8("Bạn vừa hủy bỏ nhập,nhấn Ok để thoát,Cancel để nhập lại"),QMessageBox::Ok,QMessageBox::Cancel)==QMessageBox::Ok)
           { this->close();
            break;
        }

        else
        {
             a=getInputValue(QString::fromUtf8("Nhập vào a:"));
             b=getInputValue(QString::fromUtf8("Nhập vào b:"));
        }

    }


    ui->pushButtonA->setText(QString::number(a));

    ui->pushButtonB->setText(QString::number(b));
    int x=thuatToanEuclid(a,b);
    ui->pushButtonX->setText(QString::number(x));}
   /* ui->pushButtonA->show();
        ui->pushButtonB->show();
        ui->pushButtonX->show();
        ui->label->show();
        ui->label_2->show();
        ui->label_3->show();*/




void Bai2::on_pushButton_clicked()
{
     ui->pushButtonA->setText("");
     ui->pushButtonB->setText("");
     ui->pushButtonX->setText("");
     dung();

}

void Bai2::on_pushButton_2_clicked()
{
    this->close();
}
