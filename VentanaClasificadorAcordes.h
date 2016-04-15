#ifndef VENTANACLASIFICADORACORDES_H
#define VENTANACLASIFICADORACORDES_H

#include "TemperamentoIgual.h"
#include <QMainWindow>
#include <QComboBox>
#include <QDoubleSpinBox>

namespace Ui {
class VentanaClasificadorAcordes;
}

class VentanaClasificadorAcordes : public QMainWindow
{
   Q_OBJECT

public:
   explicit VentanaClasificadorAcordes(QWidget *parent = 0);
   ~VentanaClasificadorAcordes();

   void determinaAcorde();

private slots:
   void on_nota1Spin_valueChanged(double arg1);

   void on_nota2Spin_valueChanged(double arg1);

   void on_nota3Spin_valueChanged(double arg1);

   void on_nota1Combo_currentIndexChanged(int index);

   void on_nota2Combo_currentIndexChanged(int index);

   void on_nota3Combo_currentIndexChanged(int index);

private:
   void frequencyChanged(QComboBox *box, double freq);
   void noteChanged(QDoubleSpinBox *spin, int nota);
   Ui::VentanaClasificadorAcordes *ui;
   TemperamentoIgual eqTemp;
   InfoNota infoNotas[3];
};

#endif // VENTANACLASIFICADORACORDES_H
