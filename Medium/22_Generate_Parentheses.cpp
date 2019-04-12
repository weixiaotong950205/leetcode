// Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

// For example, given n = 3, a solution set is:

// [
//   "((()))",
//   "(()())",
//   "(())()",
//   "()(())",
//   "()()()"
// ]

//此题思路：从简单的答案推复杂的如
//如，n=1时，只有s1="()"，而n=2时 "(s0)"，"s0()",","()s0"都是合法的解，但是后两者重复了
//求n=i的解时，应该先将si-1的所有解加到新增的"()"里面，这种情况下不会有重复的解，而后需要判断新得到的解与上一个解是否相同，只有相同时才会加入新的解集
//以上解法在n=4时不能获取全部解，漏掉了(())(())，即将新的一对括号加入某已经存在的括号里面

// class Solution {
// public:
// 	vector<string> generateParenthesis(int n) {
// 		if (n == 0) return { "" };
// 		vector<string> ans = { "()" };
// 		if (n == 1) return ans;
// 		for (int i = 1; i < n; i++) {
// 			int prev_size = ans.size();
// 			for (int j = 0; j < prev_size; j++) {
// 				string add_left = "()" + ans[j];
// 				if (add_left != ans.back())
// 					ans.push_back(add_left);
// 				string add_right = ans[j] + "()";
// 				if (add_right != ans.back())
// 					ans.push_back(add_right);
// 				ans[j] = "(" + ans[j] + ")";
// 			}
// 		}
// 		return ans;
// 	}
// };
#include<iostream>
#include<vector>
#include<string>

using namespace std;

class Solution {
public:
	vector<string> generateParenthesis(int n) {
		if (n == 0) return { "" };
		vector<string> ans ;
		string temp="";
        bacctrack(temp,ans,n,n);
		return ans;

	}
private:
    void bacctrack(string temp,vector<string>& ans,int left_remain,int right_remain){
        if(left_remain==0&&right_remain==0){
            ans.push_back(temp);
            return;
        }
        if(left_remain>right_remain)
            return;
        if(left_remain>0)
            bacctrack(temp+"(",ans,left_remain-1,right_remain);
        if(right_remain>0)
            bacctrack(temp+")",ans,left_remain,right_remain-1);
    }
};

int main(){
    Solution solu;
    vector<string> ans=solu.generateParenthesis(3);
    for(auto s: ans)
        cout<<s<<endl;
    cout<<ans.size();
}