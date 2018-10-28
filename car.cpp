// This is the source file that contains the implementation of
// CSRMatrix and its corresponding functions

#include "csr.hpp"
#include "vec.hpp"

#include <iostream>

namespace csr {

// impls

// create a csr matrix
CSRMatrix *create(const int n, const int nnz) {
  CSRMatrix *ptr = nullptr;
  // FINISH ME
  // allocation
  // FINISH ME
  return ptr;
}

// destroy a csr matrix
void destroy(CSRMatrix *mat) {
  if (!mat) {
    return;
  }
  // FINISH ME
  // deallocation
  // FINISH ME
}

// assign a row
bool assign_row(CSRMatrix &mat, const int row, const int *cols,
                const double *vals, const int nnz) {
  if (row < 0 || row > mat.n || nnz < 0) return true;
  const int start = mat.indptr[row];  // bonus, this is how to get the starting entry of this row
  bool fail = false;
  // FINISH ME
  // construct row
  // FINISH ME
  return fail;
}

// extract the diagonal values
bool extract_diag(const CSRMatrix &A, vec::DenseVec &diag) {
  if (A.n != diag.n) return true;
  bool fail = false;
  // FINISH ME
  // extracting diagonal entries
  // FINISH ME
  return fail;
}

// matrix vector multiplication
bool mv(const CSRMatrix &A, const vec::DenseVec &x, vec::DenseVec &y) {
  bool fail = false;
  // FINISH ME
  // matrix vector multiplication
  // FINISH ME
  return fail;
}

}  // namespace csr
