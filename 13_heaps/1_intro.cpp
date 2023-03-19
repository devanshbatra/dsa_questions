#include<iostream>

using namespace std;
//what is heap?
/*
Heap is a complete binary tree that comes with a heap order property.

complete binary tree - A complete binary tree is a binary tree in which all the levels are completely 
                        filled except possibly the lowest one, which is filled from the left.
                        see google images for more interpretation.
                        You can try this question.
                        https://leetcode.com/problems/check-completeness-of-a-binary-tree/description/

Now there are two types of heap
1) min heap - here we have the root as minimum element and at every node its children are greater than 
              the root value.

2) max heap - here we have the root as the maximum element and at every node its children are smaller than
                the root value.

*/

//A property
/*
Heap tree has a property that it is implemented through an array and processed by a tree(in back)
Actually we do not create a tree but a complete binary tree is maintained using an array. 
 so the 
//  The left child of arr[i] = arr[2*i]
//  The right child of arr[i] = arr[(2*i)+1]
//  This is for 1 based indexing.

//  The left child of arr[i] = arr[(2*i)+1]
//  The right child of arr[i] = arr[(2*i)+2]
//  This is for 0 based indexing which is followed in general.

RATNE KI JAROORAT NHI HAI, EK COMPLETE BIN TREE BANAKE DEKH LO.

 kuch jagah 0 based hoti hai to inme ek ek add ho jayega.
    see ss
INSERTION IN MAX HEAP.
Whenever get any element to push any element then we push it at the end of the index of the array
as well as the tree.
Now we will compare it with its parent which is at i/2 index. if it is greater then swap with the parent
and again check with the new parent iteratively until the parent is smaller or end of arr.


*/



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
    //time complexity for insertion is: O(logn);


    //HEAP DELETION- 
    //we have to delete the root node from the heap.
    //steps:
    //1) swap the last node with the root node.
    //2) delete the last node.
    //3) now place the new root node to its correct position by comparing with children 
    //   by swapping with the max of the two children.

    void deleteFromHeap(){
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

        }//complexity O(logn)

    void print(){
        for(int i=1; i<=size; i++){
            cout<<arr[i]<<" ";
        }cout<<endl;  
    }

};


int main(){

    maxheap h1;
    h1.insert(54);
    h1.insert(50);
    h1.insert(53);
    h1.insert(55);
    h1.insert(52);

    h1.print();


    h1.deleteFromHeap();

    h1.print();

    return 0;
}