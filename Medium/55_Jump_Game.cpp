// Given an array of non-negative integers, you are initially positioned at the first index of the array.

// Each element in the array represents your maximum jump length at that position.

// Determine if you are able to reach the last index.

// Example 1:

// Input: [2,3,1,1,4]
// Output: true
// Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.
// Example 2:

// Input: [3,2,1,0,4]
// Output: false
// Explanation: You will always arrive at index 3 no matter what. Its maximum
//              jump length is 0, which makes it impossible to reach the last index.

#include<vector>
#include<iostream>

using namespace std;

class Solution {
public:
	bool canJump(vector<int>& nums) {
		if (nums[0] == 0 && nums.size()>1)
			return false;
		int i = 0;
		while (i<nums.size())
		{
			int pre_pos = i;
			int max_step = 0;
			for (int j = i; j <= i + nums[i]; j++)
			{
				if (j + nums[j] >= nums.size() - 1)
					return true;
				if (j + nums[j] > max_step)
					max_step = j+nums[j];
			}
			i = max_step;
				if (nums[i] == 0)//向回搜索
				{
					int max_pos = 0;
					for (int j = i - 1; j>pre_pos; j--)
						if (j + nums[j]>max_pos)
							max_pos = j + nums[j];
					if (max_pos>i)
						i =max_pos;
					else
						return false;
				}
			
		}
		return true;
	}
};

int main(){
    vector<int> nums={2,3,1,1,4};
    Solution solu;
    cout<<solu.canJump(nums);
    return 0;
}