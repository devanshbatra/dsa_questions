#include <iostream>
#include <queue>
#include <vector>


using namespace std;

void solve(vector<int>& cards, int n){
    priority_queue<int> maxheap;
    long long power = 0;
    for(int i=0; i<n; i++){
        int curr = cards[i];
        if(curr==0 ){
            if(maxheap.size()>0){
                power+=maxheap.top();
                maxheap.pop();
            }
        }
        else{
            maxheap.push(curr);
        }
    }

    cout<<power<<endl;


}

int main(){
    int t;
    cin>>t;

    for(int i=0; i<t; i++){
        int n;
        cin>>n;
        vector<int> cards;
        for(int i=0; i<n; i++){
            int ele;
            cin>>ele;
            cards.push_back(ele);
        }

        solve(cards, n);

    }


    return 0;
}