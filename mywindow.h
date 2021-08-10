#ifndef MYWINDOW_H
#define MYWINDOW_H

#include <QDialog>
#include <QPushButton>
#include <QSpinBox>
#include <QSlider>
#include <QTextEdit>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLineEdit>
#include <QCheckBox>

class MyWindow : public QDialog
{
    Q_OBJECT

public:
    explicit MyWindow(QWidget *parent = nullptr);
    ~MyWindow();
private:
    QCheckBox *checkBoxOne;
    QCheckBox *checkBoxTwo;
    QLineEdit *editLineOne;
    QLineEdit *editLineTwo;
    QPushButton *buttonOne;
    QPushButton *buttonTwo;
    QPushButton *buttonClear;
    QPushButton *buttonRand;
    QSpinBox *spinBox;
    QSlider *slider;
private slots:
    void setValueLineOne();
    void setValueLineTwo();
    void StateBtnOne(const int state);
    void StateLineTwo(const int state);
    void setRandValue();
    void clearLines();




};
#endif // MYWINDOW_H
