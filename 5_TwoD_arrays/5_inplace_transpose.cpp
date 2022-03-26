// Transpose of an nXn matrix(inplace)
#include <iostream>
#include <vector>

using namespace std;


void swap(int &a, int &b){
    int temp = a;
    a=b;
    b=temp;
}

void printMat(int a[10][10], int row, int col){
    for(int i =0 ; i<row; i++){
        for(int j=0;j<col; j++){
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main(){

    int a[10][10] = { {1,2,3}, {4,5,6}, {7,8,9} };
    vector <int> v(3, 0);
    int row = 3, col= 3;
    for(int i=0;i<row; i++){
        for(int j=i+1; j<row; j++){
            swap(a[i][j], a[j][i]);
        }
    }

    printMat(a, 3, 3);

    return 0;
}