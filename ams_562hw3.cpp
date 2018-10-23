#include <iostream>
#include <cstdlib>
#include <cmath>
#include <cstdio>


typedef bool (*bisection_function)(const double, const double,
                                      const int , double, int);

// prototypes
bool bisecSin(const double a, const double b, const int maxit,
                    double root, int iters);

bool bisecQuadratic(const double a, const double b, const int maxit,
                    double root, int iters);

bool select_function(bisection_function func, const double a,
        const double b, const int maxit, double root, int iters);


int main(int argc, char* argv[]){

  double a, b, root;
  int maxit, iters;
  int function_choice;
  function_choice = atoi(*(argv));
  a = atof(*(argv+1));
  b = atof(*(argv+2));
  maxit = 20;
  iters = 0;
  root = 0;

  std::cout << "a = " << a << "   b = " << b << std::endl;
  bisection_function f;
  std::cout << "Select Function\n----------\n1: bisecSin\n2: bisecQuadratic"
            << std:endl;
  if(function_choice == 1){
    bool sin_func = select_function(bisecSin, a, b,
                             maxit, root, iters);
  }
  if(function_choice == 2){
    bool quad_func = select_function(bisecQuadratic, a, b,
                              maxit, root, iters);
  }



  return 0;
}

bool bisecSin(const double a, const double b, const int maxit,
                    double root, int iters){

            double a_ = a;
            double b_ = b;
            double epsilon = 1e-6;
            while((b_ - a_) > epsilon){
                if(iters >= maxit){
                  std::cout << "minimum not found "
                            << "root = "
                            << root
                            << std::endl;
                    return false;
                }
                double m = a_ + ((b_ - a_)/2.0);
                if((sin(m) >= 0 && sin(a_) >= 0) ||
                   (sin(m) < 0 && sin(a_) < 0)){
                        a_ = m;
                }else{
                    b_ = m;
                }
                root = m;
                iters += 1;
            }
        std::cout << "minimum found"
                  << "\nroot = "
                  << root
                  << std::endl;
        return true;
}

bool bisecQuadratic(const double a, const double b, const int maxit,
                    double &root, int &iters){

          double a_ = a;
          double b_ = b;
          double epsilon = 1e-6;
          while((b_ - a_) > epsilon){
            if(iters >= maxit){
              std::cout << "minimum not found "
                            << "root = "
                            << root
                            << std::endl;
              return false;
            }
            double m = a_ + ((b_ - a_)/2.0);
            if(
                ((m*m - 2) >= 0 && (a_*a_ - 2) >= 0) ||
                ((m*m - 2) < 0 && (a_*a_ - 2))
            ){
              a_ = m;
            }else{
              b_ = m;
            }
            root = m;
            iters += 1;
          }
          std::cout << "minimum found"
                    << "\nroot = "
                    << root
                    << std::endl;
          return true;

}

bool select_function(bisection_function func, const double a,
          const double b, const int maxit, double root, int iters){

          return func(a, b, maxit, root, iters);
}
