#ifndef ZADEH_H_INCLUDED
#define ZADEH_H_INCLUDED

namespace zadeh {

double conjuncion(double a, double b);
double disyuncion(double a, double b);
double complemento(double a, double b);
double implicacion(double a, double b);

}

namespace mandani {
   double implicacion(double a, double b);
}

namespace godel {
   double implicacion(double a, double b);
}

#endif // ZADEH_H_INCLUDED
