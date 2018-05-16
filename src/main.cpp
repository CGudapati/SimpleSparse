
#include <iostream>
#include "SSM_Includes.h"
int main() {

    SSparseMat<int, double> C(5,5,10,10);

    std::vector<int>v1   {0,3,0,1,4,2,0,4,1,3};
    std::vector<int>v2   {0,0,1,1,1,2,3,3,4,4};
    std::vector<double>v3{1,1,3,1,2,5,2,3,2,4};

    C.row_index =  v1;
    C.col_ptr = v2;
    C.values = v3;

    printVector(v3);
    printSSMatrix(C);
    SSM_Is_Triplet(C) ? print("yes!"):  print("No") ;
    std::cout << std::endl;

    SSparseMat<int, double> C1 = SSM_Compress(C);
    SSM_Is_CCS(C1) ? print("yes!"):  print("No") ;

    printSSMatrix(C1);


}