// You have been given a number of stairs. Initially, you are at the 0th stair, and you need to reach the
//  Nth stair. Each time you can either climb one step or two steps. You are supposed to return the 
// number of distinct ways in which you can climb from the 0th step to Nth step.

// you can se ss for exp

#include <iostream>
using namespace std;

int countDistinctWayToClimbStair(long long n)
{
   //base case
	if(n<0) return 0;//base mein koi seedhi nhi h so 0 tareeka
	if(n==0) return 1;// 0th se 0th pr aane ka tareeka 1 he h, koodo aur wapas
	
// 	recursive relation
	return countDistinctWayToClimbStair(n-1)+countDistinctWayToClimbStair(n-2);
}


int main(){
    int n=5;

    cout<<"The number of ways are: "<<countDistinctWayToClimbStair(n);
    

    return 0;
}