#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "fileitem.h"

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
    void on_scanDirButton_clicked();

private:
	Ui::MainWindow *ui;
	void ScanProgress(FileItem* fileitem);
};

#endif // MAINWINDOW_H
