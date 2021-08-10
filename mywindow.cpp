#include "mywindow.h"

MyWindow::MyWindow(QWidget *parent)
    : QDialog(parent)
{
    editLineOne = new QLineEdit;
    editLineTwo = new QLineEdit;

    buttonOne = new QPushButton("Set 5");
    buttonTwo = new QPushButton("Set 10");
    buttonClear = new QPushButton("Erase lines");
    buttonRand = new QPushButton("Random value");

    checkBoxOne = new QCheckBox("Unabled first button");
    checkBoxOne->setChecked(true);
    checkBoxTwo = new QCheckBox("Unabled second line");
    checkBoxTwo->setChecked(true);

    slider = new QSlider;
    slider->setMaximum(100);
    spinBox = new QSpinBox;
    spinBox->setMaximum(100);

    QHBoxLayout *firstHlayout = new QHBoxLayout;
    firstHlayout->addWidget(buttonOne);
    firstHlayout->addWidget(editLineOne);
    firstHlayout->addWidget(checkBoxOne);

    QHBoxLayout *secondHlayout = new QHBoxLayout;
    secondHlayout->addWidget(buttonTwo);
    secondHlayout->addWidget(editLineTwo);
    secondHlayout->addWidget(checkBoxTwo);

    QHBoxLayout *thirdHlayout = new QHBoxLayout;
    thirdHlayout->addWidget(buttonRand);
    thirdHlayout->addWidget(spinBox);
    thirdHlayout->addWidget(slider);


    QVBoxLayout *mainVlayout = new QVBoxLayout;
    mainVlayout->addLayout(firstHlayout);
    mainVlayout->addLayout(secondHlayout);
    mainVlayout->addLayout(thirdHlayout);
    mainVlayout->addWidget(buttonClear);

    connect(buttonOne, SIGNAL(clicked()), this, SLOT(setValueLineOne()));
    connect(buttonTwo, SIGNAL(clicked()), this,SLOT(setValueLineTwo()));
    connect(buttonRand, SIGNAL(clicked()), this, SLOT(setRandValue()));
    connect(buttonClear, SIGNAL(clicked()), this, SLOT(clearLines()));

    connect(checkBoxOne, SIGNAL(stateChanged(int)), this, SLOT(StateBtnOne(int)));
    connect(checkBoxTwo, SIGNAL(stateChanged(int)), this, SLOT(StateLineTwo(int)));

    connect(slider,SIGNAL(valueChanged(int)), spinBox,SLOT(setValue(int)));
    connect(spinBox,SIGNAL(valueChanged(int)), slider,SLOT(setValue(int)));

    setLayout(mainVlayout);

}

void MyWindow::setValueLineOne()
{
    editLineOne->setText("5");
}

void MyWindow::setValueLineTwo()
{
    editLineTwo->setText("10");
}

void MyWindow::StateBtnOne(const int state)
{
    buttonOne->setEnabled(state);
    if(!state)
    {
        editLineOne->clear();
    }
}

void MyWindow::StateLineTwo(const int state)
{
    editLineTwo->setEnabled(state);
    if(!state)
    {
        editLineTwo->clear();
    }

}

void MyWindow::setRandValue()
{
    spinBox->setValue(rand() % 100);
}

void MyWindow::clearLines()
{
    editLineOne->clear();
    editLineTwo->clear();
    spinBox->setValue(0);
    slider->setValue(0);
}

MyWindow::~MyWindow()
{
}
