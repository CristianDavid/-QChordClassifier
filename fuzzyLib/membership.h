#ifndef MEMBERSHIP_H_INCLUDED
#define MEMBERSHIP_H_INCLUDED

namespace membership {

double gamma(double u, double alpha, double beta);
double L(double u, double alpha, double beta);
double lambda(double u, double alpha, double beta, double gamma);
double pi(double u, double apha, double beta, double gamma, double delta);
   
double S(double u, double alpha, double beta);
double Z(double u, double alpha, double beta);
double softLambda(double u, double alpha, double beta, double gamma);
double softPi(double u, double apha, double beta, double gamma, double delta);
}

#endif // MEMBERSHIP_H_INCLUDED
