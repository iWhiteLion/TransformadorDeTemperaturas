#include "acerca.h"
#include "ui_acerca.h"

Acerca::Acerca(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Acerca)
{
    ui->setupUi(this);
}

Acerca::~Acerca()
{
    delete ui;
}

void Acerca::setVersion(const QString &value)
{
    version = value;
    ui->outVersion->setText(" VERSION "+value);
}

void Acerca::on_Ok_clicked()//Si el boton es clickado, cierra la ventana de informacion
{
    this->close();//Cierra la interfaz
}
