#include <iostream>
#inclide <vector>
#include <algorithm>


int main(){

  std::vector<std::vector<int>> A = {{1, 10, 0}, 
                                     {1, 7, 1}};
  std::vector<std::vector<int>> B = {{1, 0},  
                                     {1, 2},
                                     {1, 1}};
  int C[2][2];
  
  // matrix multiplication algorithm
  // O(n^3) time 
  // ex C[0][0] is calculated as such:
  // iteration 1:   A[0][0]*B[0][0]
  // iteration 2:   A[0][0]*B[0][0] + A[0][1]*B[1][0]
  // iteration 3:   A[0][0]*B[0][0] + A[0][1]*B[1][0] + A[0][2]*B[2][0]
  // insert into C[0][0]
  // break out of inner most loop
  for(int i=0; i<2; i++){
    for(int j=0; j<3; j++){
      int temp = 0;
      for(int k=0; k<3; k++){
        temp += A[i][k]*B[k][j];
      }
      C[i][j] = temp;
    }
  }




return 0;
}
