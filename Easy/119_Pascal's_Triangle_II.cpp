// Given a non-negative index k where k ≤ 33, return the kth index row of the Pascal's triangle.

// Note that the row index starts from 0.


// In Pascal's triangle, each number is the sum of the two numbers directly above it.

// Example:

// Input: 3
// Output: [1,3,3,1]

// Follow up:
// Could you optimize your algorithm to use only O(k) extra space?

#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
   
        vector<int> getRow(int rowIndex) {
        vector<int> result{1};
        vector<int> oldVec;
       for (int i = 2; i <= rowIndex + 1; ++i) {
             result.push_back(1);
             oldVec = result;
             for (int j = 1; j < i - 1; ++j) {
                 result[j] = oldVec[j - 1] + oldVec[j];
             }
        }
         return result;     
    }
};

int main(){
    Solution solu;
    vector<int> res=solu.getRow(3);
    for(auto i:res)
        cout<<i<<" ";
    return 0;
}