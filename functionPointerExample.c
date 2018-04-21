#include <stdio.h>

/*
 * William Murphy
 * 4/21/2018
 *
 * Example of how to read
 * and understand the different
 * types of pointers.
 */


// FUNC 1

/*         arr_len: function
 *           args:
 *                int size
 *           returns:
 *                int
 * */
int arr_len(int size){return size;}

// FUNC 2
/*         arr: function
 *            args:
 *              function pointer:
 *                      arr_len: function
 *                          args:
 *                              int size
 *              int s
 *            returns:
 *                  pointer to an int
 *
 *
 */
int * arr(int (*arr_len)(int), int s){

    int length = arr_len(s);
    int array[length];
    int* arrPtr;
    arrPtr = array;
    return arrPtr;
}



int main() {

    int * rs;
    rs = arr(arr_len, 5);   // note: arr[] and *arr are the same and thus, either one can be
                            //          be used in function declarations.

    *(rs) = 1;              // *(rs) points to array[0], *(rs+1) points to array[1] and so on
    *(rs + 1) = 10;
    *(rs + 2) = 100;
    *(rs + 3) = 9;
    *(rs + 4) = 10000;
    printf("result[0] = %d\nrs[1] = %d\nrs[2] = %d\nrs[3]=%d\nrs[4] = %d\n",*(rs),*(rs+1),*(rs+2),*(rs+3),*(rs+4));

    return 0;
}
