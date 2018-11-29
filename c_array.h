#ifndef C_ARRAY_H
#define C_ARRAY_H
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>



namespace __c_arrays__ 
{
    // preprocessor macro to loothrough every element in arg list
    #define __for_each__(i, loopmax, ...) for(int i=0; i<loopmax; i++) \
                                                    {__VA_ARGS__}
    typedef struct __c_vec__ {
        double *data;
        int length;
        int front;
        int back;
        int free;
    } CVector;

    typedef struct __c_array__ {

        typedef struct __array__ {
            double *data;
            int mem_len;
            int free;
            int front;
        }__array__;

        // __array__ methods(fucntion pointers)
        typedef __array__ * (*__init_array__)(int len_);
        typedef void (*arr_front_inserter)(__array__ *arr_, double value);
        typedef void (*arr_back_inserter)(__array__ *arr_, double value);
        typedef void (*arr_print_)(__array__ *arr_);

        __array__ *arr_ =  (__array__*)malloc(sizeof(__array__));

    }CArray;
    


    //  __init__
    CVector * __c_vec_init__(int len_) {
        CVector *vec = NULL;  // initialize pointer
        vec = (CVector*)malloc(sizeof(CVector));  // allocate memory 
  
        assert(len_ > 0); // len must be greater than 0
        vec->length = len_; // initialize length of data array
        vec->data = NULL; // initialize array pointer
        vec->data = (double*)malloc(sizeof(double)*vec->length); // allocate memory for array
        vec->front = 0; // first position of array
        vec->back = (vec->length - 1);  // last position of array
        vec->free = len_;  // free space left in array

        return vec; // return pointer to CVector
    } // initialize the vector


    // __realloc__
    CVector *__c_vec_realloc__(CVector *old_vec, size_t new_length) {
        // reallocate memory to increase capacity
        
        /*Steps: 
        *       first create a new CVector with incread capacity.
        *       copy over values from old CVector to new CVector
        *       point old CVector to new CVector.    
        */
        CVector *new_vec = NULL;  // initialize new CVector
        new_vec = (CVector*)malloc(sizeof(CVector));  // allocate memory
        

    }

    //  __dealloc__
    void __c_vec_dealloc__(CVector *v) {
        if(v) {
            // Not NULL
            if(v->data) {
                free(v->data);  // free allocated memory
                v->data = NULL; // limit undefined behavior
            } else {
                printf("MemberDeallocationError: Struct membor already deallocated.\n");
            }
            free(v);   // free allocated memory 
            v = NULL; // limit undefined behavior
        } else {
            // If NULL
            printf("DeallocationError: Memroy already deallocated.\n");
        }
    }

    /*********************
    * Iteration methods  *
    **********************/
    // insert data into CVector
    void front_inserter(CVector *v, double value) {
        if(v->front < v->length && v->free != 0) {
            // insert into the data structure
           *(v->data + v->front) = value;
            v->front++; // increment front iterator
            v->free--;  // decriment free storage
        } else {
            if(v->front == v->back) {
                // use v->back to keep v->front < v->back
            }
        }
    }

    void begin_(CVector *v, double value) {
            // iterator 
    }




    // insert data into the back of CVector
    void back_inserter(CVector *v, double value) {
        if(v->back > v->front && v->free != 0) {
            // load data
            *(v->data + v->back) = value;
            v->back--;  // decriment back iterator
            v->free--;  // decriment free storage
        } else {
            printf("IndexOutOfRangeError: Cannot add data into array");
        }
    }

    /*****************
     * print methods *
    ******************/
    //  get the length of the array
    void get_length(CVector *v) {
        printf("CVector->length = %d\n", v->length);
    }

    // get the amount of free storage in arr
    void get_free(CVector *v) {
        printf("Free Storage\n----------\nAmnt: %d\n", v->free);
    }


} // namspace __c_arrays__



#endif // !C_ARRAY_H
