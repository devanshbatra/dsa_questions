#include <iostream>
using namespace std;

/*
In heap sort we would be given a random array and we would be asked to sort it.
Steps:
1) build a max heap using that array by calling heapify from n/2-1 to 0(as it is 0 based indexing)
2) now steps to sort the array. - BADE ELEMENT KO USKI SAHI JAGAH PAR LAGATE JAO BAS AUR HAR STEP KE BAAD HEAPIFY CALL KAR DO.
    i) swap arr[0] and arr[size] - take size = n-1 initially
    ii) size--;
    iii) place that arr[0] to its right position. using heapify(arr, size+1, 0); used size+1 since we 
    are taking 0 based indexing in heapify.

    practise on this: https://practice.geeksforgeeks.org/problems/heap-sort/1

    give a dry run of this problem: 8 6 3 9 1 5 4 0 12 14
*/

class Solution
{
    public:
    
    void printArr(int arr[], int n){
        for(int i=0; i<n; i++){
            cout<<arr[i]<<" ";
        }cout<<endl;
    }
    
    //Heapify function to maintain heap property.
    void heapify(int arr[], int n, int i)  
    {
      // Your Code Here
      int largest = i;
      int left = 2*i+1;
      int right = 2*i+2;
      
      if(left<n && arr[left]>arr[largest]){
          largest = left;
      }
      if(right<n && arr[right]>arr[largest]){
          largest = right;
      }
      
      if(i!=largest){
          swap(arr[largest], arr[i]);
        //   printArr(arr, n);
          heapify(arr, n, largest);
      }
      
    }

    public:
    //Function to build a Heap from array.
    void buildHeap(int arr[], int n)  
    { 
    // Your Code Here
    for(int i=n/2-1; i>=0; i--){
        heapify(arr, n, i);
    }
    
    }

    
    public:
    //Function to sort an array using Heap Sort.
    void heapSort(int arr[], int n)
    {
        //heap sort is a two step process
        //first we will build a heap out of this array.
        buildHeap(arr, n);
        // printArr(arr, n);
        // cout<<"done"<<endl;
        
        //now steps
        int size = n-1;
        while(size>0){
            
            // 1) swap 1st element with the element at size
            swap(arr[0], arr[size]);
            size--;
            //we placed the small element on top
            //2) now rearrange this element
            heapify(arr, size+1, 0);
            
            
        }
        
    }
};

//Time complexity: build heap - log(n). , traversing each element and swapping with first element O(n),
// and heapify -  O(log(N)).
//Total TC: log(n) + nlog(n) ==> nlog(N).