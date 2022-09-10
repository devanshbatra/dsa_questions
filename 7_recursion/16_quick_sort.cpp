#include<iostream>
using namespace std;
void print_arr(int arr[], int n){
    for(auto i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }cout<<endl;
}

// partition ka 2 kaam h ki:
// 1> pivot element ko uski sahi jagah pr pahauchana hai
// 2> pivot ke left mein saare chotte aur right mein saare bade element daal do.
int partition(int arr[], int s, int e){
    int pivot = arr[s], cnt=0;
    for(int i=s+1; i<=e; i++){
        if(arr[i]<=pivot) cnt++;
    }

    int pivotIndex = s+cnt;
    swap(arr[pivotIndex], arr[s]);

    int i=s, j = e;
    while(i<pivotIndex && j>pivotIndex){
        // jab tak arr[i] pivot se chota aata h aur arr[j] pivot se bada tab tak i++ and j--
        while(arr[i]<=pivot){
            i++;
        }   
        while(arr[j]>pivot){
            j--;
        }
        // cout<<i<<" "<<j<<endl;
        
        // ab aisi condition aa gayi hai ki ya to i aur j pivot tak pahauch gaye hn ya phir swap karna padega kyuki i pivot se bada h aur j pivot se chota h
        if(i<pivotIndex && j>pivotIndex )
            swap(arr[i++], arr[j--]);   
    }


    return pivotIndex;
}

void quick_sort(int arr[], int s, int e){
    //base case
    if(s>=e) return ;

    int p = partition(arr, s, e);//isse pivot ke left mein pivot se chote aur pivot ke right mein pivot se bade elements aa jayenge
    
    //recursive call - now call quick sort for both the halves.
    quick_sort(arr, s, p-1);
    quick_sort(arr, p+1, e);
}

int main(){
    int n;
    cout<<"enter size: ";
    cin>>n;
    int *a = new int[n];
    cout<<"enter the elements: "<<endl;
    for(int i=0; i<n; i++){
        cin>>a[i];
    }

    cout<<"before: ";
    print_arr(a, n);
    
    quick_sort(a, 0, n-1);

    print_arr(a, n);


    return 0;
}