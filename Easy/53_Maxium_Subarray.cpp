// Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.

// Example:

// Input: [-2,1,-3,4,-1,2,1,-5,4],
// Output: 6
// Explanation: [4,-1,2,1] has the largest sum = 6.
// Follow up:

// If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, which is more subtle.

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

//O(n)解法，i位置结尾的子串，要么为maxsub(i-1),要么是maxsub(i-1)+x[i],来源编程珠矶第八章
//处理技巧，如果当期位置最大子串不超过上一位置，则将当前位置最大子串置零
//问题：错误将max 当作 max_element使用
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int i=0,len=nums.size();
        if(len==0)
            return 0;
        if(len==1)
            return nums[0];
        int maxcurpos=0,maxglobal=0;
        for(;i<len;i++) {
            maxcurpos=max(maxcurpos+nums[i],0);
            maxglobal=max(maxglobal,maxcurpos);
        }       
        return (maxglobal==0) ? *max_element(nums.begin(),nums.end()) : maxglobal;
    }
};

int main(){
    Solution solu;
    vector<int> nums={-2,-1};
    cout<<solu.maxSubArray(nums);
}