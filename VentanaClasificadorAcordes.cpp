#include "VentanaClasificadorAcordes.h"
#include "ui_VentanaClasificadorAcordes.h"
#include <QTreeWidgetItem>
#include <string>

VentanaClasificadorAcordes::VentanaClasificadorAcordes(QWidget *parent) :
   QMainWindow(parent),
   ui(new Ui::VentanaClasificadorAcordes),
   eqTemp(Notas::LA, 440.00),
   infoNotas {{Notas::LA, 1.0},{Notas::LA,1.0},{Notas::LA,1.0}} {
   ui->setupUi(this);
   determinaAcorde();
}

VentanaClasificadorAcordes::~VentanaClasificadorAcordes() {
   delete ui;
}

void VentanaClasificadorAcordes::determinaAcorde() {
   int nota1 = ui->nota1Combo->currentIndex();
   int nota2 = ui->nota2Combo->currentIndex();
   int nota3 = ui->nota3Combo->currentIndex();
   std::string strAcorde = eqTemp.getAcorde(nota1, nota2, nota3);
   ui->acordeEdit->setText(QString::fromStdString(strAcorde));
   double certeza = eqTemp.getCertezaAcorde(infoNotas[0].membership, infoNotas[1].membership, infoNotas[2].membership);
   ui->statusBar->showMessage("Certeza: " + QString::number(certeza, 'f', 4));
   QTreeWidgetItem *parent = ui->arbolMembresias->topLevelItem(0);
   parent->child(0)->setText(0, QString::number(infoNotas[0].membership, 'f', 4));
   parent->child(1)->setText(0, QString::number(infoNotas[1].membership, 'f', 4));
   parent->child(2)->setText(0, QString::number(infoNotas[2].membership, 'f', 4));
}

void VentanaClasificadorAcordes::on_nota1Spin_valueChanged(double freq) {
   infoNotas[0] = eqTemp.getNota(freq);
   frequencyChanged(ui->nota1Combo, freq);
}

void VentanaClasificadorAcordes::on_nota2Spin_valueChanged(double freq) {
    infoNotas[1] = eqTemp.getNota(freq);
    frequencyChanged(ui->nota2Combo, freq);
}

void VentanaClasificadorAcordes::on_nota3Spin_valueChanged(double freq) {
   infoNotas[2] = eqTemp.getNota(freq);
   frequencyChanged(ui->nota3Combo, freq);
}

void VentanaClasificadorAcordes::on_nota1Combo_currentIndexChanged(int index) {
   infoNotas[0].note = index;
   infoNotas[0].membership = 1.0;
   noteChanged(ui->nota1Spin, index);
}

void VentanaClasificadorAcordes::on_nota2Combo_currentIndexChanged(int index) {
   infoNotas[1].note = index;
   infoNotas[1].membership = 1.0;
   noteChanged(ui->nota2Spin, index);
}

void VentanaClasificadorAcordes::on_nota3Combo_currentIndexChanged(int index) {
   infoNotas[2].note = index;
   infoNotas[2].membership = 1.0;
   noteChanged(ui->nota3Spin, index);
}

void VentanaClasificadorAcordes::frequencyChanged(QComboBox *notaCombo, double freq) {
   int nota = eqTemp.getNota(freq).note;
   notaCombo->blockSignals(true);
   notaCombo->setCurrentIndex(nota);
   determinaAcorde();
   notaCombo->blockSignals(false);
}

void VentanaClasificadorAcordes::noteChanged(QDoubleSpinBox *spin, int nota) {
   double freq = eqTemp.getFreq(nota);
   spin->blockSignals(true);
   spin->setValue(freq);
   determinaAcorde();
   spin->blockSignals(false);
}
