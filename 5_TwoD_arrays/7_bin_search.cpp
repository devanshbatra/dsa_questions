// binary search on 2d matrix
#include <iostream>
#include <vector>

using namespace std;



void printMat(int a[10][10], int row, int col){
    for(int i =0 ; i<row; i++){
        for(int j=0;j<col; j++){
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main(){

    int a[10][10] = { {1,2,3}, {4,5,6}, {7,8,9}, {10,11,12} };
    int row = 4, col= 3;

    int s=0, e=row*col-1;
    int mid = e+(s-e)/2;
    int key=2, flag=0;
    while(s<e){
        if(a[mid/col][mid%col] == key ){
            cout<<"found at "<<mid/col<<", "<<mid%col;
            flag=1;
            break;
        }
        else if(a[mid/col][mid%col] < key) s=mid+1;
        else e=mid-1;

        mid=e+(s-e)/2;
    }

    if(flag==0){
        cout<<"not found";
    }



    return 0;
}