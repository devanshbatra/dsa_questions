#include <iostream>
using namespace std;


class Heap{
    public:
        int size;
        int arr[100];

        Heap(){
            size = 0;
            arr[0] = -1;
        }

        void insert(int num){
            size = size+1;
            int index =size;
            arr[index] = num;

            //now iteratively compare this new element with its parents.
            while(index>1){
                if(arr[index]>arr[index/2]){
                    swap(arr[index], arr[index/2]);
                    index/=2;
                }else break;
            }
        }

        int getFront(){
            return arr[1];
        }

        void deleteRoot(){
            //swap front/root with the last element
            arr[1] = arr[size];
            size--;

            //now place this new root at its adequate place by comparing with chilren
            int index = 1;
            int maxIndex = index;
            while(index<=size){
                if( index*2<=size && arr[maxIndex]<arr[index*2]){
                    maxIndex = index*2;
                }
                if( (index*2)+1<=size && arr[maxIndex]<arr[index*2+1]){
                    maxIndex = index*2+1;
                }

                if(maxIndex!=index){
                    swap(arr[index], arr[maxIndex]);
                    index = maxIndex;
                }
                else break;
            }

        }

};


void heapify(int arr[], int i, int n){
    int left = i*2+1;
    int right = i*2+2;

    int maxi = i;

    if(left<n && arr[maxi]<arr[left]){
        maxi = left;
    }
    if(right<n && arr[maxi]<arr[right]){
        maxi = right;
    }

    if(maxi!=i){
        swap(arr[maxi], arr[i]);
        heapify(arr, maxi, n);
    }

}

void printArr(int arr[], int n){
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}


int main(){
    
    int arr[10] = {7, 5, 2, 8, 3, 0, 98, 12, 34, 54};
    int n = 10;

    for(int i=n/2-1; i>=0; i--){
        heapify(arr, i, n);
    }
    
    printArr(arr, n);

}