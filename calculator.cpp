#include "calculator.h"
#include "ui_calculator.h"

double calcVal = 0.0;
bool divTrigger = false;
bool multTrigger = false;
bool addTrigger = false;
bool subTrigger = false;

Calculator::Calculator(QWidget *parent)
    : QMainWindow(parent),
      ui(new Ui::Calculator)
{
    ui->setupUi(this);

    ui->Display->setText(QString::number(calcVal));
    QPushButton *numButtons[10];
    for(size_t i=0; i<10; i++)
    {
        QString btnName = "Button" + QString::number(i);
        numButtons[i] = Calculator::findChild<QPushButton *>(btnName);
        connect(numButtons[i], SIGNAL(released()), this,
                                      SLOT(NumPressed()));
    }
    connect(ui->ButtonAdd, SIGNAL(released()), this, SLOT(MathButtonPressed()));
    connect(ui->ButtonSubtract, SIGNAL(released()), this, SLOT(MathButtonPressed()));
    connect(ui->ButtonMultiply, SIGNAL(released()), this, SLOT(MathButtonPressed()));
    connect(ui->ButtonDivide, SIGNAL(released()), this, SLOT(MathButtonPressed()));

    connect(ui->ButtonResult, SIGNAL(released()), this, SLOT(EqualButtonPressed()));

    connect(ui->ButtonChangeSign, SIGNAL(released()), this, SLOT(ChangeSignButtonPressed()));
}

Calculator::~Calculator()
{
    delete ui;
}

void Calculator::NumPressed()
{
    QPushButton *button = (QPushButton *)sender();
    QString butVal = button->text();
    QString displayVal = ui->Display->text();
    if(displayVal.toDouble() == 0 || displayVal.toDouble() == 0.0)
    {
        ui->Display->setText(butVal);
    }
    else
    {
        QString newVal = displayVal + butVal;
        double dbNewVal = newVal.toDouble();
        ui->Display->setText(QString::number(dbNewVal, 'g', 16));
    }
}

void Calculator::MathButtonPressed()
{
    divTrigger = false;
    multTrigger = false;
    addTrigger = false;
    subTrigger = false;
    QString displayVal = ui->Display->text();
    calcVal = displayVal.toDouble();
    QPushButton *button = (QPushButton *)sender();
    QString btnVal = button->text();
    if(QString::compare(btnVal, "/", Qt::CaseInsensitive) == 0)
    {
        divTrigger = true;
    }
    else if(QString::compare(btnVal, "*", Qt::CaseInsensitive) == 0)
    {
        multTrigger = true;
    }
    else if(QString::compare(btnVal, "+", Qt::CaseInsensitive) == 0)
    {
        addTrigger = true;
    }
    else if(QString::compare(btnVal, "-", Qt::CaseInsensitive) == 0)
    {
        subTrigger = true;
    }
    ui->Display->setText("");
}

void Calculator::EqualButtonPressed()
{
    double solution = 0.0;
    QString displayVal = ui->Display->text();
    double dbDisplayVal = displayVal.toDouble();
    if(addTrigger || subTrigger || multTrigger || divTrigger)
    {
        if(addTrigger)
        {
            solution = calcVal + dbDisplayVal;
        }
        else if(subTrigger)
        {
            solution = calcVal - dbDisplayVal;
        }
        else if(multTrigger)
        {
            solution = calcVal * dbDisplayVal;
        }
        else
        {
            solution = calcVal / dbDisplayVal;
        }
        ui->Display->setText(QString::number(solution));
    }
}

void Calculator::ChangeSignButtonPressed()
{
    QString displayVal = ui->Display->text();
    QRegExp reg("[-]?[0-9.]*");
    if(reg.exactMatch(displayVal))
    {
        double dbDisplayVal = displayVal.toDouble();
        double dbDisplayValSign = -1 * dbDisplayVal;
        ui->Display->setText(QString::number(dbDisplayValSign));
    }

}
