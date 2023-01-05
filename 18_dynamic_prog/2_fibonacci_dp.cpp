
//steps in dp:
// A) top down approach.
// since here we have a single parameter needed for recursive call so, we will only use a single array(1D).
// 1) make dp(array/map/table as per requirement) and initialize it.
// 2) check if soln exist in dp after base case
// 3) if not then save the solution returned , in dp.

#include <iostream>
using namespace std;

//This is a 1D dp problem as the number of states changing in the funciton parameter is 1.

//make it as a global variable.
//since n = 8, so at max we will need fib(7) as i 0 se n-1 tak chal rha h.
//for fib(7). we may need to store the subproblem soln of 0 to 7.
//so make a dp of size 8.

// int dp[8];

// int fib(int i){
//     if(i==0) return 0;
//     if(i==1) return 1;

//     if(dp[i]!=-1) return dp[i];

//     return dp[i] = fib(i-1)+fib(i-2);
// }

// int main(){

//     //print fibonacci.
//     int n = 8;
    
//     //initialize all with -1;
//     for(int i=0; i<8; i++){
//         dp[i] = -1;
//     }
//     for(int i=0; i<n; i++){
//         cout<<fib(i)<<" ";
//     }

//     return 0;
// }

//time complexity : O(N).
//space complexity: O(N) for dp + O(N) for recursive call stack.


//B) BOTTOM UP APPROACH
// for tabulation - steps
//1) check base case.
//2) set initial values of dp for base case.
//3) make a loop and traverse from base case to our n by using that dp[initial values].

// int main(){
//     int dp[8];

//     //to find the 7th term in the dp.
//     int n = 7;
//     //1) check base case
//     // if n==1 then return 1 and if n==0 return 0
//     //2) set initial values in the dp
//     dp[0] = 0; 
//     dp[1] = 1;

//     //3) traverse from next of base case towards the end
//     for(int i=2; i<=n; i++){
//         dp[i] = dp[i-1]+dp[i-2];
//     }

//     cout<<dp[n]<<endl;

//     return 0;

// }

//time complexity: O(N).
//space complexity : still O(N) for dp arr but better than top down approach as do not have recursive call stack


//C) SPACE OPTIMIZATION:
// here a bit of brainstorming is required.
// as we can see in the for loop that at every step only two element of the dp array are required at a time.
// so what if we just make two variables, namely: prev1 and prev2;


int main(){

    //to find the 7th term in the dp.
    int n = 7;
    //1) check base case
    // if n==1 then return 1 and if n==0 return 0
    //2) set initial values in the pointers or variables
    int prev1 = 1;
    int prev2 = 0;

    //prev2+prev1 = nextElement.

    //3) traverse from next of base case towards the end
    int curr;
    for(int i=2; i<=n; i++){
        curr = prev1+prev2;
        prev2 = prev1;
        prev1 = curr;
    }
    
    if(n<=1) cout<< n;
    else cout<<curr<<endl;

    return 0;

}
