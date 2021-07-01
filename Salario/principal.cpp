#include "principal.h"
#include "ui_principal.h"

#include <QtDebug>
#include <QMessageBox>

Principal::Principal(QWidget *parent)//Clase Principal
    : QMainWindow(parent)
    , ui(new Ui::Principal)
{
    ui->setupUi(this);
}

Principal::~Principal()//Destructor de la clase main
{
    delete ui;
}


void Principal::on_actionSalir_triggered()//Si la accion salir es aplastada, cierra la ventana
{
    this->close();
}

void Principal::on_cmdCalcular_clicked()//Si el boton calcular es presionado, ejecuta calcular
{
    this->calcular();
}

void Principal::on_actionCalcular_triggered()//Si la accion personal es aplastada, ejecuta calcular
{
    this->calcular();
}

void Principal::calcular()//Declaracion del metodo calcular
{
    // Obtener el nombre
    QString nombre = ui->inNombre->text();
    // Valida que el nombre no esté vacío
    if (nombre.isEmpty()){
        QMessageBox::warning(this, "Salarios","Falta nombre del trabajador");
        return;
    }
    // Obtiene horas
    int horas = ui->inHoras->value();
    // Obtiene la jornada
    char jornada ='\0';
    if (ui->inMatutina->isChecked()) {
        jornada = 'M';
    }else if (ui->inNocturna->isChecked()){
        jornada = 'N';
    }else if (ui->inVespertina->isChecked()){
        jornada = 'V';
    }
    // Instancia el objeto y se calcula
    CalculoSalario *s1 = new CalculoSalario(nombre, horas, jornada);
    s1->calcular();
    // Muestra los resultados
    ui->outResultado->appendPlainText(s1->resultado());
    // Encerar los widgets
    this->borrar();
}

void Principal::borrar()
{
    ui->inNombre->setText("");
    ui->inHoras->setValue(0);
    ui->inMatutina->setChecked(true);
    ui->inNombre->setFocus();
}

void Principal::nuevo()//Para hacer un nuevo calculo
{
    ui->outResultado->clear();
}

void Principal::on_actionNuevo_triggered()//Cuando se aplasta el boton Nuevo
{
    this->nuevo();
}

void Principal::on_actionAcerca_de_triggered()//Cuando se aplasta el boton Acerca de
{
    Acerca *acercaDe = new Acerca(this);
    acercaDe->setVersion(VERSION);
    acercaDe->show();
}

void Principal::on_actionGuardar_triggered() //Cuando se aplasta el boton Guardar
{
    QDir directorio=QDir::home();
    QString pathArchivo=directorio.absolutePath()+"  sin_nombre.txt";
    QString fileName = QFileDialog::getSaveFileName(this,"Guardar Archivo",
                pathArchivo,
         "Archivo de texto(*.txt)");

    QFile f(fileName);
    QTextStream out(&f);
    if(!f.open(QIODevice::WriteOnly | QIODevice::Append)){
        //Manda ese mensaje de error si no se abre el archivo
        QMessageBox::warning(this,"Salarios","No se puede abrir el archivo"+fileName);
        return;
    }
    out<<ui->outResultado->toPlainText()<<endl;
    f.close();//Cierra el fichero de texto

}

void Principal::on_actionAbrir_triggered()//Cuando se aplasta el boton de Abrir
{
    QString fileName = QFileDialog::getOpenFileName(this, "Abrir archivo",
                                                     "c:/", "config(*.txt)");
       QFile f(fileName);

       if (!f.open(QIODevice::ReadOnly | QIODevice::Text))
           return;

       QStringList datos;
       QTextStream in(&f);
       while (!in.atEnd()) {
           QString linea = in.readLine();
           datos << linea;
       }
       datos.size();
       datos.length();

   for(int i=0; i < datos.size(); i++){
       ui->outResultado->appendPlainText(datos[i]);
       }

       f.close();
}

