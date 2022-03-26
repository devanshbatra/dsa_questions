// print in spiral format
// https://leetcode.com/problems/spiral-matrix/submissions/
#include <iostream>

using namespace std;

int main(){

    int a[10][10] = { {1,2,3,4}, {5,6,7,8}, {9,10,11,12} };
    int row = 3, col= 4;
    int s_row=0, s_col=0;
    int total = row*col, count=0;
    int l_row = row-1, l_col = col-1;

    while(count<total){
        for(int i=s_col; i<=l_col; i++){
            cout<<a[s_row][i]<<" ";
            count++;
        }
        s_row++;
        for(int i=s_row; i<=l_row && count<total ; i++){
            cout<<a[i][l_col]<<" ";
            count++;
        }
        l_col--;
        for(int i=l_col; i>=s_col && count<total ; i--){
            cout<<a[l_row][i]<<" ";
            count++;
        }
        l_row--;
        for(int i=l_row; i>=s_row && count<total ; i--){
            cout<<a[i][s_col]<<" ";
            count++;
        }
        s_col++;
    }


    return 0;
}