#ifndef MOCKNOTEPAD_H
#define MOCKNOTEPAD_H

#include <QMainWindow>
#include <QFile>
#include <QFileDialog>
#include <QTextStream>
#include <QMessageBox>
#include <QPrinter>
#include <QPrintDialog>


QT_BEGIN_NAMESPACE
namespace Ui { class MockNotepad; }
QT_END_NAMESPACE

class MockNotepad : public QMainWindow
{
    Q_OBJECT

public:
    MockNotepad(QWidget *parent = nullptr);
    ~MockNotepad();

private slots:
    void on_actionNew_triggered();

    void on_actionOpen_triggered();

    void on_actionSave_As_triggered();

    void on_actionExit_triggered();

    void on_actionPrint_triggered();

    void on_actionCopy_triggered();

    void on_actionPaste_triggered();

    void on_actionCut_triggered();

    void on_actionUndo_triggered();

    void on_actionRedo_triggered();

private:
    Ui::MockNotepad *ui;
    QString currentFile = "";
};
#endif // MOCKNOTEPAD_H
