#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QObject>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //сделать чтение из файла
    model = new TaskModel(this);
    ui->tableView->setModel(model);
    ui->tableView->setSortingEnabled(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{

    model->insertRow(model->tasks.count());
}

