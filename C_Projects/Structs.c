#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <assert.h>


typedef struct c_vector {
    double *data_array;
    int size;
    int position;
}__vec__;

// initialize the struct
__vec__* __vec_init__(int s) {
   __vec__ *vPtr = nullptr;
   vPtr = (__vec__*)malloc(sizeof(__vec__));
   vPtr->size = s;
   vPtr->data_array = nullptr;
   vPtr->data_array = (double*)malloc(sizeof(double)*s);
   vPtr->position = 0;

    return vPtr;
}

int main() {

    __vec__ *v = __vec_init__(10);
    printf("v->size = %d\n", v->size);

    /*
    printf("%d\n", is_palindrome("redder"));
    printf("%d\n", is_palindrome("civic"));
    printf("%d\n", is_palindrome("redivider"));
    printf("%d\n", is_palindrome("madam"));
    printf("%d\n", is_palindrome("nascar"));
    printf("%d\n", is_palindrome("no"));
    printf("%d\n", is_palindrome("lol"));
    printf("%d\n", is_palindrome("loll"));*/

    printf("%d\n", check_palindrome("redder"));
    printf("%d\n", check_palindrome("civic"));
    printf("%d\n", check_palindrome("redivider"));
    printf("%d\n", check_palindrome("madam"));
    printf("%d\n", check_palindrome("lol"));
    printf("%d\n", check_palindrome("nascar"));
    printf("%d\n", check_palindrome("no"));
    printf("%d\n", check_palindrome("loll"));


    return 0;
}
