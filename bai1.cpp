#include "bai1.h"
#include "ui_bai1.h"
#include"mainwindow.h"
#include<QDebug>
#include<QInputDialog>
#include<QMessageBox>
#include<QMovie>
Bai1::Bai1(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Bai1)
{
    ui->setupUi(this);


    setWindowTitle(QString::fromUtf8("Bài 1: Sắp xếp kiểu chèn nhị phân"));
    QMessageBox::about(this,QString::fromUtf8("Giới thiệu :Sắp xếp kiểu chèn nhị phân")
                       ,
                       QString::fromUtf8("<br> Thuật toán tìm kiếm nhị phân(hay Sắp xếp kiểu chèn nhị phân) là một thuật toán dùng để tìm kiếm phần tử trong một danh sách đã được sắp xếp. Thuật toán hoạt động như sau. Trong mỗi bước, so sánh phần tử cần tìm với phần tử nằm ở chính giữa danh sách. Nếu hai phần tử bằng nhau thì phép tìm kiếm thành công và thuật toán kết thúc. Nếu chúng không bằng nhau thì tùy vào phần tử nào lớn hơn, thuật toán lặp lại bước so sánh trên với nửa đầu hoặc nửa sau của danh sách. Vì số lượng phần tử trong danh sách cần xem xét giảm đi một nửa sau mỗi bước, nên thời gian thực thi của thuật toán là hàm lôgarit.. </br>"
                                         "<br></br>"
                                         "<center><br>...........</br></center>"
                                         "<br></br>"
                                         "<b>Đọc thêm tại:</b>  <a href='https://vi.wikipedia.org/wiki/Tìm_kiếm_nhị_phân'>https://vi.wikipedia.org/wiki/Tìm_kiếm_nhị_phân</a>"
                                         "<br></br>"
                                         "<br><b><center>Đây là mã giả của thuật toán</center></b></br>"
                                         "<br></br>"
                                         "<br><b>procedure</b> <i>insertion short</i> (a<sub>1</sub>, a<sub>2</sub>, ...,a<sub>n</sub>: các số thực n≥2)</br>"
                                         "<br><b>for</b>(j:=2 <b>to</b> n</br>"
                                         "<br><b>begin</b></br>"
                                         "<br>   i:=1</br>"
                                         "<br><b>while</b> a<sub>j</sub> > a<sub>i</sub></br>"
                                         "<br> i++</br>"
                                         "<br> m=a<sub>j</sub></br>"
                                         "<br><b>for</b> k:=0 <b>to</b> j-i-1</br>"
                                         "<br> a<sub>i-k</sub> = a<sub>j-k-1</sub></br>"
                                         "<br>a<sub>i</sub>:=m</br>"
                                         "<br><b>end</b>(a<sub>1</sub>, a<sub>2</sub>, ...,a<sub>n</sub> các số đã được sắp)</br>"
                                         "<br></br>"
                                         "<br></br>"


                                         )

                       );
    ui->label->setAutoFillBackground(true);
    ui->label_2->setAutoFillBackground(true);
    ui->pushButton->setAutoFillBackground(true);
    ui->pushButton_2->setAutoFillBackground(true);
    ui->pushButton_3->setAutoFillBackground(true);
    ui->textBrowser1->setAutoFillBackground(true);
    ui->textBrowser1_2->setAutoFillBackground(true);
    setWindowTitle(QString::fromUtf8("Bài tập lập trình môn toán rời rạc! by Hieukoy vs Tranharo"));
    QMovie *movie = new QMovie("tuyetroi.gif");
    ui->label_3->setMovie(movie);
    movie->start();
    ui->pushButton_2->hide();
    ui->textBrowser1->hide();
    ui->textBrowser1_2->hide();
    ui->label->hide();
    ui->label_2->hide();
}

