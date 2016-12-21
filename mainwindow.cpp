#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QStandardItem"
#include "QStandardItemModel"
#include <iostream>
QStandardItemModel *model;
QStandardItem *item;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    model = new QStandardItemModel;
    item = new QStandardItem(QString("0"));
    model->setItem(0,0,item);
    item = new QStandardItem(QString("1"));
    model->setItem(0,1,item);
    item = new QStandardItem(QString("2"));
    model->setItem(1,0,item);
    item = new QStandardItem(QString("12123"));
    model->setItem(1,1,item);
    ui->tableView->setModel(model);
    ui->tableView->resizeRowsToContents();
    ui->tableView->resizeColumnsToContents();
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_tableView_clicked(const QModelIndex &index)
{
    int col = index.column(), row = index.row();
    item = new QStandardItem(QString("*"));
    model->setItem(row,col,item);
    ui->tableView->setModel(model);
    std::cout<<index.column()<<std::endl<<"---"<<std::endl;

}
