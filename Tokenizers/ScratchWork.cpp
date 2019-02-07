#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#define BUFFER 50

// typedef for the function pointer
typedef int (*operation_ptr)(int, int);

int add(int a, int b) { return a + b;}
int mult(int a, int b) {return a * b;}

// perform operation o two integers
int do_operation(int (*op)(int, int), int x, int y) {
    return op(x, y);
}

// same as do_operation but using a typedef
int some_operation(operation_ptr op, int x, int y) {
    return op(x, y);
}


//---------------------------------------------------------
// Tokenize an input string 

struct Token {
    char **tokens;
    int *token_lengths;
};

void tokenize(const char *input) {
    
    char **container   = NULL;
    char *current_word = NULL;
    int *word_lengths  = NULL;

    int input_length = 0;
    while(*(input + input_length) != '\0') {
        input_length++;
    } // calculate the size of the input string

    // allocate memory for the array of arrays and word lengths
    container    = (char**)malloc(input_length*sizeof(char*));
    word_lengths = (int*)malloc(input_length*sizeof(int));
    // temporary container to store current word
    // This gets overridden after each word is written to container
    current_word = (char*)malloc(BUFFER*sizeof(char)); 

    char delimiter = ' '; // space delimiter
    int word_size  = 0;   // temp: stores current word's length

    int i = 0;  // container[i][] position
    int j = 0;  // container[][j] position
    int k = 0;  // input word position
    int word_counter = 0; // counter for words
    while(word_counter < input_length) {
        while(*(input + k) != '\0') {
            if(*(input + k) == delimiter) {
                // if the word has ended
                
                // allocate memory for the inner array
                *(container + word_counter) = (char*)malloc(word_size*sizeof(char));

                // set the length of the current word
                *(word_lengths + word_counter) = word_size;

                int l = 0;
                while(l < word_size) {
                    // copy contents of the temp pointer to container
                    *(container + word_counter)[l] = *(current_word + l);
                }
                word_size = 0; // reset the word size to 0
                break; // break out of inner loop to incriment word_counter

            } else {
                // if we are currently in a word
                *(current_word + word_size) = *(input + k); 
                
                word_size++; // incriment the word_counter iterator
                k++;   // incriment the input iterator
            }
        }
        word_counter++; // incriment container[n] iterator
    }


    

}




int main(int argc, char **argv) {

    // array of 11 character arrays
    char **char_array = (char**)malloc(11*sizeof(char*));
    int i = 0;
    
    while(i < 11) { // allocate memory for each character array
        *(char_array + i) = (char*)malloc(4*sizeof(char));
        i++;
    }

    // test: input the values of the char arrays
    int j = 0;
    int k = 0;
    *(char_array + j)[k]   = 'w'; 
    *(char_array + j)[k+1] = 'i';
    *(char_array + j)[k+2] = 'l';
    *(char_array + j)[k+3] = 'l';
    
    // same as above
    *(*(char_array + j)     + (k+1)) = 'w';
    *(*(char_array + (j+1)) + (k+1)) = 'o';
    *(*(char_array + (j+2)) + (k+1)) = 'r';
    *(*(char_array + (j+3)) + (k+1)) = 'd';

   printf("char_array[0][0] = %c", char_array[3][0]);
   

   tokenize("this is an input string");


    return 0;
}











/*

#define BUFFER 50



struct tokens {
    char* current_string;
    char** str_array;
    size_t str_length;
};

void __init__(tokens* tok, const char* input_str) {

    tok = NULL; // initialize
    tok = (tokens *)malloc(sizeof(tokens)); // allocate memory
    // allocate memory for the string contianer
    tok->current_string = (char*)malloc(BUFFER*sizeof(char));

    tok->str_array = (char**)malloc(strlen(input_str)*sizeof(char*));
    // allocate memory for each char array
    for(int i=0; i < strlen(input_str); i++) {
        tok->str_array[i] = (char*)malloc(BUFFER*sizeof(char));
    }

    char *str_feed = (char*)malloc(BUFFER*sizeof(char)); // temporary string container
    

    char space = ' ';
    int buff_counter = 0;
    int j = 0;
    int k = 0;  // counter for 
    for(int i=0; *(input_str + i) != '\0'; i++) {
        if(*(input_str + i) == space){
            j++;    // move to the next array of arrays
            k = 0;  // restart the inner counter 
        } else {
            *(tok->str_array[j] + k) == *(input_str + i);
            printf("current token: %c\n", *(tok->str_array[j] + k));
            k++;  
        }
    }


}


int main() {

    char **str_ptr_array; // pointer to pointer to char
    char *current_word;   // temporary word container
    int *word_lengths;    // stores the lengths of the words
    const char* input_str = "this is an imput string";
    const char* input_str_two = "this is some amount of words strung together to be analyzed";
    int num_words = 0;  // number of words in the input string
    char space = ' ';
    // step one: calculate the length of the input string
    int str_length = 0;
    while(*(input_str_two + str_length) != '\0'){
        str_length++;
    }
    // return the length of the input string
    printf("input_str_two's length is: %d\n", str_length);

    
    // step two: count the number of words
    for(int i=0; *(input_str_two + i) != '\0'; i++) {
        if(*(input_str_two + i) == space) {
            num_words++; // increase the word count by 1
        }
    }
    num_words = ++num_words;
    printf("Total number of words: %d\n", num_words);

    // step three: allocate memory
    //-----------------------------------------------------
    // allocate for the pointer to pointer to char
    str_ptr_array = (char**)malloc(num_words*sizeof(char*));
    word_lengths = (int*)malloc(num_words*sizeof(int)); // stores the word length 
    current_word = (char*)malloc(BUFFER*sizeof(char)); // tempory container
    
    
    
    int word_len = 0;   // length of the word
    // allocate memory for each of the inner pointers
    int counter = 0;
    int j = 0;
    int k = 0;
    while(counter < num_words) { // loop through each of the words
        while(*(input_str_two + j) != '\0') { // loop through entire string
            if(*(input_str_two + j) == space) { // if a space is found
                // first: set the length of the inner array
                str_ptr_array[counter] = (char*)malloc(word_len*sizeof(char));
                *(word_lengths + counter) = word_len;
                // next: loop through the the length of the word
                int l = 0;
                while(l < k) {
                    // insert the word into the inner array
                    *(str_ptr_array[counter] + l) = *(current_word + l);
                    l++; // increment l
                } 
                k = 0; // reset the value of k for the temproy contianer
                    // to overwrite the values

               word_len = 0;    // reset the word length
               break;   // break out of the inner while loop
            } else {
                word_len++; // increase the length by one
                *(current_word + k) = *(input_str_two + j);
                k++;
                j++;
            }
        }
        counter++; // increase the counter
    }
    printf("first word, first letter: %c\n", str_ptr_array[0][0]);
    */




