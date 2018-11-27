#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QProcess>
#include <QPlainTextEdit>

MainWindow::MainWindow(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::MainWindow)
{
	ui->setupUi(this);
	ui->pushButton_3->setEnabled(false);
	ui->pushButton_4->setEnabled(false);
}

MainWindow::~MainWindow()
{
	delete ui;
}

void MainWindow::on_pushButton_released()
{
	ui->pushButton_3->setEnabled(true);
	ui->pushButton_4->setEnabled(true);
	process = new QProcess();
	process->start("pkexec /usr/local/bin/gswitch egpu");
	process->waitForReadyRead();
	ui->plainTextEdit->appendPlainText(process->readAllStandardOutput());
}

void MainWindow::on_pushButton_2_released()
{
	ui->pushButton_3->setEnabled(true);
	ui->pushButton_4->setEnabled(true);
	process = new QProcess();
	process->start("pkexec /usr/local/bin/gswitch internal");
	process->waitForReadyRead();
	ui->plainTextEdit->appendPlainText(process->readAllStandardOutput());
}

void MainWindow::on_pushButton_3_released()
{
	process->write("y\n");
	process->waitForFinished();
	ui->plainTextEdit->appendPlainText(process->readAllStandardOutput());
}

void MainWindow::on_pushButton_4_released()
{
	process->write("n\n");
	process->waitForFinished();
	ui->plainTextEdit->appendPlainText(process->readAllStandardOutput());
}

void MainWindow::on_pushButton_5_released()
{
	QApplication::quit();
}
