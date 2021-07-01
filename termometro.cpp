#include "termometro.h"
#include "ui_termometro.h"

#include <QDebug>
Termometro::Termometro(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Termometro)
{
    ui->setupUi(this);
//Conexiones para las seniales y slots
    connect(ui->cmdCent, SIGNAL(valueChanged(int)),
            this, SLOT(cent2fahr(int)));

    connect(ui->cmdCent, SIGNAL(valueChanged(int)),
            this, SLOT(cent2kel(int)));

    connect(ui->cmdFahr, SIGNAL(valueChanged(int)),
            this, SLOT(fahr2cent(int)));

    connect(ui->cmdFahr, SIGNAL(valueChanged(int)),
            this, SLOT(fahr2kel(int)));

    connect(ui->cmdKel, SIGNAL(valueChanged(int)),
            this, SLOT(kel2cent(int)));

    connect(ui->cmdKel, SIGNAL(valueChanged(int)),
            this, SLOT(kel2fahr(int)));
}

Termometro::~Termometro()
{
    delete ui;
}

void Termometro::cent2fahr(int valor)
{
    if (ui->cmdCent->hasFocus()){
        float f = valor * 9.0/5 + 32;
        ui->cmdFahr->setValue(f);
    }
}

void Termometro::cent2kel(int valor)
{
    if (ui->cmdCent->hasFocus()){
        float k = valor + 273.15;
        ui->cmdKel->setValue(k);
    }
}

void Termometro::fahr2cent(int valor)
{
    if (ui->cmdFahr->hasFocus()){
        float c = (valor - 32) * 5.0/9;
        ui->cmdCent->setValue(c);
    }
}

void Termometro::fahr2kel(int valor)
{
    if (ui->cmdFahr->hasFocus()){
        float k = (valor - 32) * 5.0/9 + 273.15;
        ui->cmdKel->setValue(k);
    }
}

void Termometro::kel2cent(int valor)
{
    if (ui->cmdKel->hasFocus()){
        float c = valor - 273.15;
        ui->cmdCent->setValue(c);
    }
}

void Termometro::kel2fahr(int valor)
{
    if (ui->cmdKel->hasFocus()){
        float f = (valor - 273.15) * 9/5.0 + 32;
        ui->cmdFahr->setValue(f);
    }
}

