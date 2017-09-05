#include <iostream>
#include <cmath>

double f(double x)
{
  return ((std::cos(x))-(x*(std::exp(-x))));
}

double g(double x)
{
  return ((std::cos(x))/(std::exp(-x)));
}

int main(void)
{
  std::cout.precision(16);
  std::cout.setf(ios::std::scientific);
  int NMAX=50;
  double a
