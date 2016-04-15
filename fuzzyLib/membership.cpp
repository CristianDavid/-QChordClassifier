#include <cmath>
#include "membership.h"

#define PI 3.14159265358979323846F

using std::cos;

namespace membership {

double gamma(double u, double alpha, double beta) {
   if (u < alpha)     return 0.0;
   else if (u > beta) return 1.0;
   else               return (u-alpha) / (beta-alpha);
}

double L(double u, double alpha, double beta) {
   if (u < alpha)     return 1.0;
   else if (u > beta) return 0.0;
   else               return (beta-u) / (beta-alpha);
}

double lambda(double u, double alpha, double beta, double gamma) {
   if      (u < alpha)  return 0.0;
   else if (u <= beta)  return (u-alpha) / (beta-alpha);
   else if (u <= gamma) return (gamma-u) / (gamma-beta);
   else                 return 0.0;
}

double pi(double u, double alpha, double beta, double gamma, double delta) {
   if (u < alpha)       return 0.0;
   else if (u < beta)   return (u-alpha) / (beta-alpha);
   else if (u <= gamma) return 1.0;
   else if (u <= delta) return (delta-u) / (delta-gamma);
   else                 return 0.0;
}
   
double S(double u, double alpha, double beta) {
   if (u < alpha)      return 0.0;
   else if (u <= beta) return 0.5 * (1 + cos((u-beta) / (beta-alpha) * PI));     
   else                return 1.0;
}

double Z(double u, double alpha, double beta) {
   if (u < alpha)      return 1.0;
   else if (u <= beta) return 0.5 * (1 + cos((u-alpha) / (beta-alpha) * PI));
   else                return 0.0;
}

double softLambda(double u, double alpha, double beta, double gamma) {
   if (u < alpha)       return 0.0;
   else if (u <= beta)  return 0.5 * (1 + cos((u-beta) / (beta-alpha) * PI));
   else if (u <= gamma) return 0.5 * (1 + cos((u-beta) / (gamma-beta) * PI));
   else                 return 0.0;
}

double softPi(double u, double alpha, double beta, double gamma, double delta) {
   if (u < alpha)       return 0.0;
   else if (u <= beta)  return 0.5 * (1 + cos((u-beta) / (beta-alpha) * PI));
   else if (u <= gamma) return 1.0;
   else if (u <= delta) return 0.5 * (1 + cos((u-gamma) / (delta-gamma) * PI));
   else                 return 0.0;
}

}
