// source code of COO format

#include "coo.hpp"
#include "vec.hpp"

namespace coo {

// create a csr matrix
COOMatrix *create(const int n, const int nnz) {
  COOMatrix *ptr = nullptr;
  // FINISH ME
  // allocate ptr
  // FINISH ME
  return ptr;
}

// destroy a csr matrix
void destroy(COOMatrix *mat) {
  if (!mat) return;
  // FINISH ME
  // deallocate ptr
  // FINISH ME
}

// assign a triplet (i,j,v)
bool assign_ijv(COOMatrix &mat, const int i, const int j, const double v,
                const int nnz_index) {
  bool fail = false;
  // FINISH ME
  // constructo entry (i,j,v) in slot nnz_index
  // FINISH ME
  return fail;
}

// extract the diagonal values
bool extract_diag(const COOMatrix &A, vec::DenseVec &diag) {
  if (A.n != diag.n) return true;
  bool fail = false;
  // FINISH ME
  // extracting diagonal entries
  // FINISH ME
  return fail;
}

// matrix vector multiplication
bool mv(const COOMatrix &A, const vec::DenseVec &x, vec::DenseVec &y) {
  bool fail = false;
  // FINISH ME
  // matrix vector multiplication
  // FINISH ME
  return fail;
}

}  // namespace coo
