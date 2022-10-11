#include <iostream>
#include <queue>
using namespace std;


//FIND MEDIAN IN AN INPUT DATA STREAM
// we will be provided with a input stream of data (integers).
// now we have to tell the median of all the numbers uptill now everytime a new element is added.

/*
approach 1: first you have to tell this approach and its disadvantages, don't skip directly to the second appr.
    can we can any sorting algorithm and sort the array everytime a new element is added. but it is not
    feasible as for n element we would sort TC: would be n^2log(n).
    But if you remember, there is a sorting algorithm INSERTION SORT in which we maintain a sorted array
    and everytime a new element is added.
    if we also do that and maintain a sorted array then finding median would be easy as:
        median for odd number of elements: n/2;
        median for even number of elements: (arr[n/2]+arr[(n/2)+1])/2 i.e avg. of middle two elements.

    
    but this approach also take worst tc of O(N^2).

*/

/*
approach 2: 
    We can do this question using heaps.
    We know that for odd arrays the median would be just the middle element
    and for even it is the avg of two middle elements

    if we divide the array into two, [_ _ _, _ _] - odd divided into two - if first part is greater than median
    would be the last element of the first subarray. and since it would be maintain in sorted order so,
    the maxheap.top() will give the ans. means greater part se he median aayega

    if array is even , [_ _ _, _ _ _] - even divided into two- now the median would be the avg of the
    last element of the first subArray and the first element of the second subarray.
    

    so basically we need to maintain maxheap for first part and minheap for the second part.
    that too with a size difference of 1.

    //jab bhi koi naya element aayega tab dekhi jayegi ki kis heap mein push karna hai. 
    //TC: we are pushing in heap for n element so n(logn).

    //also to create cases, an easy approach (aise he) would be to use signam func. 
    //signam(a, b) returns 0 if a==b, 1 if a>b, -1 if a<b.
*/

class MedianFinder {
public:
    vector<int> v;
    priority_queue<double, vector<double>, greater<double>> minheap;
    priority_queue<double> maxheap;
    double median;
    
    
    int signam(int a, int b){
        if(a==b) return 0;
        else if(a>b) return 1;
        else return -1;
    }
    
    MedianFinder() {
        median = INT_MAX;
    }
    
    void addNum(int num) {
        
        switch(signam(maxheap.size(), minheap.size())){
            case 0: //both are of same size add in any
                if(num > median){
                    minheap.push(num);
                    median = minheap.top();
                }
                else{
                    maxheap.push(num);
                    median = maxheap.top();
                }
                break;
            
            case 1: //left is of greater size
                if(num > median){
                    minheap.push(num);
                    median = (maxheap.top() + minheap.top())/2;
                }
                else{
                    //if num is smaller than median then we first need to shift one element
                    //from
                    minheap.push(maxheap.top());
                    maxheap.pop();
                    maxheap.push(num);
                    median = (maxheap.top()+minheap.top())/2;
                    cout<<endl;
                }
                break;
                
            case -1:
                if(num>median){
                    maxheap.push(minheap.top());
                    minheap.pop();
                    
                    minheap.push(num);
                    median = (maxheap.top()+minheap.top())/2;
                    
                }
                else{
                    maxheap.push(num);
                    median = (maxheap.top()+minheap.top())/2;
                }
                break;

        }
        
    }
    
    double findMedian() {
        return median;
    }
};
