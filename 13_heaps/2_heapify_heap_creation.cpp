//The use of heapify function is to place a node to its right place in the heap.

//We will start from the end and will check wether the node is in right place or not by checking its
//children.

//PROPERTY HEAP=> Now heap has a special property, that the nodes from index(array) n/2+1 to n are all 
//                  LEAF NODES.
//we we only need to check from n/2 to 0(reverse) index as leaf nodes are already in the form of a heap.
#include<iostream>
using namespace std;

class maxheap{
    public:
        int arr[100];
        int size;

        maxheap(){
            size=0;
            arr[0] = -1;
        }

    void insert(int val){
        size = size+1;
        int index = size;
        arr[index] = val;

        //now compare with the parent
        while(index>1){
            if( arr[index] > arr[index/2] ){
                swap(arr[index], arr[index/2]); 
                index/=2;
            }else return;
        }
    }

    void print(){
        for(int i=1; i<=size; i++){
            cout<<arr[i]<<" ";
        }cout<<endl;  
    }

};

//recursive method.
void heapify(int arr[], int n, int i){
    //we will see which is largest from left and right and will replace from the larger from both
    //child.
    int largest = i;
    int left = 2*i;
    int right = 2*i+1;

    if(left<=n && arr[left]>arr[largest]){
        largest = left;
    }
    if(right<=n && arr[right]>arr[largest]){
        largest = right;
    }
    
    //if i has changed than swap and do for further
    if(i!=largest){
        swap(arr[i], arr[largest]);
        //rc
        //call heapify for the next i for checking down
        heapify(arr, n, largest);
    }

}
//tc: O(log(n));

void printArr(int arr[], int n){
    for(int i=1; i<=n; i++){
        cout<<arr[i]<<" ";
    }cout<<endl;
}

int main(){

    //lets make a random array.
    //and then we will apply heapify on it for every node from reverse n/2 to 0th index.
    maxheap h1;
    int arr[6] = {-1,50,55,53,52,54}; //pehla element to -1 hota he hai.
    int n = 5;//size

    cout<<"before: ";
    printArr(arr, n);
    
    //traversing - build heap O(N) mein hota hai. kaise?? aise toh o(logn) lag rha hai.
    for(int i=n/2; i>0; i--){

        // cout<<"checking for "<<arr[i]<<endl;

        heapify(arr, n, i);
    }
    cout<<"after heapify: ";
    printArr(arr, n);

}

//try here: https://www.codingninjas.com/codestudio/problems/build-min-heap_1171167?leftPanelTab=0


//TO SUM UP:
/*
TC: insertion in heap: O(log(N)).
    deletion in heap: O(log(N)).
    building a heap: O(N).
*/