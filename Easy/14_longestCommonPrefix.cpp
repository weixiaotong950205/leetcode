// Write a function to find the longest common prefix string amongst an array of strings.

// If there is no common prefix, return an empty string "".

// Example 1:

// Input: ["flower","flow","flight"]
// Output: "fl"
// Example 2:

// Input: ["dog","racecar","car"]
// Output: ""
// Explanation: There is no common prefix among the input strings.
// Note:

// All given inputs are in lowercase letters a-z.
#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size()==0||strs[0].empty())return "";
        string common=strs[0];
        for(int i=1;i<strs.size();i++){
            if(strs[i].empty())return "";
            for(int j=0;j<common.size()&&strs[i].size();j++)
                if(strs[i][j]!=common[j])
                {
                 if(j==0) return "";
                 if(j<common.size())
                     common=common.substr(0,j);
                 break;
                }
        }
        return common;
    
    }
};

int main(){
    vector<string> strs={"flower","flow","flight"};
    Solution solu;
    cout<<solu.longestCommonPrefix(strs)<<endl;
}
