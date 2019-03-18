// Given an array of integers, return indices of the two numbers such that they add up to a specific target.

// You may assume that each input would have exactly one solution, and you may not use the same element twice.

// Example:

// Given nums = [2, 7, 11, 15], target = 9,

// Because nums[0] + nums[1] = 2 + 7 = 9,
// return [0, 1].

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int>::iterator beg=nums.begin();
        vector<int> res;
        while(beg!=nums.end()-1)
        {
             vector<int>::iterator secon=find(beg+1,nums.end(),target-(*beg));
            if(secon!=nums.end())
            {
                res.push_back(beg-nums.begin());
                res.push_back(secon-nums.begin());
                return res;
            }
            ++beg;
       }
    }
};

int main()
{
    int a[5]={2,7,11,5};
    vector<int> nums(a,a+4);
    Solution solu;
    vector<int> out=solu.twoSum(nums,9);
    for(int i=0;i<out.size();i++)
        cout<<out[i]<<endl;
    //return 0;
}
