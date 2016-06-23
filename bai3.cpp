#include "bai3.h"
#include "ui_bai3.h"
#include<QMessageBox>
#include<QDebug>
#include<QList>
#include<QInputDialog>
#include<QMovie>
#include<QTimer>
int so;
Bai3::Bai3(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Bai3)
{
    ui->setupUi(this);
    QTimer *time;
    setWindowTitle(QString::fromUtf8("Bài 3: Sinh hoán vị liền sau của một hoán vị cho trước!"));
    QMessageBox::about(this,QString::fromUtf8("Giới thiệu : Sinh hoán vị liền sau của một hoán vị cho trước")
                       ,
                       QString::fromUtf8(
                                         "<center><br>...........</br></center>"
                                         "<br></br>"
                                         "<br><center>Thuật toán</center></br>"
                                         "<br><b>procedure</b> Hoán vị liền sau (a<sub>1</sub>, a<sub>2</sub>, ..., a<sub>n</sub>) (hoán vị của {1,2,...,n} khác (n, n－1, ..., 2, 1))</br>"
                                         "<br>j := n － 1</br>"
                                         "<br><b>while</b> a<sub>j</sub>  > a <sub>j+1</sub></br>"
                                         "<br>j := j － 1 {j là chỉ số lớn nhất mà a<sub>j</sub>  < a <sub>j+1</sub> }</br>"
                                         "<br>k := n</br>"
                                         "<br><b>while</b> a<sub>j</sub> > a<sub>k</sub></br>"
                                         "<br>k := k - 1 {a<sub>k</sub> là số nguyên nhỏ nhất trong các số lớn hơn a<sub>j</sub> và bên phải a<sub>j</sub>   .</br>"
                                         "<br>r := n</br>"
                                         "<br>đổi chỗ (a<sub>j</sub>, a<sub>k</sub>)</br>"
                                         "<br>s := j + 1</br>"
                                         "<br><b>while</b> r > s</br>"
                                         "<br>đổi chỗ (a<sub>r</sub>, a<sub>s</sub>)</br>"
                                         "<br>r := r - 1 ; s := s + 1</br>"
                                         "<br>{Điều này sẽ xếp phần đuôi của hoán vị ở sau vị trí thứ j theo thứ tự tăng dần.}</br>"

                                         "<br></br>"
                                         "<br><b><center>Đọc thêm tại:</b>  <a href='https://voer.edu.vn/m/sinh-cac-hoan-vi-va-to-hop/0febd2c1'>https://voer.edu.vn/m/sinh-cac-hoan-vi-va-to-hop/0febd2c1</a> để hiểu rõ hơn thuật toán!</center></br>"

                                         "<br></br>"
                                         "<br></br>"

                                         )

                       );
    time->singleShot(1000,this,SLOT(dung()));
    ui->pushButton_3->hide();
    QMovie *movie = new QMovie("tuyetroi.gif");
    ui->label->setMovie(movie);
    movie->start();
  //so=getInputValue(QString::fromUtf8("Xin nhập số sinh hoán vị:"));
  //int gt5=SinhHoanVi(so);
  //qDebug()<<gt5;

}

Bai3::~Bai3()
{
    delete ui;
}
QList <int> Bai3::getNumber(int a)
{ QList <int> number;
    while(a!=0){
        int x=a%10;
        a=a/10;
        number<<x;
    }
    return number;
}
QList<int> Bai3::sapXepSo(QList<int> a)
{
    QList <int> hth;
    for(int i=a.size()-1;i>=0;i--)
        hth<<a.at(i);
    return hth;
}
int Bai3::getInputValue(QString name)
{
    bool ok=false;
        QString s=QString::fromUtf8("Xin nhập...");
        int value = QInputDialog::getInt(this, tr("%1").arg(s),name, 2,12,9999999,1,&ok);
        if(ok)
            return value;
        else
            return -1;
}

int Bai3::SinhHoanVi(int a)
{
    QList <int>list;QString str;
    list=getNumber(a);
    list=sapXepSo(list);
    int dem=0;

    do{
    for(int i=0;i<list.size();i++)
        for(int e=i+1;e<list.size();e++)
            if(list.at(i)==list.at(e)){
                dem++;
                if(QMessageBox::question(this,QString::fromUtf8("Lỗi"),QString::fromUtf8("Số đã nhập không có hoán vị. Bạn có muốn thử với số khác không?"))==QMessageBox::Yes)
                {
                    ui->pushButton->setText("");
                    a=getInputValue(QString::fromUtf8("Xin nhập số sinh hoán vị:"));
                    ui->pushButton->setText(QString:: number(a));

                }else{
                    this->close();
                    break;
                }
                list=getNumber(a);
                list=sapXepSo(list);
            }
    // bắt đầu hàm sinh hoán vị
    int j=list.size()-2;
    //hàm ktra hoán vi
    int dem1=0;
    while(list.at(j)>list.at(j+1)){
        j=j-1;
        dem1++;
        if(dem1>=1){
            if(QMessageBox::question(this,QString::fromUtf8("Lỗi"),QString::fromUtf8("Số đã nhập không có hoán vị. Bạn có muốn thử với số khác không?"))==QMessageBox::Yes){
                ui->pushButton->setText("");
                a=getInputValue(QString::fromUtf8("Xin nhập số sinh hoán vị:"));
                ui->pushButton->setText(QString:: number(a));
            }else{
                this->close();
            }
            list=getNumber(a);
            list=sapXepSo(list);
            j=list.size()-2;
        }
    }

    while(list.at(j)>list.at(j+1))
        j=j-1;
        //dem1++;
        /*if(dem1==1){
            if(QMessageBox::question(this,QString::fromUtf8("Lỗi"),QString::fromUtf8("Số đã nhập không có hoán vị. Bạn có muốn thử với số khác không?"))==QMessageBox::Yes){
                a=getInputValue(QString::fromUtf8("Xin nhập số sinh hoán vị:"));
            }else{
                this->close();
            }
            list=getNumber(a);
            list=sapXepSo(list);
        }*/
    //qDebug()<<"j="<<j;
    int k=list.size()-1;//qDebug()<<"k="<<k;
    while(list.at(j)>list.at(k))
        k=k-1;
    int temp;
    temp=list.at(j);
    list.replace(j,list.at(k));
    list.replace(k,temp);
    int r=list.size()-1;
    int s=j+1;
    while(r>s)
    {
        temp=list.at(r);
        list.replace(r,list.at(s));
        list.replace(s,temp);
        r=r-1;
        s=s+1;
    }
    for(int i=0;i<list.size();i++)
    {
        //qDebug()<<list.at(i);
        str.append(QString::number(list.at(i)));
    }
    return str.toInt();
    }
    while(dem!=0);
}
void Bai3::dung()
{
    so=getInputValue(QString::fromUtf8("Xin nhập số sinh hoán vị:"));
    if(so==-1){
        this->close();
        //break;
    }else{
        ui->pushButton->setText(QString:: number(so));
        ui->pushButton_3->show();
        int gt5=SinhHoanVi(so);
        ui->pushButton_2->setText(QString::number(gt5));
    }
}

void Bai3::on_pushButton_4_clicked()
{
    ui->pushButton->setText("");
    ui->pushButton_2->setText("");
    dung();
}

void Bai3::on_pushButton_5_clicked()
{
    this->close();
}
