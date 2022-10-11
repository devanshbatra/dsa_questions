// You have k lists of sorted integers in non-decreasing order.
// Find the smallest range that includes at least one number from each of the k lists.

//approach: 1 - we will find all the ranges and store the range which has the lowest difference.
                //this approach will take O((n*k)^2) time complexity.

/*
approach 2 - we will take the first k elements of all the lists
            now to make a range we have two conditions: 1) range should include atleast one element from each
            list 2) range should be minimum(diff between min and max should be min).

            steps:
            1) select first elements of all k lists and find their min and max without using heap(heap agli app
                mein aayega na).
            2) find min and max from them, now we will get a range and it satisfies the first condition already.
            3) now to reduce the difference the min and max element of the heap we can increase the min or 
                decrease the max. decrease the max is not possible as it will violate the first condition.
                so we will increase the min by popping the min and pushing the next element to the min.
                iteratively we will do that and at every step we will compare our difference with the prev.
                difference if less then update the ans range.
            tc: O(k) + O(nk^2).
*/

/*
approach 3 - same uppar wali approach ki tarah he karenge but kyoki hum min ko increase kar skte hain but
             decrease nhi kar skte so,
             we will make track of mini by using min heap as we have to increase the mini.
             but for the max, we will find the maximum element initially while we would be insert the first
            k elements in min heap and further we will just use a variable and if the new var is greater than
            that maxi then we would update that maxi.
            and at every step we also will update the minimum range and then update our range ans.

            TC:     
             
*/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Node{
    public:
        int data;
        int row;
        int col;
        Node(int d, int a, int b){
            data = d;
            row = a;
            col = b;
        }
};

class comparator{
    public:
        bool operator()(Node* a, Node* b){
            return a->data > b->data;
        }
};

class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        //1) create a custom min heap.
        priority_queue<Node*, vector<Node*>, comparator> minheap;
        
        //2) add first element of each subarray to each heap
        int maxi = INT_MIN;
        int k = nums.size();
        for(int i=0; i<k; i++){
            Node* newnode = new Node(nums[i][0], i, 0);
            maxi = max(maxi, nums[i][0]);
            minheap.push(newnode);
        }
        
        // cout<<minheap.top()->data<<" "<<maxi;/
        int ansMin = minheap.top()->data;
        int ansMax = maxi;
        int rangeDiff = INT_MAX;
        while(minheap.size()>1){
            //find min and max
            Node* minNode = minheap.top();
            int mini = minNode->data;
            minheap.pop();
            // cout<<"mini: "<<mini<<" and maxi: "<<maxi<<" "<<abs(maxi-mini)<<" ";
            //find range diff
            if( rangeDiff > abs(maxi-mini)){
                rangeDiff = abs(maxi-mini);
                ansMin = mini;
                ansMax = maxi;
            }
            // cout<<"and updated range diff is: "<<rangeDiff<<endl;
            
            //update maxi and mini
            if((minNode->col)+1 < nums[minNode->row].size() ){
                Node* newnode = new Node(nums[minNode->row][(minNode->col)+1], minNode->row, (minNode->col)+1);
                minheap.push(newnode);
                maxi = max(maxi, nums[minNode->row][(minNode->col)+1]);
            }else break;
            
            
        }
        
        vector<int> ans;
        ans.push_back(ansMin);
        ans.push_back(ansMax);
        return ans;
        
    }
};