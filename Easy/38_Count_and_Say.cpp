// The count-and-say sequence is the sequence of integers with the first five terms as following:

// 1.     1
// 2.     11
// 3.     21
// 4.     1211
// 5.     111221
// 1 is read off as "one 1" or 11.
// 11 is read off as "two 1s" or 21.
// 21 is read off as "one 2, then one 1" or 1211.

// Given an integer n where 1 ≤ n ≤ 30, generate the nth term of the count-and-say sequence.

// Note: Each term of the sequence of integers will be represented as a string.

// Example 1:

// Input: 1
// Output: "1"
// Example 2:

// Input: 4
// Output: "1211"

// 题意是n=1时输出字符串1；n=2时，数上次字符串中的数值个数，因为上次字符串有1个1，
// 所以输出11；n=3时，由于上次字符是11，有2个1，所以输出21；n=4时，由于上次字符串是21，有1个2和1个1，所以输出1211。依次类推，写个countAndSay(n)函数返回字符串。

#include<iostream>
#include<string>

using namespace std;

class Solution {
public:
	string countAndSay(int n) {
		string temp = "1";
		for (int i = 1; i < n; i++) {
			string s;
			int pos = -1, count = 0;
			char first = temp[0];
			while (1) {
				if (++pos == temp.size()) {
					s += to_string(count) + first;//不添加这一句最后一次的计数无法统计进去
					break;
				}
				if (temp[pos] == first) {
					++count;
				}
				else {
					s += to_string(count) + first;
					first = temp[pos];
					count = 1;
				}
			}
			temp = s;
		}
		return temp;
	}
};


int main(){
    Solution solu;
    cout<<solu.countAndSay(5);
}
