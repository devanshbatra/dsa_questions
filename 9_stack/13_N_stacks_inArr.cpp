#include<iostream>
#include<stack>

using namespace std;

/*
https://www.codingninjas.com/codestudio/problems/n-stacks-in-an-array_1164271?leftPanelTab=0
N stacks - we have to fit N number of stacks in an array. like we fitted 2 stacks in an array.

approach1: We can partition the whole array into N parts and allocate each part to each stack.
            but its drawback is that there is a lot of wastage in space as if any stack is full
            then we cannot add to it even if all others are empty.

approach 2: This is a very efficient approach , here we will use each and every free space to allocate elements
            to the stack and there will be no order of ordering the stack elements, an array named next[] will
            be maintained to store which element is after this element.

            so, in this approach we need to create 4 different variables
            1) arr[] the original array which has to accomodate N stacks.

            2) top[] array: It will store the index of top(in the original array) of each stack.
                        Its size will be N (equal to the number of stacks).

            3) next[] array: this can store two different things
                            i> point to the next element after stack top.
                            ii> point to the next free space available.
            --->How does we know what it is representing : 
                if that index of the original array (for which we are concerned) already contains an element
                then next will represent the next element in the stack (jo uske neeche present hai).
                otherwise if that index is empty, then it represents the next free space available.

            4) freeSpot - this denotes the index which is free to use next.

We are using all these structures to just store integer stacks in an array ?
--> No, we are using integer stacks for just easing the understanding, otherwise this technique is usefull
    when we need to accomodate complex objects within an array. And these approaches are also used in OS.

CONSTRUCTOR: first we will intitialize the structures.
            1> All the elements of top will be -1 as no element exist in any of the stack
            2> next will be like representing the next free spaces.
                next[0] - 1, next[1] - 2, next[2] - 3 and so on... last wale ka = -1
            3> freePoint will be 0 ( as this is the first available free space ).

PUSH OPERATION: 
push(10, 1) -  push data - 10 on stack 1
steps:
    1- //find index
        int index = freespot;
    2- //update the freespot (by seeing the next empty element from the next array)
        freespot = next[index];
    3- //insert in array
        arr[index] = 10;
    //now we can either update the top for stack 1 ( as one element is added ) or we can update the next[]
    as we have to denote the next present element for index 0. but we will update next first as next will
    be found out using the previous top of that array ( arre bhai jo pehle top tha wo he to next hoga).
    4- //update next
        next[index] = top[1st stack <i.e. if stack number = m -> (m-1)]//m-1 as 1st stack will be at 0th index(0 based indexing).
    
    5- //update the top[] - now the stack one has its top at index 0 of original array.
        top[1] = index;
    
POP OPERATION
    steps = all steps will be reversed as in push operation just do up to down and lhs to rhs.


*/

class Nstack{

    int* arr;
    int * top;
    int * next;
    int freespot;

    int n, s;//number of stacks and size of array

    public:
        //constructor
        Nstack(int N, int S){
            this->n = N;//number of stacks
            this->s = S;// size of array
            arr = new int[s];
            top = new int[n];
            next = new int[s];
            freespot = 0;

            //top initialize
            for(int i=0; i<n; i++){
                top[i] = -1;
            }
            //or we can do this by using the memset function provided by cpp - memset(jisme daalna hai, jo dalna hai, kya size banana hai);
            // memset(top, -1, n);

            //next initializse
            for(int i=0; i<s; i++){
                next[i] = i+1;
            }
            //update last index to -1
            next[s-1]= -1;
        }

        bool push(int x, int m){ //x is the data and m is the stack number to which data has to be entered.
            //check for overflow 
            if(freespot==-1){
                cout<<"could not insert , stack overflow"<<endl;
                return false;
            }

            //steps followed
            //find index
            int index = freespot;

            //update the freespot
            freespot = next[index];

            //insert in array
            arr[index] = x;

            //update the next[]
            next[index] = top[m-1]; // as 1st stack will represent the 0th position.

            //update the top[]
            top[m-1] = index;

            return true;
        }

        int pop(int m){ //m represent the stack number, pop return the popped element and -1 if underflow.

            //checking stack underflow - check top of the indicated stack
            if(top[m-1]==-1) return -1;

            //steps - exactly reverse the steps of push (up to down and lhs to rhs).
            //store index
            int index = top[m-1]; //index will be present at top array

            top[m-1] = next[index];//now our next top will be the element next to it .

            next[index] = freespot; //now our next[] for this index should represent the next available space- assign freespot

            freespot = index; //now this index is removed, so declare it as the new freespot.

            return arr[index];// return the popped element. as it is still present in the array(wo alag baat hai ki can't be used).


        }


};

//time complexity : for push and pop we are doing in constant time so- O(1)
//space complexity: O(s+n) used arr, next and top.

