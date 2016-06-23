#ifndef BAI2_H
#define BAI2_H

#include <QDialog>

namespace Ui {
class Bai2;
}

class Bai2 : public QDialog
{
    Q_OBJECT

public:
    explicit Bai2(QWidget *parent = 0);
    ~Bai2();

    int getInputValue(QString name);
    int thuatToanEuclid(int a, int b);


private slots:
    void dung();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Bai2 *ui;

};

#endif // BAI2_H
