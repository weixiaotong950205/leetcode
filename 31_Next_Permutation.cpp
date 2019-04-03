// Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.

// If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).

// The replacement must be in-place and use only constant extra memory.

// Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.

// 1,2,3 → 1,3,2
// 3,2,1 → 1,2,3
// 1,1,5 → 1,5,1

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


//使用了stl的库函数，具体实现还要手写一下
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        std::next_permutation(nums.begin(),nums.end()); 
    }
};

int main(){
    vector<int> nums={3,2,1};
    Solution solu;
    solu.nextPermutation(nums);
    for(auto i:nums)
        cout<<i<<endl;
    return 0;
}