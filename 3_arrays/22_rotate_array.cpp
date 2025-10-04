//https://leetcode.com/problems/rotate-array/
//1. One brute force method would be to use an extra array.
//2. 2nd brute force would be to jump each element one step at a time to the right and moving the last element to the 0th index
//during every jump. This would take O(n*k) complexity.

//3. 3rd method implemented below. Without using extra space and using around O(n) complexity.


class Solution {
public:

    void swap(int* a, int* b){
        int temp = *a;
        *a = *b;
        *b = temp;
    }

    void reverse(vector<int>& nums, int s, int e){
        int n = nums.size();
        while(s<e){
            swap(&nums[s++], &nums[e--]);
        }
    }

    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k%n;
        
        reverse(nums, 0, n-k-1);
        reverse(nums, n-k, n-1);
        reverse(nums, 0, n-1);

    }
};