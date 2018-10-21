#include <iostream>
#include <cmath>
#include <cstdlib>

// TODO: Finsih Functions

typedef bool (*computeFunction)(const double, const double, const int,
                                  double &, int &);


// function prototypes
bool bisecSin(const double a, const double b, const int maxit, double &root,
              int &iters);
bool bisecQuadratic(const double a, const double b, const int maxit,
                    double &root, int &iters);

// function computation
bool selectFunction(computeFunction func, const double a, const double b,
                      int maxit, double &root, int &iters){

                return func(a, b, maxit, root, iters);
}

int main(int argc, char* argv[]){
    double a, b, root;
    int maxit, iters;
    int func_choice;

    func_choice = atoi(*(argv));
    a           = atof(*(argv+1));
    b           = atof(*(argv+2));

    
    if(func_choice == 1){
        bool sin_func = selectFunction(bisecSin, a, b, maxit, 
                                        root, iters);
    }
    if(func_choice == 2){
        bool quad_func = selectFunction(bisecQuadratic, a, b, maxit, 
                                         root, iters);
    }
    if(func_choice > 2){
        
    }
    
    
    // call functions

    // do nice terminal outputs


  return 0;
}

// implementation fo the two functions
