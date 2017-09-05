#include <iostream>
#include <cmath>

double f(double x) //Una funcion f en terminos de x, los cuales pueden tener valor reales.
{
  return ((std::cos(x))-(x*(std::exp(-x)))); 
}

int main(void)
{
  std::cout.precision(16); //Aumenta la precision
  std::cout.setf(std::ios::scientific); //Escribe todo en forma cientifica
  int NMAX=50; //numero de iteraciones maximo
  double a=1.0, b=3.0, c=0.0; // En a la funcion es positiva, en b es negativa
  const double eps=1.0e-10; //epsilon tolerancia

  for(int ii=1; ii<=NMAX; ii++)
    {
      c=0.5*(a+b);
      if(std::fabs(f(c))<=eps)
	{
	  break; //Si tiene a c dentro de la tolerancia, pare y tomemos a c como raiz
	}
      
      if(f(c)*f(b)<0)
	{
	  std::cout<<ii<<'\t'<<std::fabs((c-a)/c)*100<<std::endl; //En este caso c es la nueva aproximacion y a la anterior
	  a=c; //Es bajar f(a) hasta que de muy cercano a 0
	}
      else
	{
	  std::cout<<ii<<'\t'<<std::fabs((c-b)/c)*100<<std::endl;  //En este caso c es la nueva aproximacion y b la anterior
	  b=c; //Es subir f(b) hasta que de muy cercano a 0
	}
    }
  return 0;
}
