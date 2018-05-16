//
// Created by nag on 5/15/18.
//

#ifndef SIMPLESPARSE_SSM_CUMSUM_H
#define SIMPLESPARSE_SSM_CUMSUM_H

#include <cmath>

/*This is a straight forward function. Say your workbench w consists of [2,3,1,2,2]
 * We need to convert this to a col_ptr starting with 0 and and the cumulative sums. ie.
 * [0] -> [0,2] -> [0,2,5] -> [0,2,5,6] and so on..
 * We will also replace w with the elements of Cp as we iterate through it.
 * So [2,3,1,2,2] -> [0,3,1,2,2] -> [0,2,1,2,2] and so on.
 * */

template <typename T>
double SSM_CumSum(T & Cp, T &colCount_w, int n )
{
    auto nz = 0;
    for (auto i = 0; i <n ; ++i){
        Cp[i] = nz;
        nz += colCount_w[i];
        colCount_w[i] = Cp[i];
    }
    Cp[n] = nz;  //last element (n+1) index

    return (float) nz;
}


#endif //SIMPLESPARSE_SSM_CUMSUM_H
