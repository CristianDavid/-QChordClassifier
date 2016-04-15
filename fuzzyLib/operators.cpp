#include <algorithm>

namespace zadeh {
double conjuncion(double a, double b) {
   return std::min(a, b);
}

double disyuncion(double a, double b) {
   return std::max(a, b);
}

double complemento(double a) {
   return 1 - a;
}

double implicacion(double x, double y) {
   return disyuncion(conjuncion(x, y), complemento(x));
}
}

namespace mandani {
double implicacion(double x, double y) {
   return std::min(x, y);
}
}

namespace godel {
double implicacion(double a, double b) {
   return a < b? 1.0 : b;
}
}
   
double conjuncion(double a, double b) { // And multiplicativo
   return a * b;
}

double disyuncion(double a, double b) {
   return a + b - a*b;
}
