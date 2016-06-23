#ifndef BAI3_H
#define BAI3_H

#include <QDialog>

namespace Ui {
class Bai3;
}

class Bai3 : public QDialog
{
    Q_OBJECT

public:
    explicit Bai3(QWidget *parent = 0);
    ~Bai3();
    QList <int> getNumber(int a);
    QList<int> sapXepSo(QList <int> a);
    int getInputValue(QString name);
    int SinhHoanVi (int a);
private slots:
    void dung();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

private:
    Ui::Bai3 *ui;
};

#endif // BAI3_H
