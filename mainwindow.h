#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButtonOne_clicked();

    void on_pBtnOne_clicked(bool checked);

    void on_pBtnOne_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
