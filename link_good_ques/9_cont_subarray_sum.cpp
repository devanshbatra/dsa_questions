// https://leetcode.com/problems/continuous-subarray-sum/submissions/

/*
Given an integer array nums and an integer k, return true if nums has a good subarray or false otherwise.

A good subarray is a subarray where:

    its length is at least two, and
    the sum of the elements of the subarray is a multiple of k.

*/

//This question may seem to be of dp but it is not and can be easily solved in O(n) time complexity.
// Our approach Uses hash table and prefix sum(matlab ek sum ka array banana, yahan array nhi banaya but..)
// technique.
//This approach is simple with some crucial edge cases but cannot be thought if not done before.
//We just create a hashmap and then see where the remainder is coming same for the prefix sum array.