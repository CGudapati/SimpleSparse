//
// Created by nag on 5/15/18.
//

#ifndef SIMPLESPARSE_SSM_SPARSE_H
#define SIMPLESPARSE_SSM_SPARSE_H

#include "SSM_Includes.h"
template <typename T, typename S>
struct SSparseMat{

    T nzmax;  //maximum number of entries
    T m;  //Number of rows
    T n;  //number of columns
    std::vector<T> row_index;
    std::vector<T> col_ptr;
    std::vector<S> values;
    int nz;

    SSparseMat() = default;
    SSparseMat(T numRows, T numCols, T nzFlag, T nzmaxVal) :
            m(numRows), n(numCols), nz(nzFlag), nzmax(nzmaxVal)
    {
     col_ptr = std::vector<T> ((numCols+1));
     row_index = std::vector<T>(nzmaxVal);
     values = std::vector<S>(nzmaxVal);
    }
};

#endif //SIMPLESPARSE_SSM_SPARSE_H
