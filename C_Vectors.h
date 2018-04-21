//
// Created by William on 4/21/2018.
//

#ifndef CPNTRS_C_VECTORS_H
#define CPNTRS_C_VECTORS_H

#include <stdlib.h>
#include <stdio.h>

/* 
 * Building a vector like class in C
 * utilizing malloc and realloc for
 * dynamic memory allocation.
 *
 * TODO:
 *     Add many of the features common with vectors.
 *     Actually test to make sure malloc/realloc are
 *     working correctly.
 */



typedef struct C_vector{
    double* _data;
    int len;
    int v_position;

};

// initialize the vector
void __init__(struct C_vector* vtr, int size){
    vtr->len = size;
    if(size == 0)

        // if length is 0, no memory needs to be allocated yet
        vtr->_data = NULL;
    else

        // allocate enough memory to handle initial vector length
        vtr->_data = (double*)malloc(sizeof(double) * vtr->len);

    // starting point should be in the front of the vector
    vtr->v_position = 0;
}

// insert value
void insert(struct C_vector* vtr, double value){

    // get current position in the vector
    int current_pos = vtr->v_position;
    if(current_pos < (vtr->len)-1) {
        vtr->_data[current_pos] = value;
        vtr->v_position++;
    } else{
       // first, make a copy of original vector
        struct C_vector vtr_copy;
        vtr_copy.len = vtr->len;

        // set to zero to get access to all elements of vtr
        vtr_copy.v_position = 0;

        // copy over all data stored in vector vtr
        while(vtr_copy.v_position < vtr->v_position){
            vtr_copy._data[vtr_copy.v_position] = vtr->_data[vtr_copy.v_position];
            vtr_copy.v_position++;
        }

        // reallocate memory
        /* NOTE: The reason to copy over the memory stored in vtr is
         *  due to the use of realloc. realloc increases the memory storage
         *  of the vector but if there is no room left in the stack, the
         *  memory location for the entire vector will be moved, causeing any
         *  pointers pointing to original memory location to break.
         * */
        int new_len = (vtr->len + 1);
        vtr->len = 0;   // set to front of array to refill
        vtr->_data = realloc(vtr->_data, sizeof(double) * new_len);
        while(vtr->len < vtr_copy.len){
            vtr->_data[vtr->len] = vtr_copy._data[vtr->len];
            vtr->len++;
        }

        // free memory allocated to vtr_copy
        free(vtr_copy._data);
        vtr_copy._data = NULL; // good practice to set pointer to NULL in stack

        // add new value into the vector
        vtr->_data[++vtr->len] = value;
    }


}





#endif //CPNTRS_C_VECTORS_H

