#include "TemperamentoIgual.h"
#include "fuzzyLib/membership.h"
#include "fuzzyLib/operators.h"
#include <cmath>
#include <string>

#define FREQUENCY_POS(octave, note) (octave)*12 + (note)
#define CENTS(n, f) (f) * std::pow(std::pow(2.0, 1/1200.0), (n))

TemperamentoIgual::TemperamentoIgual(int base, double freq)
 : base(base), freq(freq) {
   int basePos = FREQUENCY_POS(4, base);
   for (int i = 0; i < 9*12; i++) {
      frequencies[i] = calculateFrequency(i - basePos);
   }
}

InfoNota TemperamentoIgual::getNota(double freq) {
   double maxMembership = 0.0, temp;
   int i, j;
   for (i = 0; i < 9; i++) {
      for (j = 0; j < 12; j++) {
         double note = frequencyAt(i,j);
         temp = membership::softLambda(freq, CENTS(-55, note), note, CENTS(55, note));
         if (temp < maxMembership) return InfoNota {(j-1+12)%12, maxMembership};
         maxMembership = temp;
      }
   }
   return InfoNota {-1, 0.0};
}

double TemperamentoIgual::getFreq(int nota) {
   return frequencyAt(4, nota);
}

double TemperamentoIgual::getCertezaAcorde(double mem1, double mem2, double mem3) {
   using zadeh::conjuncion;
   return conjuncion(conjuncion(mem1, mem2), mem3);
}

std::string TemperamentoIgual::getAcorde(int nota1, int nota2, int nota3) {
   std::string nombres[12] = {"Do", "Do#", "Re", "Re#", "Mi", "Fa",
                              "Fa#", "Sol", "Sol#", "La", "La#", "Si"};
   enum class Intervalos {
      PRIMERA = 0, SEGUNDA_MENOR, SEGUNDA_MAYOR, TERCERA_MENOR, TERCERA_MAYOR, CUARTA,
      QUINTA_DISMINUIDA, QUINTA, SEXTA_MENOR, SEXTA_MAYOR, SEPTIMA_MENOR, SEPTIMA_MAYOR
   };
   Intervalos n2 = (Intervalos) ((nota2 - nota1 + 12) % 12);
   Intervalos n3 = (Intervalos) ((nota3 - nota1 + 12) % 12);
   switch (n2) {
      case Intervalos::PRIMERA:
         if (n3 == Intervalos::PRIMERA)
            return nombres[nota1] + " Consonante";
         if (n3 == Intervalos::CUARTA)
            return nombres[nota3] + " Quinta";
         if (n3 == Intervalos::QUINTA)
            return nombres[nota1] + " Quinta";
         break;
      case Intervalos::TERCERA_MENOR:
         if (n3 == Intervalos::QUINTA_DISMINUIDA)
            return nombres[nota1] + " Disminuido";
         if (n3 == Intervalos::QUINTA)
            return nombres[nota1] + " Menor";
         if (n3 == Intervalos::SEXTA_MENOR)
            return nombres[nota3] + " Mayor";
         if (n3 == Intervalos::SEXTA_MAYOR)
            return nombres[nota3] + " Disminuido";
         break;
      case Intervalos::TERCERA_MAYOR:
         if (n3 == Intervalos::QUINTA)
            return nombres[nota1] + " Mayor";
         if (n3 == Intervalos::SEXTA_MENOR)
            return nombres[nota1] + " Aumentado";
         if (n3 == Intervalos::SEXTA_MAYOR)
            return nombres[nota3] + " Menor";
         break;
      case Intervalos::CUARTA:
         if (n3 == Intervalos::PRIMERA)
            return nombres[nota2] + " Quinta";
         if (n3 == Intervalos::CUARTA)
            return nombres[nota2] + " Quinta";
         if (n3 == Intervalos::SEXTA_MENOR)
            return nombres[nota2] + " Menor";
         if (n3 == Intervalos::SEXTA_MAYOR)
            return nombres[nota2] + " Mayor";
         break;
      case Intervalos::QUINTA_DISMINUIDA:
         if (n3 == Intervalos::TERCERA_MENOR)
            return nombres[nota1] + " Disminuido";
         if (n3 == Intervalos::SEXTA_MAYOR)
            return nombres[nota2] + " Disminuido";
      case Intervalos::QUINTA:
         if (n3 == Intervalos::PRIMERA)
            return nombres[nota1] + " Quinta";
         if (n3 == Intervalos::TERCERA_MENOR)
            return nombres[nota1] + " Menor";
         if (n3 == Intervalos::TERCERA_MAYOR)
            return nombres[nota1] + " Mayor";
         if (n3 == Intervalos::QUINTA)
            return nombres[nota1] + " Quinta";
         break;
      case Intervalos::SEXTA_MENOR:
         if (n3 == Intervalos::TERCERA_MENOR)
            return nombres[nota2] + " Mayor";
         if (n3 == Intervalos::TERCERA_MAYOR)
            return nombres[nota1] + " Aumentado";
         if (n3 == Intervalos::CUARTA)
            return nombres[nota3] + " Menor";
         break;
      case Intervalos::SEXTA_MAYOR:
         if (n3 == Intervalos::TERCERA_MENOR)
            return nombres[nota2] + " Disminuido";
         if (n3 == Intervalos::TERCERA_MAYOR)
            return nombres[nota2] + " Menor";
         if (n3 == Intervalos::CUARTA)
            return nombres[nota3];
         if (n3 == Intervalos::QUINTA_DISMINUIDA)
            return nombres[nota3];
         break;
      default:
         return "¡Disonante!";
   }
   return "¡Disonante!";
}

double &TemperamentoIgual::frequencyAt(int octave, int note) {
   return frequencies[FREQUENCY_POS(octave, note)];
}

double TemperamentoIgual::calculateFrequency(int n) {
   double a = std::pow(2.0, 1/12.0);
   return freq * std::pow(a, n);
}
