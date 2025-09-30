// Linear search
#include <iostream>

using namespace std;

int search(int n[10], int key){
    int flag=0;
    for(int i=0;i<10;i++){
        if(key==n[i]){
            cout<<"Element found at index: "<<i<<endl;
            flag=1;
        }
    }
    if(flag==0)  cout<<"Element not found";
}

int main(){
    int n[10] = {23, 65, 12, 76, 45, 23, 9, 78, 23, 90};
    int key;
    cin>>key;
    search(n, key);
    return 0;
}


