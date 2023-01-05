// https://leetcode.com/problems/russian-doll-envelopes/description/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
// approach :

    //ab ek envelop doosre mein tabhi fit ho paayega jab uska w aur h dono he chote ho.
    // ham ya to width ya height , ek cheez mein he to compare / sort kar sakte hain, 
    // dono ko kaise saath mein handle karen.
    // so what we will do ham 2d array ko width ke according sort kar lenge.
    // aur heights may be in random order hongi. so hum ye pata krne ke liye ki kitne envelopes ek doosre mein 
    // fit ho jaayenge , heights mein LIS(longest increaseing subsequence ) laga denge.

    //case: ab ek case hai jisme width same hai aur height alag alag hai.
    // so uss case mein hum heights ke decreasing order mein laga denge.
    // like [5, 8][5, 4].
    // kyunki ham nhi chahate ki do 5 wale include ho jaaye.(because we are using dp+binSearch approach).
    // so height=8 wala pehle rhega to longest increasing subsequence mein 4 ko to dekha he nhi jaayega, agar 8 liya jaata hai.

    static bool comparator(vector<int> &a, vector<int> &b){
        if(a[0]!=b[0]) return a[0]<b[0];
        else return a[1]>b[1];
    }

    void findNGE(vector<int>& seq, int s, int e, int key, int & ans){
        if(s>e) return;

        //rc
        int mid = s+(e-s)/2;
        if(seq[mid]>=key){
            //left
            ans = mid;
            findNGE(seq, s, mid-1, key, ans);
        }else{
            //right
            findNGE(seq, mid+1, e, key, ans);
        }
    }

    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end(), comparator);
        int n = envelopes.size();

        //applying lis on heights
        vector<int> seq;
        for(int i=0; i<n; i++){
            int height = envelopes[i][1];
            //if empty or strictly greater than the last element than directly push_back.
            if(seq.size()==0 || height>seq[seq.size()-1]) seq.push_back(height);
            else{
                //replace with next greater eleemtn
                int nextGreaterIndex;
                findNGE(seq, 0, seq.size()-1, height, nextGreaterIndex);
                seq[nextGreaterIndex] = height;
            }

        }


        return seq.size();
    }