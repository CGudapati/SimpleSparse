//
// Created by nag on 5/15/18.
//

#ifndef SIMPLESPARSE_SSM_UTILS_H
#define SIMPLESPARSE_SSM_UTILS_H

#include "SSM_Includes.h"

template <typename T>
void SSM_print( const T & mat, int brief)
{
    int m, n, nz, nzmax;

    if (!&mat){
        std::cout << "(null)" << std::endl;
    }
    m = mat.m;
    n = mat.n;
    nz = mat.nz;
    nzmax = mat.nzmax;

    if (nz < 0)
    {
        std::cout << "CSC: " << m << " x " << n << " nzmax: " << nzmax << std::endl;

        for (int j = 0; j < n; ++j) {
            std::cout << "    col " << j << " : locations " << mat.col_ptr[j]<< " to " <<mat.col_ptr[j+1]-1 << std::endl;
            for (int p = mat.col_ptr[j]; p < mat.col_ptr[j+1] ; ++p) {
                std::cout << "      " << mat.row_index[p] << ":  " << mat.A_value[p]  << std::endl;
                if (brief && p > 20)
                {
                    std::cout << "......." << std::endl;
                    return void();
                }
            }
        }


    }
    else
    {
        std::cout << "triplet: " << m << " x " << n << " nzmax: " << nzmax << " nnz: " << nz << std::endl;
        for (int p = 0; p < nz; ++p) {
            std::cout << "      " << mat.row_index[p] <<  " " <<  mat.col_ptr[p] << " : " << mat.A_value[p]<< std::endl;
            if (brief && p > 20)
            {
                std::cout << "......." << std::endl;
                return void();
            }
        }

    }


}

template<typename T>
void printVector (std::vector<T> const &vec)   //prints vector horizontally
{
for ( auto i : vec )
{
std::cout << i << " ";

}
std::cout  << std::endl;
}

template<typename T>
void printSSMatrix(const T &mat)
{
    std::cout << "Number of rows: " << mat.m << std::endl;
    std::cout << "Number of cols: " << mat.n << std::endl;
    std::cout << "Col. Ptr: " << std::endl;
    printVector(mat.col_ptr);
    std::cout << "Row. Index: "<< std::endl;
    printVector(mat.row_index);
    std::cout << "A Values: " << std::endl;
    printVector(mat.values);
    std::cout << std::endl;
}
template <typename T>
constexpr bool SSM_Is_Triplet(const T &mat) {
    return (mat.nz >= 0) ;  //If it is triplet, then return yes
};

template <typename T>
constexpr bool SSM_Is_CCS(const T &mat) {
    return (mat.nz < 0);  //If it is triplet, then return yes
};


template <typename T>
void SSM_write_CCS(const T & mat)
{
    std::ofstream outFile("my_file.txt");

    for (const auto &e : mat.col_ptr)
    {
        outFile  << e << " ";
    }
    outFile << std::endl;

    for (const auto &e : mat.row_index)
    {
        outFile << e << " ";
    }
    outFile << std::endl;

    for (const auto &e : mat.A_value)
    {
        outFile <<std::setprecision(10)<< e << " ";
    }

    outFile.close();
}

template <typename T>
void print(const T &var)
{
    std::cout << var << std::endl;
}

void xls()
{
    std::cout << "HI" << std::endl;
}


#endif //SIMPLESPARSE_SSM_UTILS_H
