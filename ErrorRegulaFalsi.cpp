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
      c=b-((f(b)*(a-b))/(f(a)-f(b)));
      
      if(std::fabs(f(c))<=eps)
	{
	  break;
	}
      
      if(f(c)*f(b)<0)
	{
	  std::cout<<ii<<'\t'<<std::fabs((c-a)/c)*100<<std::endl; //OJO, si se pone primero a=c, da 0 por como esta el error
	  a=c;
	}
      else
	{
	  std::cout<<ii<<'\t'<<std::fabs((c-b)/c)*100<<std::endl;
	  b=c;
	}
    }

  return 0;
}
	 
