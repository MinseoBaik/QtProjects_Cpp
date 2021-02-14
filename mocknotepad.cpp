#include "mocknotepad.h"
#include "ui_mocknotepad.h"

MockNotepad::MockNotepad(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MockNotepad)
{
    ui->setupUi(this);
    this->setCentralWidget(ui->textEdit);
}

MockNotepad::~MockNotepad()
{
    delete ui;
}


void MockNotepad::on_actionNew_triggered()
{
    currentFile.clear();
    ui->textEdit->setText(QString());
}

void MockNotepad::on_actionOpen_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(this, "Opend the File");
    QFile file(fileName);
    currentFile = fileName;
    if(!file.open(QIODevice::ReadOnly | QFile::Text))
    {
        QMessageBox::warning(this, "Warning", "Cannot open file : " + file.errorString());
        return;
    }
    setWindowTitle(fileName);
    QTextStream in(&file);
    QString text = in.readAll();
    ui->textEdit->setText(text);
    file.close();
}

void MockNotepad::on_actionSave_As_triggered()
{
    QString fileName = QFileDialog::getSaveFileName(this, "Save As");
    QFile file(fileName);
    if(!file.open(QFile::WriteOnly | QFile::Text))
    {
        QMessageBox::warning(this, "Warning", "Cannot save file : " + file.errorString());
        return;
    }
    currentFile = fileName;
    setWindowTitle(fileName);
    QTextStream out(&file);
    QString text = ui->textEdit->toPlainText();
    out << text;
    file.close();
}

void MockNotepad::on_actionPrint_triggered()
{
    QPrinter printer;
    printer.setPrinterName("Printer Name");
    QPrintDialog pDialog(&printer, this);
    if(pDialog.exec() == QDialog::Rejected)
    {
        QMessageBox::warning(this, "Warning", "Cannot Access Printer");
        return;
    }
    ui->textEdit->print(&printer);
}

void MockNotepad::on_actionExit_triggered()
{
    QApplication::quit();
}

void MockNotepad::on_actionCopy_triggered()
{
    ui->textEdit->copy();
}



void MockNotepad::on_actionPaste_triggered()
{
    ui->textEdit->paste();
}

void MockNotepad::on_actionCut_triggered()
{
    ui->textEdit->cut();
}

void MockNotepad::on_actionUndo_triggered()
{
    ui->textEdit->undo();
}

void MockNotepad::on_actionRedo_triggered()
{
    ui->textEdit->redo();
}
