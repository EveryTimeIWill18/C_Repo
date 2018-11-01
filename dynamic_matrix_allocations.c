#include <iostream>
#include <cmath>
#include <cstdlib>
#include <cstdio>
#include <cassert>
#include <sys/types.h>
#include <sys/types.h>
#include "c_matrix_preproc.hpp"
// always do buffered read/write
// reading/writing in larger chunks is more efficient

// fopen - more efficient/less control
// open  - less efficient/more control


// function prototype
typedef double ** (*__init__)(double **, const int, const int);

typedef double * (*__init_vec__)(double *, const int);

double **mat_init_(double **ptr, const int rows, const int cols);

void insert_array(double *row_arr);

double** do_operation(__init__ init_mtx, double **mtxPtr, const int rows, const int cols);

double** create_matrix(__init__ mtx, __init_vec__ vtr, double **mtxPtr, 
                                        const int rows, const int cols);

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
    std::cout << "Hello world!" << std::endl;
	return EXIT_SUCCESS;
}

double* insert_array(double *row_arr, const int length){

    // length cannot be negative
    assert(length >= 0);
    row_arr = (double *)malloc(sizeof(double)*length);
    return row_arr;
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
        printf("row[%d] = %d bytes of storage.\n", i, sizeof(double)*cols);
    }
    return ptr;
}

double **init_matrix(double **mPtr, double *vPtr, __init_vec__ c_vector, const int length, 
                            const int rows, const int cols){

    // make sure rows/cols > 0
    assert(rows > 0);
    assert(cols > 0);

    // allocate memory
    ptr = (double **)malloc(sizeof(double *)*rows); 
            

}




double** do_operation(__init__ init_mtx, double **mtxPtr, 
            const int rows, const int cols){
            
        return init_mtx(mtxPtr, rows, cols);
}
