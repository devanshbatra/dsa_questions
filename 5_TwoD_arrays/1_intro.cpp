#include <iostream>

using namespace std;

// linear search
bool searchele(int a[][3], int key, int row , int col){
    for(int i= 0 ; i<row; i++){
        for(int j=0; j<col; j++){
            if(key==a[i][j]){
                return true;
            }
        }
    }return false;
}

int main(){
    int a[4][3] = {1,2,3 ,4,5,6 ,7,8,12 ,34,45,35};
    // int a[4][3] = {{1,2,3,4}, {5,6,7,8}, {12,34,45,35}}; /ya aise karlo
    
    for(int i=0; i<4; i++){
        for(int j = 0; j< 3; j++){
             cout<<a[i][j]<<" ";
        }cout<<endl;
    }

    // searching for an element in a 2d array(linear search)
    int key= 6;
    if(searchele(a, key, 3, 4)){
        cout<<"Element found !!"<<endl;
    }else cout<<"element not found!!";

}