Bai1::~Bai1()
{
    delete ui;
}
QList <int> lt;
void Bai1::on_pushButton_clicked()
{
    int n=getInputValue(QString::fromUtf8("Nhập số phần tử của dãy"));
    if(n<=2)
        QMessageBox::critical(this,QString::fromUtf8("Lỗi"),QString::fromUtf8("Xin nhập n>=2!"),QMessageBox::Ok);
    else
        for(int i=0;i<n;i++)
        {   QString xau=QString::number(i+1);
            int sotudo=getInputValue(QString::fromUtf8("Nhập phần tử thứ %1").arg(xau));
            if(sotudo==-1)
            {   if(QMessageBox::question(this,QString::fromUtf8("Bạn có muốn nhập lại?"),QString::fromUtf8("Bạn vừa hủy bỏ, bạn có muốn tiếp tục nhập không?"))==QMessageBox::Ok)
                sotudo=getInputValue(QString::fromUtf8("Nhập phần tử thứ %1").arg(xau));
                else
                    break;
            }
            else
            {
                int dem=0;
                for(int i=0;i<lt.size();i++)
                    if(sotudo==lt.at(i))
                        dem++;
            if(dem==0)
            lt<<sotudo;
            }
        }
    QString str=getText(lt);
    ui->textBrowser1->setText(str);
    ui->textBrowser1->show();
    ui->label->show();
    ui->pushButton_2->show();
        for(int i=0;i<lt.size();i++)
            qDebug()<<lt.at(i);
}
int Bai1::getInputValue(QString name)
{
    bool ok=false;
        QString s=QString::fromUtf8("Xin nhập...");
        int value = QInputDialog::getInt(this, tr("%1").arg(s),name, 2,-9999999,9999999,1,&ok);
        if(ok)
            return value;
        else
            return -1;
}
void Bai1::thuatToanSapXep(QList<int> &a)
{
    for(int j=1;j<a.size();j++)
    {
        int i=0;
        while(a.at(j)>a.at(i))
            i++;
        int m=a.at(j);
        for(int k=0;k<j-i;k++)
            a.replace(j-k,a.at(j-k-1));
        a.replace(i,m);
    }

}

void Bai1::on_pushButton_2_clicked()
{   QString xau1=getText(lt);
    ui->textBrowser1->setText(xau1);
    //ui->textBrowser1->setHtml();
    thuatToanSapXep(lt);
    QString xau2=getText(lt);
    ui->textBrowser1_2->setText(xau2);
    ui->textBrowser1_2->show();
    ui->label_2->show();
    lt.clear();
}
QString Bai1::getText(QList<int> a)
{
    QString str;
    for(int i=0;i<a.size();i++)
    {
        str.append(QString::number(a.at(i)));
        str.append(" ");
    }
    str=QString::fromUtf8("<center><font size=\"16\">%1</font></center>").arg(str);
    return str;
}

void Bai1::on_pushButton_3_clicked()
{
    this->close();
}

void Bai1::dung()
{
    int n=getInputValue(QString::fromUtf8("Nhập số phần tử của dãy"));
    if(n<=2)
        QMessageBox::critical(this,QString::fromUtf8("Lỗi"),QString::fromUtf8("Xin nhập n>=2!"),QMessageBox::Ok);
    else
        for(int i=0;i<n;i++)
        {   QString xau=QString::number(i+1);
            int sotudo=getInputValue(QString::fromUtf8("Nhập phần tử thứ %1").arg(xau));
            if(sotudo==-1)
            {   if(QMessageBox::question(this,QString::fromUtf8("Bạn có muốn nhập lại?"),QString::fromUtf8("Bạn vừa hủy bỏ, bạn có muốn tiếp tục nhập không?"))==QMessageBox::Ok)
                sotudo=getInputValue(QString::fromUtf8("Nhập phần tử thứ %1").arg(xau));
                else
                    break;
            }
            else
            {
                int dem=0;
                for(int i=0;i<lt.size();i++)
                    if(sotudo==lt.at(i))
                        dem++;
            if(dem==0)
            lt<<sotudo;
            }
        }
    QString str=getText(lt);
    ui->textBrowser1->setText(str);
    ui->textBrowser1->show();
    ui->label->show();
    ui->pushButton_2->show();
}

void Bai1::on_pushButton_4_clicked()
{
    ui->textBrowser1->setText("");
    ui->textBrowser1_2->setText("");
    dung();
}
