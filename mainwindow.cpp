#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QProcess>
#include <QPlainTextEdit>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->buttonBox->setEnabled(false);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_released()
{
    ui->buttonBox->setEnabled(true);
    process = new QProcess();
    process->start("pkexec /usr/local/bin/gswitch egpu");
    process->waitForReadyRead();
    ui->plainTextEdit->appendPlainText(process->readAllStandardOutput());
}

void MainWindow::on_pushButton_2_clicked()
{
    ui->buttonBox->setEnabled(true);
    process = new QProcess();
    process->start("pkexec /usr/local/bin/gswitch internal");
    process->waitForReadyRead();
    ui->plainTextEdit->appendPlainText(process->readAllStandardOutput());
}

void MainWindow::on_buttonBox_accepted()
{
    process->write("y\n");
    process->waitForFinished();
    ui->plainTextEdit->appendPlainText(process->readAllStandardOutput());
}

void MainWindow::on_buttonBox_rejected()
{
    process->write("n\n");
    process->waitForFinished();
    ui->plainTextEdit->appendPlainText(process->readAllStandardOutput());
}
