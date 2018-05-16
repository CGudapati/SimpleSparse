//
// Created by nag on 5/15/18.
//

#ifndef SIMPLESPARSE_SSM_COMPRESS_H
#define SIMPLESPARSE_SSM_COMPRESS_H

#include "SSM_Includes.h"

template <typename T>
T SSM_Compress(const T & triplet_mat)
{
    SSparseMat<int, double> C(triplet_mat.m, triplet_mat.n, triplet_mat.nz, triplet_mat.nzmax); //Creating a Compressed column storage vector

    std::vector<int> w(triplet_mat.n); //This is a workbench vector, if there are 4 columns, this will have 4 element


    //say the col_Ptr is {0,0,1,1,1,2,3,3,4,4} , we can see that there are 2 entries in 0th column and 3 entries in 1st column
    // etc. w will have 5 elements as w[0] = 2 w[1] = 3 etc.
    for (auto k = 0; k < triplet_mat.nz; ++k) {
            ++w[triplet_mat.col_ptr[k]];  //whenever it encounters a column index in col_ptr, the corresponding element in w is incremented by 1
    }

    //We will use the col_count w workbench vector and get the colPtr which is a cumulative sum
    SSM_CumSum(C.col_ptr, w, triplet_mat.n);

    //Now we will get the row_index and the values. We will go through the triplet_colptr and then use that as index of workbench w
    //and te supply that value to the row_index vector and the value will be the kth value in triplet.row_ptr

    for(auto k = 0 ; k < triplet_mat.nz; ++k)
    {
        auto p = w[triplet_mat.col_ptr[k]];
        C.row_index[p] = triplet_mat.row_index[k];
        C.values[p]    = triplet_mat.values[k];
        ++w[triplet_mat.col_ptr[k]];
    }
    C.nz = -1; //Since this is a triplet matrix

    return C;


}

#endif //SIMPLESPARSE_SSM_COMPRESS_H
