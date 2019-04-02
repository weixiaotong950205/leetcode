// Given a string, determine if it is a palindrome, 
//considering only alphanumeric characters and ignoring cases.

// Note: For the purpose of this problem, we define empty string as valid palindrome.

// Example 1:

// Input: "A man, a plan, a canal: Panama"
// Output: true
// Example 2:

// Input: "race a car"
// Output: false

//问题：未考虑i,j增减时的边界问题，在验证i、j是否继续增减时候应该先验证其值是否已经超出字符串的索引范围
//未考虑部分数字和字母ascll码相差和大小写之间的差值相同的情况。
// 可以用transform(s.begin(), s.end(), s.begin(), ::tolower)，将所有大写转换为小写，再进行判断;
#include<string>
#include<iostream>

using namespace std;

class Solution {
public:
	bool isPalindrome(string s) {
		if (s.size() <= 1)
			return true;
		int i = 0, j = s.size() - 1;
		while (true) {
			while (i < s.size() && !isLetters(s[i]) && !isNumbers(s[i]))
				++i;
			while (j > 0 && !isLetters(s[j])&&!isNumbers(s[j]))
				--j;
			if (i >= j)
				return true;
			if (s[i]==s[j]||isSameletters(s[i], s[j])) {
				++i;
				--j;
			}
			else
				return false;

		}
	}

private:
	int diff = 'a' - 'A';
	bool isLetters(char c) {
		return (c >= 'A'&& c <= 'Z') || (c >= 'a' && c <= 'z');
	}
	bool isNumbers(char c) {
		return c >= '0'&&c <= '9';
	}
	bool isSameletters(char c1, char c2) {
		return isLetters(c1) && isLetters(c2) && (c1 == c2 || abs(c1 - c2) == diff);
	}
};

int main()
{
	Solution solu;
	cout << solu.isPalindrome("0P");
	return 0;
}

