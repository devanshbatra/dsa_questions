#include <iostream>
#include <vector>
using namespace std;
// book allocation problem
// https://www.codingninjas.com/codestudio/problems/allocate-books_1090540?leftPanelTab=1


// my solution for isPossibleSolution 100% fast    
bool isPossibleSolution(vector<int> a, int n, int m, int mid){
    int pageSum = 0, i = 0;
    while (m > 0 && i<n ){
        pageSum = 0; //update page sum for the new child
        while (i < n){
            if (pageSum + a[i] > mid){
                m--;
                break;
            }
            else{
                pageSum += a[i];
                i++;
            }
        }
    }
    if (i == n){
        return true;
    }
    else{
        return false;
    }
}

// babbar soln also 100% fast(but follow my solution)
bool isPossibleSolution_babb(vector<int> a, int n, int m, int mid){
    int pageSum = 0, studCount = 1;
    for(int i=0; i<n; i++){
        if(pageSum+a[i]<=mid){
            pageSum+=a[i];
        }
        else{
            studCount++;
            if(studCount>m || a[i]>mid){
                return false;
            }
            pageSum = a[i];//update pagesum for the new child
        }
    }
    return true;
    
}

int binarySearchAlgo(vector<int> a, int n, int sum, int m)
{
    int h = sum, l = 0;
    int mid = l + (h - l) / 2;
    int ans = -1;
    while (l <= h)
    {
        if (isPossibleSolution_babb(a, n, m, mid))
        {
            // go to left and store ans
            h = mid - 1;
            ans = mid;
        }
        else
        {
            // go to right for a bigger number
            l = mid + 1;
        }
        mid=l+(h-l)/2;
    }
    return ans;
}

int main()
{
    cout << "Enter the number of books: " << endl;
    int n;
    cin >> n;
    cout << "Enter the elements: " << endl;
    vector<int> books;
    for (int i = 0; i < n; i++)
    {
        int el;
        cin >> el;
        books.push_back(el);
    }
    int m;
    cout << "Enter the number of students: ";
    cin >> m;

    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += books[i];
    }

    cout<<binarySearchAlgo(books, n, sum, m);
    return 0;
}