#include <iostream>  //declaring variables
#include <iomanip>
#include <string>
#include <fstream>
#include <cstdlib>
using namespace std;
void Product(float arrM[4][4], float arrN[4][4],int n){
    float arrP[n][n], x;
    //int arrQ[3][3];
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            arrP[i][j] = 0;
            //arrQ[i][j] = 0;
        }
    }
    for(int a = 0;a<n;a++){
        for(int b = 0;b<n;b++){
            for(int i = 0;i<n;i++){
                x = float(arrM[a][i])*float(arrN[i][b]);
                //cout<<x<<endl;
                arrP[a][b] = arrP[a][b] + x;
                //cout<< arrP[a][b];
            }
            //cout<< arrP[a][b]<< " ";
            //cout<< endl;
        }
    }
    cout<<"The product A*A^(-1) matrix is:"<< endl;
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            cout<<arrP[i][j]<< " ";
        }
        cout<<endl;
    }
}

void Part_Pivoting(float arrA[4][4]){
    for(int r = 0;r<3;r++){
        float pivot = arrA[r][r];
        //cout << pivot << endl;
        if(pivot == 0){
           for(int i = r+1;i<4;i++){
                if(abs(int(arrA[i][r])) > abs(int(pivot))){
                    float temp[4];
                    int j = 0;
                    for(int j = 0;j<4;j++){
                        temp[j] = arrA[r][j];
                        arrA[r][j] = arrA[i][j];
                        arrA[i][j] = temp[j];
                    }
                }
                else continue;
           }
        }
        else continue;
    }
}
void LU_decomposition(float arrA[4][4]){
    //Partial pivoting at first
    Part_Pivoting(arrA);
    for(int j = 0;j<4;j++){
        if(j == 0){
            //u[0][0] = arrA[0][0];
            //cout<< arrA[0][0] << endl;
            for(int i = 1;i<4;i++){
                arrA[i][j] = arrA[i][j]/arrA[0][0];
                //cout<< arrA[i][j] << endl;
            }
        }
        else{
            for(int i =0;i<4;i++){
                float s = 0;
                float a = 0;
                for(int k = 0;k<i;k++){
                    a = arrA[i][k]*arrA[k][j];
                    s = s + a;
                }
                //cout<< s << endl;
                if(i < j)arrA[i][j] = arrA[i][j] - s;
                else if(i == j){
                    arrA[i][i] = arrA[i][j] - s;
                    //if(i == j)cout<< arrA[i][j] << endl;
                }
                else{
                    float s = 0;
                    float a = 0;
                    for(int k = 0;k<j;k++){
                        a = arrA[i][k]*arrA[k][j];
                        s = s + a;
                    }
                    arrA[i][j] = (arrA[i][j] - s)/arrA[j][j];
                }
            }
        }
    }
    /*
    for(int i =0;i<4;i++){
        for(int j =0;j<4;j++){
            cout<< arrA[i][j] << endl;
        }
        cout<< endl;
    }
    */
}
float Determinant(float arrA[4][4]){
    //Pivoting(arrA);
    LU_decomposition(arrA);
    float p = 1;
    for(int i =0;i<4;i++){
        p = p*arrA[i][i];
    }
    return p;
}
// NOTE: This code assumes that the matrix A is already LU decomposed.
void FB_Substitution(float arrA[4][4], int n){
    //RHS matrix
    cout<<"The RHS matrix b is:"<< endl;
    float arrb[4][n];
    if(n == 1){
        ifstream myfileb;
        myfileb.open("A4_Q1b.txt");
        for(int i = 0;i<4;i++){
            myfileb >> arrb[i][0];
            cout<< arrb[i][0] <<" ";
            cout<<endl;
        }
    }
    else if(n == 4){
        ifstream myfileB;
        myfileB.open("A4_Q2b.txt");
        for(int i = 0;i<4;i++){
            for(int k =0;k<n;k++){
                myfileB >> arrb[i][k];
                cout<< arrb[i][k] <<" ";
            }
            cout<<endl;
        }
    }
    //Making augmented matrix
    int m = 4 + n;
    float arrL[4][m];
    for(int i = 0;i<4;i++){
        for(int j = 0;j<4;j++){
            if(i > j) arrL[i][j] = arrA[i][j];
            if(i == j) arrL[i][j] = 1;
            if(i < j) arrL[i][j] = 0;
        }
        /*
        for(int j = 4; j< m;j++){
            arrL[i][j] = arrb[i][j - 4];
        //cout<< arrL[i][4] << endl;
        }
        */
    }
    /*
    cout << "The L matrix(augmented):" << endl;
    for(int i = 0;i<4;i++){
        for(int j = 0;j<4;j++){
            cout<<arrL[i][j]<< " ";
        }
        cout<<endl;
    }
    */
    float arry[4][n];
    //solving Y
    if(n == 1){
        for(int i = 0;i<4;i++){
            float s = 0;
            for(int j = 0;j<i;j++){
                s = s + arrL[i][j]*arry[j][0];
            }
            arry[i][0] = (arrb[i][0] - s)/arrL[i][i];
        }
        //for backward substitution
        float arrU[4][4];
        for(int i = 0;i<4;i++){
            for(int j = 0;j<4;j++){
                if(i <= j) arrU[i][j] = arrA[i][j];
                if(i > j) arrU[i][j] = 0;
            }
            //arrU[i][4] = arry[i][0];
        }
        /*
        cout << "The U matrix(augmented):" << endl;
        for(int i = 0;i<4;i++){
            for(int j = 0;j<4;j++){
                cout<<arrU[i][j]<< " ";
            }
            cout<<endl;
        }
        */
        //solving X
        float arrX[4][1];
        for(int i = 3;i >= 0;i--){
            float s = 0;
            for(int j = i+1;j<4;j++){
                s = s + arrU[i][j]*arrX[j][0];
            }
            //cout<< s << endl;
            arrX[i][0] = (arry[i][0] - s)/arrU[i][i];
        }
        cout<< "The solution is:" << endl;
        for(int i = 0;i<4;i++){
            cout << "x[" << i << "] = "<< arrX[i][0] << endl;
        }
    }

    else{
    //solving Y
        for(int i = 0;i<4;i++){
            for(int j = 0;j<n;j++){
                float s = 0;
                for(int k = 0;k<i;k++){
                    s = s + arrL[i][k]*arry[k][j];
                }
                arry[i][j] = (arrb[i][j] - s)/arrL[i][i];
                //cout<< arry[i][j] << " ";
            }
            //cout<< endl;
        }
        //for backward substitution
        float arrU[4][4];
        for(int i = 0;i<4;i++){
            for(int j = 0;j<4;j++){
                if(i < j)arrU[i][j] = arrA[i][j];
                else if(i == j)arrU[i][j] = arrA[i][j];
                else arrU[i][j] = 0;
            }
        }
        //solving X[4][4]
        float arrX[4][4];
        for(int i = 3;i >= 0;i--){
           for(int j = 0;j<n;j++){
                float s = 0;
                for(int k = i+1;k<n;k++){
                    s = s + arrU[i][k]*arrX[k][j];
                }
                arrX[i][j] = (arry[i][j] - s)/arrU[i][i];
            }
        }
        cout<< "The INVERSE is:" << endl;
        for(int i = 0;i<4;i++){
            for(int j =0; j< 4;j++){
                cout << arrX[i][j] << " ";
            }
            cout<< endl;
        }
    }
}


