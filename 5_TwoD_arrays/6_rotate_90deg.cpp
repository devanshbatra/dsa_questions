// to rotate a matrix by 90deg
/*
1 2 3       7 4 1
4 5 6  ==>  8 5 2
7 8 9       9 6 3
*/

/*
for this we need to first compute the transpose and then reverse every row.
*/
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
    int row = 3, col= 3;

    //performing transpose
    for(int i=0;i<row; i++){
        for(int j=i+1; j<row; j++){
            swap(a[i][j], a[j][i]);
        }
    }

    printMat(a, 3, 3);
    cout<<endl;
    //reversing every row 
    for(int i=0;i<row;i++){

        // ab ek ek row ke liye
        int s=0, e=col-1;
        while(s<e){
            swap(a[i][s], a[i][e]);
            s++;
            e--;
        }
    }

    cout<<"rotated matrix: "<<endl;
    printMat(a, 3, 3);

    return 0;
}