// Es totalmente igual a Biseccion, solo que se diferencia en como se selecciona c
#include <iostream>
#include <cmath>

double f(double x)
{
  return ((std::cos(x))-(x*(std::exp(-x))));
}

int main(void)
{
  std::cout.precision(16);
  std::cout.setf(std::ios::scientific);
  int NMAX=50;
  double a=1.0, b=3.0, c=0.0;
  const double eps=1.0e-10;

  for(int ii=1; ii<=NMAX; ii++)
    {
      c=b-((f(b)*(a-b))/(f(a)-f(b))); //Por como se da el metodo
      
      if(std::fabs(f(c))<=eps)
	{
	  break;
	}

      std::cout<<ii<<'\t'
	       <<a<<'\t'
	       <<b<<'\t'
	       <<c<<'\t'
	       <<f(c)<<std::endl;
      if(f(c)*f(b)<0)
	{
	  a=c;
	}
      else
	{
	  b=c;
	}
    }
  std::cout<<c<<std::endl;
  return 0;
}
	 
