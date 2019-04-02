// Given a non-empty array of integers, every element appears twice except for one. 
// Find that single one.

// Note:

// Your algorithm should have a linear runtime complexity. 
// Could you implement it without using extra memory?

// Example 1:

// Input: [2,2,1]
// Output: 1
// Example 2:

// Input: [4,1,2,1,2]
// Output: 4

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
//先排序再寻找，对数阶复杂度
//双重循环寻找O(n^2)
// class Solution {
// public:
//     int singleNumber(vector<int>& nums) {
//         sort(nums.begin(),nums.end());
//         for(auto item:nums)
//             cout<<item<<endl;
//         int i=0,len=nums.size();
//         while(1){
//             if(i==len-1||nums[i]!=nums[i+1])
//                 return nums[i];
//             i+=2;
//         }
//     }
// };

//异或做法，同一个数异或两次，结果仍然为自己
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int one=0,len=nums.size();
        for(int i=0;i<len;++i)
            one^=nums[i];
        return one;
    }
};

int main(){
    Solution solu;
    vector<int> nums={4,1,2,1,2};
    cout<<solu.singleNumber(nums);
    return 0;
}