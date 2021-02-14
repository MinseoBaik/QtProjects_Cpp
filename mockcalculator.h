#ifndef MOCKCALCULATOR_H
#define MOCKCALCULATOR_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MockCalculator; }
QT_END_NAMESPACE

class MockCalculator : public QMainWindow
{
    Q_OBJECT

public:
    MockCalculator(QWidget *parent = nullptr);
    ~MockCalculator();

private:
    Ui::MockCalculator *ui;
};
#endif // MOCKCALCULATOR_H
