#ifndef TEMPERAMENTO_IGUAL_H
#define TEMPERAMENTO_IGUAL_H

#include <string>

enum Notas {
   DO = 0, DO_SHARP, RE, RE_SHARP, MI, FA, FA_SHARP,
   SOL, SOL_SHARP, LA, LA_SHARP, SI
};

struct InfoNota {
   int note;
   double membership;
};

class TemperamentoIgual {
 public:
   TemperamentoIgual(int base = Notas::LA, double freq = 440.00);
   InfoNota getNota(double freq);
   double getFreq(int nota);
   std::string getAcorde(int nota1, int nota2, int nota3);
   double getCertezaAcorde(double mem1, double mem2, double mem3);
 private:
   inline double &frequencyAt(int octave, int note);
   double calculateFrequency(int n);
   const int base;
   const double freq;
   double frequencies[9*12];
};

#endif // TEMPERAMENTO_IGUAL_H
