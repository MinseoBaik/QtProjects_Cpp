#include "mockcalculator.h"
#include "ui_mockcalculator.h"

MockCalculator::MockCalculator(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MockCalculator)
{
    ui->setupUi(this);
}

MockCalculator::~MockCalculator()
{
    delete ui;
}

