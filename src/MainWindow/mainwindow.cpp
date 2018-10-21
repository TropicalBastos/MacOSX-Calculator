#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QString>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->addButton = ui->add;
    this->subtractButton = ui->subtract;
    this->multiplyButton = ui->multiply;
    this->divideButton = ui->divide;
    this->display = ui->display;
    this->initEventListeners();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::initEventListeners(){
    connect(this->addButton, SIGNAL(pressed()), this, SLOT(add()));
    connect(this->subtractButton, SIGNAL(pressed()), this, SLOT(subtract()));
    connect(this->multiplyButton, SIGNAL(pressed()), this, SLOT(multiply()));
    connect(this->divideButton, SIGNAL(pressed()), this, SLOT(divide()));
}

void MainWindow::add(){

}

void MainWindow::subtract(){

}

void MainWindow::multiply(){

}

void MainWindow::divide(){

}

double MainWindow::getDisplayNumber(){
    QString text = this->display->text();
    return text.toDouble();
}
