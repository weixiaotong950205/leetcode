// Given a collection of numbers that might contain duplicates, return all possible unique permutations.

// Example:

// Input: [1,1,2]
// Output:
// [
//   [1,1,2],
//   [1,2,1],
//   [2,1,1]
// ]

//跟46题一样的解法，运行时间不稳定，更慢一些

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
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
    vector<int> nums={1,1,1,2};
    vector<vector<int> > ans=solu.permuteUnique(nums);
    for(auto v:ans){
        for(auto i:v)
            cout<<i<<" ";
        cout<<endl;
    }

}