include <iostream>
#include <cmath>
#include <cstdlib>


// function pointer returns bool
typedef bool (*interval_bisect)(const double, const double,
                    const int, double &, int &);


// prototypes
bool bisecSin(const double a, const double b, const int maxit, double &root,
              int &iters);

bool bisecQuadratic(const double a, const double b, const int maxit,
                    double &root, int &iters);


bool select_function(interval_bisect func, const double a, const double b,
                          const int maxit, double &root, int &iters){

     // returns the selected function with given parameters
     return func(a, b, maxit, root, iters);
}

int main(int argc, char* argv[]){

   double a, b, root;
   int maxit, iters;

   // parse command line inputs
   a = std::atof(argv[1]);
   b = std::atof(argv[2]);
   maxit = std::atoi(argv[3]);
   int func_choice = std::atoi(argv[4]);
   if(func_choice == 1){
      bool func = select_function(bisecSin, a, b, maxit, root, iters);
   }

  return 0;
}

bool bisecSin(const double a, const double b, const int maxit,
               double &root, int &iters){

         double epsilon = 1e-6;
         double a_ = a;
         double b_ = b;
         while((b_ - a_) > epsilon){
            if(iters >= maxit)
               return false;
            double m = a_ + ((b_ - a_)/2.0);
            if((sin(m) >= 0 && sin(a_) >= 0) || (sin(m) < 0 && sin(a_) < 0)){
               a_ = m;
               std::cout << "a := m " << m << std::endl;
            }else{
               b_ = m;
               std::cout << "b := m " << m << std::endl;
            }
            iters += 1;
         }
         return true;
}
