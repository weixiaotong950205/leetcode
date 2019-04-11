// Given a collection of candidate numbers (candidates) and a target number (target),
// find all unique combinations in candidates where the candidate numbers sums to target.

// Each number in candidates may only be used once in the combination.

// Note:

// All numbers (including target) will be positive integers.
// The solution set must not contain duplicate combinations.
// Example 1:

// Input: candidates = [10,1,2,7,6,1,5], target = 8,
// A solution set is:
// [
//   [1, 7],
//   [1, 2, 5],
//   [2, 6],
//   [1, 1, 6]
// ]

//此题和上一题基本一致，唯一不同的是，在和不超过target时不用回溯。

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//此版本递归不对，测试用例只能找到1 1 6， 1 7
// class Solution {
// public:
// 	vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
// 		vector<int> vec;
// 		sort(candidates.begin(), candidates.end());
// 		vector<int>::iterator it = lower_bound(candidates.begin(), candidates.end(), target);
// 		if (it == candidates.begin() && *it > target)
// 			return ans;
// 		search_range = it - candidates.begin() ;
// 		if (search_range > candidates.size())
// 			--search_range;
// 		int sum = 0;
// 		dfs(candidates, target, vec, sum, 0);
// 		return ans;
// 	}
// private:
// 	int search_range;
// 	vector<vector<int> > ans;
// 	void dfs(vector<int>&candidates, int target, vector<int>& vec, int& sum, int begin) {//sum应该传引用
// 		for (int i = begin; i < search_range; ++i) {
// 			sum += candidates[i];
// 			if (sum < target) {
// 				vec.push_back(candidates[i]);
// 				continue;
// 			}
// 			else if (sum == target) {
// 				vec.push_back(candidates[i]);
// 				ans.push_back(vec);
// 				sum -= vec.back();
// 				vec.pop_back();
// 				sum -= vec.back();
// 				vec.pop_back();
// 				dfs(candidates, target, vec, sum, i);
// 			}
// 			else { //temp>target
// 				sum -= candidates[i];
// 				sum -= vec.back();
// 				vec.pop_back();
// 				dfs(candidates, target, vec, sum, i);

// 			}

// 		}
// 		//vec.pop_back();//一次for循环完成后回到上层需要将最后的元素pop出，例如：2+2+2+  3、6、7，当回溯到更上一层for循环时，需要将尾部2pop()出来
// 	}
// };
class Solution
{
  public:
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
    {
        sort(candidates.begin(), candidates.end());
        //vector<int>::iterator it = lower_bound(candidates.begin(), candidates.end(), target);//用lower_bounder在面对有重复target的时候会有问题
        vector<int>::iterator it = upper_bound(candidates.begin(), candidates.end(), target);
        if (it == candidates.begin())
            return ret;
        search_range = it - candidates.begin() ;
 		// if (search_range > candidates.size())
 		// 	--search_range;
        vector<int> temp;
        dfs(candidates,temp,target,0);
        return ret;
    }

  private:
    vector<vector<int>> ret;
    int search_range;
    void dfs(vector<int> &candidates, vector<int> &temp, int remain, int start)
    {
        if (remain < 0)
            return;
        else if (remain == 0)
            ret.push_back(temp);
        else
        {
            for (int pos = start; pos < search_range; pos++)
            {
                if (pos > start && candidates[pos] == candidates[pos - 1])
                    continue;
                temp.push_back(candidates[pos]);
                dfs(candidates, temp, remain - candidates[pos], pos + 1);
                temp.pop_back();
            }
        }
    }
};

int main()
{
    vector<int> candinates = {2,5,2,1,2};
    Solution solu;
    vector<vector<int>> ans = solu.combinationSum2(candinates, 5);
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
            cout << ans[i][j] << " ";
        cout << endl;
    }
}
