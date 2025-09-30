// sorting an array containing only 0 and 1
// Can be done in just o(n)
// Using TWO POINTER APPROACH
// https://www.geeksforgeeks.org/problems/segregate-0s-and-1s5106/1
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

void printVec(vector<int> &a){
    for(int i=0; i<a.size(); i++){
        
        cout<<a[i]<<" ";
    }
    cout<<endl;
}
void swap(int *a, int *b){
    int temp;
    temp = *a;
    *a=*b;
    *b=temp;
}


void sort01(vector<int>& a){
    int i =0, n=a.size();
    int j = n-1;
    while(i<j){
        // while(a[i]==0){
        //     i++;
        // }
        // while(a[j]==1){
        //     j--;
        // }
        if(a[i]==1 && a[j]==0 ){
            swap(&a[i], &a[j]);
            i++;
            j--;
        }else if(a[i]==1 && a[j] == 1 ){
            j--;
        }else if(a[i]==0 && a[j] == 0){
            i++;
        }else{
            i++;
            j--;
        }
        
    }
}

void sort01_another(vector<int>& a){
    int i =0, n=a.size();
    int j = n-1;
    while(i<j){

        // ab ye multiple steps ko yahin kr dega- isliye andar i<j wali condition bhi lagani padi
        while(a[i]==0 && i<j ){
            i++;
        }
        while(a[j]==1 && i<j ){
            j--;
        }
        // ab a[i]==1 aur a[j]==0 - waali condition he bchegi
        if(i<j){
            swap(&a[i], &a[j]);
            i++;
            j--;
        }
        
    }
}

int main(){
    cout<<"enter the size";
    int n;
    cin>>n;
    cout<<"Enter the array elements: ";
    vector<int> a;
    for(int i=0; i<n; i++){
        int el;
        cin>>el;
        a.push_back(el);
    }
    printVec(a);
    sort01(a);
    printVec(a);
    return 0;
}