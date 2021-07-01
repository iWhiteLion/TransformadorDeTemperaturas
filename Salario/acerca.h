#ifndef ACERCA_H
#define ACERCA_H

#include <QDialog>

namespace Ui {
class Acerca;
}

class Acerca : public QDialog
{
    Q_OBJECT

public:
    explicit Acerca(QWidget *parent = nullptr);
    ~Acerca();//Destructor

    void setVersion(const QString &value);

private slots:

    void on_Ok_clicked();

private:
    Ui::Acerca *ui;//Creando la interfaz
    QString version;//String de la Version
};

#endif // ACERCA_H
