#include<iostream>
/*
in factorial solution of a bigger problem is dependent on the solution of a smaller problem
we need a recursive call + a base case.

**base case mein return likhna mandatory hai.   
** agar base case nhi likha toh - segmentation fault aa jayega
segmentation fault - Core Dump/Segmentation fault is a specific kind of error caused by accessing memory
 that “does not belong to you.”

so - 
recursive function(){
    base case
    some processing             TAIL RECURSION 
    recursive call
}

recursive function(){
    base case
    recursive call             HEAD RECURSION 
    some processing
}
*/
/*
3! = 3 X 2!
2! = 2 X 1!
1! = 1 X 0! (aur 0 ka factorial hume pata h) - ruk jao base case mil gaya.

so rec func is : n*f(n-1) 

*/
using namespace std;

int factorial(int n){
    if(n==0) return 1;

    return n * factorial(n-1);
}

void printNum_head(int n){
    //base case
    if(n==0) return;

    //recursive call
    printNum_head(n-1);

    // processing 
    cout<<n<<" ";

//isme pehle he recursive call maar di
//so print tab hoga jb saari recursive calls khatam ho jayegi aur base case aayega.
//so print 1 se hoga as it would be at the top of the function stack at that time.
}
void printNum_tail(int n){
    //base case
    if(n==0) return;

    // processing 
    cout<<n<<" ";

    //recursive call
    printNum_head(n-1);

// isme processing (printing) he pehle kar di to 5 pehle he print ho jayega, uske baad 4,3,2,1.

}

int main(){
    int n;
    cout<<"Enter the number for factorial: ";
    cin>>n;
    cout<<factorial(n);

    //about tail and head recursion 
    // printing numbers from 1 to 5
    printNum_head(5);
    cout<<endl;
    printNum_tail(5);

    // so the power of head and tail recursion is that we can reverse the order of our solution.
    return 0;
}