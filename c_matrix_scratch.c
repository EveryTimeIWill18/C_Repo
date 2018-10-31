namespace vec {

    typedef struct __coo_matrix__ {
        double *v;          ///< value data array
        int *i;         ///< row indices
        int *j;         ///< column indices
        int n;          ///< size of the square matrix
        int nnz;        ///< total number of non-zeros
    } COOMatrix;

    COOMatrix *create(const int n, const int nnz){
            
            // initialize the pointer
            COOMatrix *ptr = nullptr;
            // allocate memory for the struct
            ptr = (COOMatrix*)malloc(sizeof(double)*n*n);
            // set the matrix dimension
            ptr->n = n;
            // make sure dimension is not negative
            assert(ptr->n >= 0);
            // set the number of non zero entries
            ptr->nnz = nnz;
             // make sure dimension is not negative
            assert(ptr->nnz >= 0);

            // return pointer to a struct
            return ptr;
    }

    void destroy(COOMatrix *mat){
        if(!mat){
            // if error occurs
            return;
        }
        // deallocate memory
    

    }
}
