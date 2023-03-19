// https://leetcode.com/problems/minimum-time-to-complete-all-tasks/description/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//we would do that greedily.
//sort the tasks according to their end time.
//so, according to our question we must greedily fall into our overlaps.
//and if we sort according to end time.
//then we would try to first complete our tasks in already on slots but if not suffient.
//then the left slots would be filled at the end of the range.
//because we know that there is a higher probability of having an overlap near the end of the range.
static bool comparator(vector<int>& a, vector<int>& b){
    return a[1]<b[1];
}

int findMinimumTime(vector<vector<int>>& tasks) {
    

    vector<bool> available(2001, false);
    
    sort(tasks.begin(), tasks.end(), comparator);

    int t = tasks.size();

    int openSlots = 0;

    for(int i=0; i<t; i++){

        int s = tasks[i][0];
        int e = tasks[i][1];
        int dur = tasks[i][2];

        //check available slots first
        for(int j=s; j<=e; j++){
            if(available[j]) dur--;
        }

        //if still left start filling from end
        int t = e;
        while(dur>0 ){
            if(available[t]==false){ //to understand this condition see this test case: [[2,13,2],[6,18,5],[2,13,3]]
                dur--;
                available[t] = true;
                openSlots++;
            }
            t--;
        }

    }

    return openSlots;



}