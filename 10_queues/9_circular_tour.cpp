#include <iostream>

using namespace std;

/*Circular tour: we are given n petrol pumps containing amount of petrol and dist to next petrol pump
now we need to choose a starting point such that we can make a round trip by coming to each petrol pump.

https://practice.geeksforgeeks.org/problems/circular-tour/1#

approach 1(brute force - naive approach) - we will loop through each petrol pump and see if it can be the
starting point by trying to complete the path . Time complexity : O(n^2).

approach 2(efficient): we can use the concept of two pointers and queue to solve this . Like in queue we 
use two pointers front and rear here also we will use queue but instead of using an additional queue we 
will apply the pointer to the array itself.
- front and rear will point to 0 at first.
- now we analyse a balance petrol (balance = 0 initial), balance(at each step) = balance+ (petrol-dist).
- if balance>=0 then going to next node is possible so rear = rear+1;
- else if balance is neg. then the front needs to be relocated front = rear+1 and rear = rear+1 and reset bal = 0
    because agar front se rear tak nhi pohocha to rear se pehle pehle agar kahi se start karenge to to nhi he phochega
- now if front and rear again meet then this means it is possible to complete the path with front index
        as starting point.
- front and rear can also go round the cycle like rear = (rear+1)%n.
- else return -1.
//this implementation you can find on : https://leetcode.com/problems/gas-station/description/
//BUT DON'T SEE IT.


approach 3(most optimised): we will use the same concept of approach 2 but instead of revisiting the cycle 
again we will store the value of the negative balances(as deficit ) which we got in the first iteration.
also we calculate the net balance front the first iteration.
if(netBalance + deficit >= 0) then return front as this means now the balance is sufficient to commute the nodes
else return -1 as all fronts are already tried and no one gives this much netbalance at last which could 
neutralize the deficit.

*/

//approach 3 written here:

struct petrolPump{
    int petrol;
    int distance;
};

int tour(petrolPump p[],int n)
{
    
    int front = 0;
    int rear = 0; 
    int balance  = 0;
    int deficit  = 0;
    
    for(rear=0; rear<n; rear++){
        int pet = p[rear].petrol;
        int dist = p[rear].distance;
        
        balance+=pet-dist;
        // cout<<"balance: "<<balance<<endl;
        
        //if balance>0 ka apne app chalta rahe ga as rear will keep on increasing
        //but if balance is less than zero then we need to put front=rear+1 and also add up the deficit.
        if(balance<0){
            front = rear+1;
            deficit = deficit+balance;
            balance = 0; //remember to update the balance as now we will have a new start.
            // cout<<"deficit increased: "<<deficit<<endl;
        }
    }
    
    
    //now either the net balance is greater than deficit - in than case we will be able to complete the circle with the selected front.
    //or balance is smaller than deficit - that means the front has tried all the nodes and there is no possibility to complete the circle.
    //so in that case return -1.
    if(balance+deficit>=0) return front;
    else return -1;
   
}
