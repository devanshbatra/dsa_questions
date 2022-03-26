#include<iostream>
#include<vector>
#include<string>

using namespace std;

int binSearch(vector<int> a, int h, int l, int k){
    cout<<"l and h: "<<l<<" "<<h<<endl;
    int ans=0;
    if(l<=h){
        int mid = (h+l)/2;
        if(a[mid]==k){
            cout<<"found"<<endl;
            return mid;
        }
        else if(a[mid]>k){
            h=mid-1;
            binSearch(a, h, l, k);
        }else{
            l=mid+1;
            binSearch(a, h, l, k);
        }
    }else{
        cout<<"not found"<<endl;
        return -1;
    }
}

// integer overflow condition
/*
integer has max value of (2^31)-1 and supposse both high and low is of INT_MAX and 
mid = (h+l)/2 which will then overflow so to avoid this condition we use a different form of same formula

->mid = h/2 + l/2 + h/2 - h/2
-> mid = h/2+h/2 + l/2-h/2
-> mid= h + (l-h)/2 //this will not cause any overflow
*/


int binSearch_int_over(vector<int> a, int h, int l, int k){
    cout<<"l and h: "<<l<<" "<<h<<endl;
    int ans=0;
    if(l<=h){
        int mid = h+ (l-h)/2;
        if(a[mid]==k){
            cout<<"found"<<endl;
            return mid;
        }
        else if(a[mid]>k){
            h=mid-1;
            binSearch(a, h, l, k);
        }else{
            l=mid+1;
            binSearch(a, h, l, k);
        }
    }else{
        cout<<"not found"<<endl;
        return -1;
    }
}

int main(){
    cout<<"enter the size";
    int n;
    cin>>n;
    cout<<"Enter the array elements in increasing order : ";
    vector<int> a;
    for(int i=0; i<n; i++){
        int el;
        cin>>el;
        a.push_back(el);
    }
    cout<<"Enter the element to be searched: ";
    int key;
    cin>>key;

    int l=0, h=n-1;

    int index = binSearch(a, h, l, key);
    cout<<"The index of element is: "<<index<<endl;

    return 0;
}