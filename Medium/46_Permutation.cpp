// Given a collection of distinct integers, return all possible permutations.

// Example:

// Input: [1,2,3]
// Output:
// [
//   [1,2,3],
//   [1,3,2],
//   [2,1,3],
//   [2,3,1],
//   [3,1,2],
//   [3,2,1]
// ]

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int> > ans;
        sort(nums.begin(),nums.end());
        ans.push_back(nums);
        while(next_permutation(nums.begin(),nums.end())){
            ans.push_back(nums);
        }
        return ans;
                
    }
};

int main(){
    Solution solu;
    vector<int> nums={1,2,3};
    vector<vector<int> > ans=solu.permute(nums);
    for(auto v:ans)
        for(auto i:v)
            cout<<i<<" ";
}