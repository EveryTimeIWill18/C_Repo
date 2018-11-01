#include <iostream>
#include <cmath>
#include <cstdlib>
#include <cstdio>
#include <cassert>
#include "c_matrix_preproc.hpp"

// function prototype
typedef double ** (*__init__)(double **, const int, const int);

double **mat_init_(double **ptr, const int rows, const int cols);

double** do_operation(__init__ init_mtx, double **mtxPtr, const int rows, const int cols);


int main(int argc, char **argv){

    // command line arguments
    argc = atoi(argv[0]);
    // initiialize test matrix
    int rows = atoi(argv[1]);
    int cols = atoi(argv[2]);

    // pointer to pointer to double
    double **ptr;

    // create a matrix
    double **A = do_operation(mat_init_, ptr, rows, cols);

	return EXIT_SUCCESS;
}


double **mat_init_(double **ptr, const int rows, const int cols){
    
    // make sure rows/cols > 0
    assert(rows > 0);
    assert(cols > 0);

    // allocate memory
    ptr = (double **)malloc(sizeof(double *)*rows);   

    // for each row allocate memory
    int i = 0;
    while(i < rows){
        ptr[i] = (double *)malloc(sizeof(double)*cols);
        i += 1;
        printf("row[%d] = %d\n", i, i);
    }
    return ptr;
}

double** do_operation(__init__ init_mtx, double **mtxPtr, 
            const int rows, const int cols){
            
        return init_mtx(mtxPtr, rows, cols);
}
