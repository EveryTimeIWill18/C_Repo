//
//  main.c
//  C_testing
//
//  Created by William Murphy on 3/17/18.
//  Copyright © 2018 William Murphy. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

#define BUFFER 1000


int main(int argc, const char * argv[]) {
   
    // set the name of the file to search
    char filename[] = "/Users/williammurphy/Downloads/ls.s3.0.0.0.0.2018-03-14T00.01.tag_http-prefix-tag-2.part4231.txt";
    char c;
    
    // read and write files
    FILE *read_file;
    read_file = fopen(filename,"r+");
    
    // check read does not fail
    if(!read_file){
        fprintf(stderr, "ERROR: file: %s\n could not be opened\n exiting ...\n", filename);
        exit(1);
    }
    
    // allocate memory to store the file
    char *json_feed = (char*)malloc(BUFFER*sizeof(char));
    int buff_cntr = 0;
    int i = 0;
    int num_open_braket = 0;
    
    while ((c = getc(read_file)) != EOF) {
        ++buff_cntr;
        if(buff_cntr >= 1000){
            
            // memory must be reallocated
            char *new_json_feed = (char*)realloc(json_feed, 2*BUFFER*sizeof(char));
            
            // if no more memory can be allocated
            if(!new_json_feed){
                fprintf(stderr, "ERROR: No further memory could be allocated, quitting ...\n");
                exit(1);
            }
            // point memory location of json_feed to the location of new_json_feed
            json_feed = new_json_feed;
        }
        if(c == '{'){
            num_open_braket++;
        }
        if(c == '}'){
            num_open_braket--;
        }
        if(num_open_braket == 0 && i != 0){
            *(json_feed + (i)) = '}';
            FILE *f_write;
            
            // change path to the location you want to store these files
            f_write = fopen("/Users/williammurphy/Desktop/json_feed_.txt", "w");
            
            // write one text file per full json_feed
            fwrite(json_feed, i*sizeof(json_feed), sizeof(json_feed), f_write);
            
            // close file writes and free allocated memory
            fclose(f_write);
            break;
        }
        *(json_feed + i) = c;
        i++;
    }
    
    printf("%s ",json_feed);
    // close the read file
    fclose(read_file);
    free(json_feed);
   

    return 0;
}
