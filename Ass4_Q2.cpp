#include <iostream>  //declaring variables
#include <iomanip>
#include <string>
#include <fstream>
#include <cstdlib>
#include "Library.cpp"

using namespace std;
float Determinant(float arrA[4][4]){
    //Pivoting(arrA);
    LU_decomposition(arrA);
    float p = 1;
    for(int i =0;i<4;i++){
        p = p*arrA[i][i];
    }
    return p;
}

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
    /*
    Part_Pivoting(arrA);
    cout<< "The swapped matrix B is:"<< endl;
    for(int i = 0;i<4;i++){
        for(int j = 0;j<4;j++){
            cout<<arrA[i][j]<< " ";
        }
        cout<<endl;
    }
    */
    cout << Determinant(arrA) << endl;
    cout << "The LU decomposed matrix is:" << endl;
    for(int i = 0;i<4;i++){
        for(int j = 0;j<4;j++){
            cout<< arrA[i][j] <<" ";
        }
        cout<<endl;
    }
    if (Determinant(arrA) != 0){
        cout << "INVERSE EXISTS" << endl;
        LU_decomposition(arrA);
        FB_Substitution(arrA,4);

    }
    return 0;
}

