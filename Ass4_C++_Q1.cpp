#include <iostream>  //declaring variables
#include <iomanip>
#include <string>
#include <fstream>
#include <cstdlib>
#include "Library.cpp"
using namespace std;

int main(){
    cout<<"The LHS coefficient matrix A is:"<< endl;
    float arrA[4][4];
    ifstream myfileA;
    myfileA.open("A4_Q1.txt");
    for(int i = 0;i<4;i++){
        for(int j = 0;j<4;j++){
            myfileA >> arrA[i][j];
            cout<< arrA[i][j] <<" ";
        }
        cout<<endl;
    }
    LU_decomposition(arrA);
    FB_Substitution(arrA, 1);
    myfileA.close();
    return 0;
    //RESULT:
    /*
    The LHS coefficient matrix A is:
    1 0 1 2
    0 1 -2 0
    1 2 -1 0
    2 1 3 -2
    The RHS matrix b is:
    6
    -3
    -2
    0
    The solution is:
    x[0] = 1
    x[1] = -1
    x[2] = 1
    x[3] = 2
    */
}

