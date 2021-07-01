#ifndef TERMOMETRO_H
#define TERMOMETRO_H

#include <QMainWindow>
//Termometro.h
QT_BEGIN_NAMESPACE
namespace Ui { class Termometro; }
QT_END_NAMESPACE

class Termometro : public QMainWindow
{
    Q_OBJECT

public:
    Termometro(QWidget *parent = nullptr);
    ~Termometro();
//slots para conversion de temperaturas
public slots:
    void cent2fahr(int);
    void cent2kel(int);
    void fahr2cent(int);
    void fahr2kel(int);
    void kel2cent(int);
    void kel2fahr(int);

private:
    Ui::Termometro *ui;
};
#endif // TERMOMETRO_H
