int matrix[4][4] = {{1, 0, 2, 0}, 
                        {0, 2, 0, 0},
                        {3, 0, 2, 2},
                        {1, 0, 0, 1}};

    // allocating memory for a matrix
    int rows = 4;
    int columns = 4;
    
    // use malloc to allocate memory
    int **matrixPtr = (int **)malloc(rows * sizeof(int *));
    
    // allocate memory for each of the rows
    int col = 0;
    while(col < rows){
        matrixPtr[col] = (int *)malloc(columns * sizeof(int));
        col += 1;
    }

    // pointer to pointer to int 
    int **ptr = &matrixPtr[0];

    // load in data by row(iterate over columns)
    *(*(ptr)) = 1;      // matrixPtr[0][0] = 1
    *(*(ptr) + 1) = 0;  // matrixPtr[0][1] = 0
    *(*(ptr) + 2) = 2;  // matrixPtr[0][1] = 2
    *(*(ptr) + 3) = 0;  // matrixPtr[0][1] = 0
 
    for(int i=0; i < 4; i++){
        for(int j=0; j<4; j++){
            std::cout << "matrixPtr["<<i<<"]["<<j<<"] = " << matrixPtr[i][j] << std::endl;;
        }
    }
