#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "qmessagebox.h"
#include <QFileDialog>
#include <QImage>
#include <QBuffer>


QString fileOpen;
QString fileSave;
QImage img;
float valorZoom;


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{

    fileOpen = QFileDialog::getOpenFileName(this,
        tr("Abrir Imagem"));

     img.load(fileOpen);

     img.scaled(100,100,Qt::IgnoreAspectRatio,Qt::SmoothTransformation);

    ui->label->setPixmap((QPixmap::fromImage(img)).scaled(ui->label->geometry().width(),ui->label->geometry().height(),Qt::KeepAspectRatioByExpanding,Qt::SmoothTransformation));





}

void MainWindow::on_horizontalSlider_valueChanged(int value)

{

    valorZoom = value/100.0;



  //  ui->label_3->setText(QString::number(valorZoom));

    ui->label->setPixmap((QPixmap::fromImage(img)).scaled(ui->label->geometry().width()*valorZoom,ui->label->geometry().height()*valorZoom,Qt::KeepAspectRatioByExpanding,Qt::SmoothTransformation));


}


void MainWindow::on_pushButton_2_clicked()
{
    fileSave = QFileDialog::getSaveFileName(this,
        tr("Salvar Imagem"),nullptr,"*.JPG",nullptr);




    QImage imgTmp(img.scaled(ui->label->geometry().width()*valorZoom,ui->label->geometry().height()*valorZoom,Qt::IgnoreAspectRatio,Qt::SmoothTransformation));
    imgTmp.save(fileSave,nullptr,80);
}
