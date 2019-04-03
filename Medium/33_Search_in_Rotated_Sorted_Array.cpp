// Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

// (i.e., [0,1,2,4,5,6,7] might become [4,5,6,7,0,1,2]).

// You are given a target value to search. If found in the array return its index, otherwise return -1.

// You may assume no duplicate exists in the array.

// Your algorithm's runtime complexity must be in the order of O(log n).

// Example 1:

// Input: nums = [4,5,6,7,0,1,2], target = 0
// Output: 4
// Example 2:

// Input: nums = [4,5,6,7,0,1,2], target = 3
// Output: -1


//主要思路：先用二分法找到枢纽位置，利用然后二分法在对应的区域寻找target

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int len=nums.size();
        if(nums.empty()||target<nums[0]&&target>nums[len-1]) //输入为空或者target没在范围内
            return -1;
        int first=nums[0],last=nums[len-1];
        if(first<=last){                                    //如果没有旋转，直接用二分法寻找
            auto it=lower_bound(nums.begin(),nums.end(),target);
            return it==nums.end()||*it>target ? -1 : it-nums.begin(); //此处未考虑it为end()的情况
        }
        int low=0,high=len-1,middle;
        while(high-low>1){      //二分法找枢值
            middle=(high+low)/2;
            if(nums[middle]<last){
                high=middle-1;
            }
            else
                low=middle;
        }
        int pivot= nums[high]>first ? high :low; //此处前一版本错误为用high直接与first进行比较了
        cout<<"pivot "<<pivot<<endl;
        vector<int>::iterator it;
        if(target>=first){
            it=lower_bound(nums.begin(),nums.begin()+pivot+1,target);
            return it==nums.begin()+pivot+1 || *it>target ? -1 : it-nums.begin(); //注意此处和57行的异同点
        }
        else{
             it=lower_bound(nums.begin()+pivot+1,nums.end(),target);
             return it==nums.end()|| *it>target ? -1 : it-nums.begin();
        }
          
        
    }
};

int main(){
    vector<int> nums={3,5,1};
    Solution solu;
    cout<<solu.search(nums,5);
    return 0;    
}
