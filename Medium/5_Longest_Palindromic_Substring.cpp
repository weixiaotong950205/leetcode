// Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.

// Example 1:

// Input: "babad"
// Output: "bab"
// Note: "aba" is also a valid answer.
// Example 2:

// Input: "cbbd"
// Output: "bb"

//采用temp记录当前最大回文串时出现了内存超出的情况
//改进为记录当前最大回文串的首位置的方式：仍然超出：Memory Limit Exceeded
#include<iostream>
#include<string>
#include<vector>
using namespace std;
//内存超限
// class Solution {
// public:
// 	string longestPalindrome(string s) {
//         int first=0;
// 		int max_size = 1;
// 		for (int i = 0; i < s.size()-1;i++) {
// 			if (s.size() - i <= max_size)
// 				return s.substr(first,max_size);     //未遍历的最长字符串已经小于当前最长的回文串
// 			for (int j = i+1; j < s.size(); j++) {
// 				if (max_size >= j-i + 1)
// 					continue;
// 				if (isPllindrome(s.substr(i, j - i + 1)) &&j-i+1 > max_size) {
// 					max_size = j-i+1;
// 					first=i;
// 				}
// 			}
// 		}
//         return s.substr(first,max_size);

// 	}
// private:
// 	bool isPllindrome(const string &s) {
// 		if (s.size() == 0 || s.size() == 1)
// 			return true;
// 		int first = 0;
// 		int last = s.size() - 1;
// 		while (s[first]==s[last]&&first<last){
// 			++first;
// 			--last;
// 		}
// 		return first < last ? false : true;
// 	}
// };
//参考https://leetcode.com/problems/longest-palindromic-substring/discuss/147548/Direct-c%2B%2B-DP
//DP求解

class Solution {
public:
    string longestPalindrome(string s) {
		int n=s.size();
        if(n==0) return "";
		vector<vector<bool>> dp(s.size(),vector<bool>(s.size(),false));
		for(int i=0;i<n;i++){
			dp[i][i]=true;
			if(i==n-1) break;
			dp[i][i+1]=(s[i]==s[i+1]);
		}
		//填充dp表格
		for(int i=n-3;i>=0;i--)
			for(int j=i+2;j<n;j++)
				dp[i][j]=(s[i]==s[j]&&dp[i+1][j-1]);//首位相同，且中间也为回文串时才为回文串
		//寻找最长回文串
		int max=0;
		int first;
		for(int i=0;i<n;i++){
				if(max>=n-i)
					break;
			for(int j=i;j<n;j++)
				if(dp[i][j]&&j-i+1>max){
					first=i;
					max=j-i+1;
				}		
		}
		return s.substr(first,max);
		
    }
};

int main() {
	string s = "cbbbb";
	Solution solu;
	cout << solu.longestPalindrome(s) << endl;
}