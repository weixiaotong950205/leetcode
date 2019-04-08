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

//老版本的的算法复杂度在o(n^2),运行时间在百毫秒左右
// class Solution {
// public:
//     vector<int> twoSum(vector<int>& nums, int target) {
//         vector<int>::iterator beg=nums.begin();
//         vector<int> res;
//         while(beg!=nums.end()-1)
//         {
//              vector<int>::iterator secon=find(beg+1,nums.end(),target-(*beg));
//             if(secon!=nums.end())
//             {
//                 res.push_back(beg-nums.begin());
//                 res.push_back(secon-nums.begin());
//                 return res;
//             }
//             ++beg;
//        }
//     }
// };

//新版本的先对输入进行排序，再利用双向指针进行搜索
//时间复杂度 nlogn+2*n
//遇到的问题：未考虑排序后的容器下标变化问题,未考虑有重复元素且元素
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
       if(nums.size()<=1)
           return {-1,-1};
       vector<int> sort_nums(nums.begin(),nums.end());
       sort(sort_nums.begin(),sort_nums.end());
       int i=0,j=nums.size()-1;
       int sum;
       while(i<j){
           sum=sort_nums[i]+sort_nums[j];
           if(sum==target){
               int m=find(nums.begin(),nums.end(),sort_nums[i])-nums.begin();
               //防止两个元素相同的情况
               int n=find(nums.begin(),nums.begin()+m,sort_nums[j])-nums.begin();
               if(n==m)
                    n=find(nums.begin()+m+1,nums.end(),sort_nums[j])-nums.begin();
               vector<int> res;
               m>n ? res={n,m} : res={m,n};
               return res;
           }
           else if(sum>target)
               --j;
           else
               ++i;
       }
        return {-1,-1};
    }
};

int main()
{
    int a[5]={0,4,3,0};
    vector<int> nums(a,a+4);
    Solution solu;
    vector<int> out=solu.twoSum(nums,0);
    for(int i=0;i<out.size();i++)
        cout<<out[i]<<endl;
    for(auto i:nums)
        cout<<i<<endl;
    //return 0;
}
