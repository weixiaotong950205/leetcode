// Given an array of integers nums sorted in ascending order, find the starting and ending position of a given target value.

// Your algorithm's runtime complexity must be in the order of O(log n).

// If the target is not found in the array, return [-1, -1].

// Example 1:

// Input: nums = [5,7,7,8,8,10], target = 8
// Output: [3,4]
// Example 2:

// Input: nums = [5,7,7,8,8,10], target = 6
// Output: [-1,-1]

#include<vector>
#include<iostream>
using namespace std;

//second version:binarySearch
class Solution {

public:
    vector<int> searchRange(vector<int>& nums, int target) {
       vector<int> res={-1,-1};
       if(nums.empty()) return res;
       int pos,cnt_lft=0,cnt_rh=0;
       pos=binarySearch( nums, target, 0, nums.size()-1);
       if(pos==-1)
           return res;
       for(int i=pos+1;i<nums.size();i++)
       {
           if (nums[i] == target)
           {
               cnt_rh++;
           }
           else break;
       }
       for(int i=pos-1;i>=0;i--)
       {
           if (nums[i] == target)
           {
               cnt_lft--;
           }
           else break;
       }
       res[0]=pos+cnt_lft;
       res[1]=pos+cnt_rh;
       return res;
    }
private:
	int binarySearch(vector<int>& nums, int target, int low, int high)
	{
		if (low > high)return -1;
		int med = (low + high) / 2;
		if (nums[med] == target)return med;
		if (target > nums[med])
			return binarySearch(nums, target, med+1, high);
		else
			return binarySearch(nums, target, low, med-1);

	}
};

//first version:runtime 8ms,96.94%
//class Solution {
//
//public:
//	vector<int> searchRange(vector<int>& nums, int target) {
//		int first = -1, count = 0;
//		vector<int> res;
//		for (int i = 0; i < nums.size(); i++)
//			if (nums[i] == target)
//			{
//				first = i;
//				for (int j = i + 1; i < nums.size(); j++)
//				{
//					if (nums[j] == target)
//						count++;
//					else
//						break;
//				}
//				break;
//			}
//		res.push_back(first);
//		res.push_back(first + count);
//		return res;
//	}
//};

int main(){
    Solution solu;
    vector<int> nums={5,7,7,8,8,10}; 
    vector<int> res=solu.searchRange(nums,8);
    for(auto i:res)
        cout<<i<<" ";
    return 0;
}