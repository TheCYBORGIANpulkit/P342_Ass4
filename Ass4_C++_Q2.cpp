#include <iostream>  //declaring variables
#include <iomanip>
#include <string>
#include <fstream>
#include <cstdlib>
#include "Library.cpp"

using namespace std;
int main(){
    cout<<"The matrix A is:"<< endl;
    float arrA[4][4];
    ifstream myfileM;
    myfileM.open("A4_Q2.txt");
    for(int i = 0;i<4;i++){
        for(int j = 0;j<4;j++){
            myfileM >> arrA[i][j];
            cout<< arrA[i][j] <<" ";
        }
        cout<<endl;
    }
    int det = Determinant(arrA);
    cout << "The determinant of the matrix is:" << det << endl;
    cout << "The LU decomposed matrix is:" << endl;
    for(int i = 0;i<4;i++){
        for(int j = 0;j<4;j++){
            cout<< arrA[i][j] <<" ";
        }
        cout<<endl;
    }
    //cout<< "the diagonal elements" << endl;
    //for(int i =0;i<4;i++)cout<< arrA[i][i] << endl;
    if (det != 0){
        cout << "INVERSE EXISTS" << endl;
        FB_Substitution(arrA,4);
    }
    return 0;
    /*RESULT:
    The matrix A is:
    0 2 8 6
    0 0 1 2
    0 1 0 1
    3 7 1 0
    The determinant of the matrix is:36
    The LU decomposed matrix is:
    3 7 1 0
    0 2 8 6
    0 0 1 2
    0 0.5 -4 6
    INVERSE EXISTS
    The RHS matrix b is:
    1 0 0 0
    0 1 0 0
    0 0 1 0
    0 0 0 1
    The INVERSE is:
    0.333333 -0.25 1.66667 -1.83333
    0 0.0833333 -0.666667 0.833333
    0 0.166667 -0.333333 -0.333333
    0 -0.0833333 0.666667 0.166667
    */
}

