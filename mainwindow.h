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
    void on_egpuButton_released();
    void on_internalButton_released();
    void on_yesButton_released();
    void on_noButton_released();
    void on_quitButton_released();
    void on_setupButton_released();
    void on_submitButton_released();

private:
	Ui::MainWindow *ui;
	QProcess *process;
};

#endif // MAINWINDOW_H
