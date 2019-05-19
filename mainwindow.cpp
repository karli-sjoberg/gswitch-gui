#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QProcess>
#include <QPlainTextEdit>

MainWindow::MainWindow(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::MainWindow)
{
	ui->setupUi(this);
    ui->yesButton->setEnabled(false);
    ui->noButton->setEnabled(false);
    ui->lineEdit->setEnabled(false);
    ui->submitButton->setEnabled(false);
}

MainWindow::~MainWindow()
{
	delete ui;
}

void MainWindow::on_egpuButton_released()
{
    ui->yesButton->setEnabled(true);
    ui->noButton->setEnabled(true);
	process = new QProcess();
	process->start("pkexec /usr/bin/gswitch egpu");
	process->waitForReadyRead();
	ui->plainTextEdit->appendPlainText(process->readAllStandardOutput());
}

void MainWindow::on_internalButton_released()
{
    ui->yesButton->setEnabled(true);
    ui->noButton->setEnabled(true);
	process = new QProcess();
	process->start("pkexec /usr/bin/gswitch internal");
	process->waitForReadyRead();
	ui->plainTextEdit->appendPlainText(process->readAllStandardOutput());
}

void MainWindow::on_yesButton_released()
{
	process->write("y\n");
	process->waitForFinished();
	ui->plainTextEdit->appendPlainText(process->readAllStandardOutput());
}

void MainWindow::on_noButton_released()
{
	process->write("n\n");
	process->waitForFinished();
	ui->plainTextEdit->appendPlainText(process->readAllStandardOutput());
}

void MainWindow::on_quitButton_released()
{
	QApplication::quit();
}

void MainWindow::on_setupButton_released()
{
    ui->lineEdit->setEnabled(true);
    ui->submitButton->setEnabled(true);
    process = new QProcess();
    process->start("pkexec /usr/bin/gswitch setup");
    process->waitForReadyRead();
    ui->plainTextEdit->appendPlainText(process->readAllStandardOutput());
    process->waitForReadyRead();
    ui->plainTextEdit->appendPlainText(process->readAllStandardOutput());
}

void MainWindow::on_submitButton_released()
{
    QString lineEditString = ui->lineEdit->text() + "\n";
    ui->lineEdit->clear();
    process->write(lineEditString.toUtf8());
    process->waitForFinished();
    ui->plainTextEdit->appendPlainText(process->readAllStandardOutput());
}
