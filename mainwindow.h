#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QProcess>

namespace Ui {
	class MainWindow;
}

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	explicit MainWindow(QWidget *parent = 0);
	~MainWindow();

private slots:
	void on_pushButton_released();
	void on_pushButton_2_released();
	void on_pushButton_3_released();
	void on_pushButton_4_released();
	void on_pushButton_5_released();

private:
	Ui::MainWindow *ui;
	QProcess *process;
};

#endif // MAINWINDOW_H
