#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <assert.h>

// define a series template
#define qvec(T)             \
    struct qvec_##T {       \
        size_t cap, len;    \
        T data[];           \
    }

#define qvec_new(T)                                                           \
({                                                                            \
    const size_t initial_size = 16;                                           \
    struct qvec_##T *v = malloc(sizeof(qvec(T)) + sizeof(T) * initial_size);  \
    v->cap = initial_size;                                                    \
    v->len = 0;                                                               \
    v;                                                                        \
})

int is_palindrome(const char *word) {
    /*Return's 1 if word is palindrome*/
    int i = 0;
    while(*(word + i) != '\0') {
        i++;
    }
    // get the midpoint
    int midpoint = (i/2);
    int j = 0; // create an iterator
    while ( j < midpoint) {
        if (*(word + j) != *(word + (i-1)-j)) {
            return 0;
        }
        j++;
    }
    return 1;
}

int check_palindrome(const char *word) {

    int i = 0; // get the length of the word
    while(*(word + i) != '\0') {
        i++;
    }
    // get the midpoint
    int midpoint = (i/2);
    int j = 0; // create an iterator
    while (j < midpoint) {
        if (*(word + j) == *(word + (i-1)-j)) {
        }
        else {
            return 0;
        }
        j++;
    }
    return 1;
}


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

// insert data
void vec_insert(__vec__ *vPtr, double value) {

    if (vPtr->position < vPtr->size-1) {
        // insert the data into the current position
        *(vPtr->data_array + vPtr->position) = value;
        vPtr->position++; // increment the pointer
    } else {
        printf("vector if full!");
    }
}

double vec_remove(__vec__ *vPtr, int pos) {
    if(pos < vPtr->position) {
      double pop = *(vPtr->data_array + pos);
      vPtr->position = pos; // move pointer to this location
      *(vPtr->data_array + pos) = -0.000001; // remove marker
      return pop;
    } else {
        printf("pos is out of bounds!");
    }

}



int main() {

    __vec__ *v = __vec_init__(10);
    printf("v->size = %d\n", v->size);

    vec_insert(v, 100.1);
    vec_insert(v, 200.200);
    vec_insert(v, 300.300);
    vec_insert(v, 400.4000);
    printf("v->position = %d\n", v->position);
    printf("v->data_array[0] = %f\n", *(v->data_array + 0));
    printf("v->data_array[0] = %f\n", *(v->data_array + 1));
    printf("v->data_array[0] = %f\n", *(v->data_array + 2));
    printf("v->data_array[0] = %f\n", *(v->data_array + 3));


    printf("%d\n", check_palindrome("redder"));
    printf("%d\n", check_palindrome("civic"));
    printf("%d\n", check_palindrome("redivider"));
    printf("%d\n", check_palindrome("madam"));
    printf("%d\n", check_palindrome("lol"));
    printf("%d\n", check_palindrome("nascar"));
    printf("%d\n", check_palindrome("no"));
    printf("%d\n", check_palindrome("loll"));

 qvec(int) *q = qvec_new(int);


    return 0;
}
