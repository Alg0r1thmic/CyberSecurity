#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "md5.h"
#include "sha1.h"
#include "sha256.h"
#include "sha512.h"
#include <string>
#include <vector>
#include <qdebug.h>
#include "ripemd.h"
using namespace std;
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


void MainWindow::on_pushButton_clicked()
{
    QString str;
    str=ui->textEdit->toPlainText();

    string input;
    input=str.toStdString();

    string result=md5(input);

    QString resultshow=QString::fromStdString(result);
    ui->textEdit_2->setText(resultshow);
}


void MainWindow::on_pushButton_2_clicked()
{
    QString str;
    str=ui->textEdit_3->toPlainText();

    string input;
    input=str.toStdString();

    string result=sha1(input);

    QString resultshow=QString::fromStdString(result);
    ui->textEdit_4->setText(resultshow);
}

void MainWindow::on_pushButton_3_clicked()
{
    QString str;
    str=ui->textEdit_5->toPlainText();

    string input;
    input=str.toStdString();

    string result=sha256(input);

    QString resultshow=QString::fromStdString(result);
    ui->textEdit_6->setText(resultshow);

}

void MainWindow::on_pushButton_4_clicked()
{
    QString str;
    str=ui->textEdit_7->toPlainText();

    string input;
    input=str.toStdString();

    string result=sha512(input);

    QString resultshow=QString::fromStdString(result);
    ui->textEdit_8->setText(resultshow);

}

void MainWindow::on_pushButton_5_clicked()
{
    QString str;
    str=ui->textEdit_9->toPlainText();

    string input;
    input=str.toStdString();

    vector<unsigned char> text;
    for (int i = 0; i < input.length(); ++i) {
        text.push_back(input[i]);
    }

    string result=getHash(text);

    QString resultShow=QString::fromStdString(result);
    ui->textEdit_10->setText(resultShow);
}
