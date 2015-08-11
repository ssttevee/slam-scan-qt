#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "qfiledialog.h"
#include "fileitem.h"
#include <sstream>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::ScanProgress(FileItem* fileitem)
{
	std::stringstream ss;
	ss << "Size: " << (*fileitem).getSize() << " bytes";
	ui->dirSizeLabel->setText(ss.str().c_str());
}

void MainWindow::on_scanDirButton_clicked()
{
	QString filename = QFileDialog::getOpenFileName(this, "Select directory to scan", "C:/", "*");
	FileItem fi (filename.toStdString().c_str());
	__hook(&FileItem::OnScanComplete, &fi, &MainWindow::ScanProgress);
	fi.scan();
}