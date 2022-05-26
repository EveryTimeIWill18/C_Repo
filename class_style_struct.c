#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

struct DataFrame {

    double ** _data_frame;
    int n_rows;
    int n_cols;

    int row_ptr;
    int col_ptr;
};

struct DataFrame create_dataframe(int n_rows, int n_cols) {
            struct DataFrame df;
            df.n_rows = n_rows;
            df.n_cols = n_cols;

            // Allocate memory for the 2d array
            df._data_frame = (double**)malloc(df.n_rows * sizeof(double*));
            // Allocate memory for the the columns
            for (int i=0; i < df.n_cols; i++) {
                *(df._data_frame + i) = (double*)malloc(df.n_cols * sizeof(double));
            }

            // Set the position pointers
            df.row_ptr = 0;
            df.col_ptr = 0;

            return df;
}

void insert_data(struct DataFrame * df, double value) {
    if (df->col_ptr <= df->n_cols-1 && df->row_ptr <= df->n_rows-1) {
        // if there is still space in the current row & column
        df->_data_frame[df->row_ptr][df->col_ptr] = value;
        df->col_ptr++;

    } else if (df->col_ptr == df->n_cols && df->row_ptr <= df->n_rows-1) {
        // If the current column is filled but not the rows, move to the next row
        df->row_ptr++;
        df->col_ptr = 0;
        df->_data_frame[df->row_ptr][df->col_ptr] = value;
        df->col_ptr++;

    } else if (df->col_ptr <= df->n_cols-1 && df->row_ptr == df->n_rows) {
        // If we are in the last row but there's still room in the column
        df->_data_frame[df->row_ptr][df->col_ptr] = value;
        df->col_ptr++;

    } else if (df->col_ptr == df->n_cols && df->row_ptr == df->n_rows) {
        printf("DataFrame IS FILLED TO CAPACITY");
        // Create a temp 2d array with the new size, copy over and delete the old array
        int temp_n_rows = df->n_rows + 1;

        // Allocate the new memory
        double **temp = (double**)malloc(temp_n_rows * sizeof(double*));
        for (int i=0; i < df->n_cols; i++) {
            *(temp + i) = (double*)malloc(df->n_cols * sizeof(double));
        }

        // Write the data into temp array
        for (int i=0; i < df->n_rows; i++) {
            for (int j=0; j < df->n_cols; j++) {
                *(*(temp + i) + j) = *(*(df->_data_frame + i) + j);
            }
        }
        df->_data_frame = temp;

        // deallocate temp memory
//        for (int i=0; i < temp_n_rows; i++) {
//            free(temp[i]);
//        }
//        free(temp);

        // Set new row size
        df->n_rows = temp_n_rows;
        df->row_ptr++;
        df->col_ptr = 0;
        *(*(df->_data_frame + df->row_ptr) + df->col_ptr) = value;
        df->col_ptr++;
    }
    else{
        printf("DataFrame IS FILLED TO CAPACITY");

    }

}




int main() {
    int row = 4, col = 4;

    struct DataFrame df_1 = create_dataframe(row, col);
    insert_data(&df_1, 10000.99);
    insert_data(&df_1, 500000.99);
    insert_data(&df_1, 700000.99);
    insert_data(&df_1, 800000.99);

    insert_data(&df_1, 900000.99);
    insert_data(&df_1, 80.99);
    insert_data(&df_1, 1.99);
    insert_data(&df_1, 840.99);

    insert_data(&df_1, .99);
    insert_data(&df_1, 129.99);
    insert_data(&df_1, 1.99);
    insert_data(&df_1, 4.99);

    insert_data(&df_1, 11.99);
    insert_data(&df_1, 8444.99);
    insert_data(&df_1, 23.99);
    insert_data(&df_1, 1000000000.99);

//    insert_data(&df_1, 0.959);

    printf("df_1[3][0] = %f\n", *(*(df_1._data_frame + 3) + 3));
    printf("Get row pointer: %d\n", df_1.row_ptr);
    printf("Get col pointer: %d\n", df_1.col_ptr);









    printf("Hello, World!\n");
    return 0;
}
