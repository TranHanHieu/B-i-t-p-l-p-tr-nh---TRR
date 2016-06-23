#ifndef BAI1_H
#define BAI1_H

#include <QDialog>
#include<QList>

namespace Ui {
class Bai1;
}

class Bai1 : public QDialog
{
    Q_OBJECT

public:
    explicit Bai1(QWidget *parent = 0);
    ~Bai1();
    int getInputValue(QString name);
    void thuatToanSapXep(QList<int> &a);
    QString getText(QList <int> a);

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void dung();

private:
    Ui::Bai1 *ui;
};

#endif // BAI1_H
