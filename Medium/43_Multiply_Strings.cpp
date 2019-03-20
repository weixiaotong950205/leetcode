// Given two non-negative integers num1 and num2 represented as strings, return the product of num1 and num2, also represented as a string.

// Example 1:

// Input: num1 = "2", num2 = "3"
// Output: "6"
// Example 2:

// Input: num1 = "123", num2 = "456"
// Output: "56088"
// Note:

// The length of both num1 and num2 is < 110.
// Both num1 and num2 contain only digits 0-9.
// Both num1 and num2 do not contain any leading zero, except the number 0 itself.
// You must not use any built-in BigInteger library or convert the inputs to integer directly.

#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Solution {
public:
	string multiply(string num1, string num2) {
		if (num1 == "0" || num2 == "0")return string("0");
		int size1 = num1.size(), size2 = num2.size(), res_size = size1 + size2;
		vector<int> vi(res_size, 0);
		int temp;
		for (int i = size1 - 1; i >= 0; i--)
			for (int j = size2 - 1; j >= 0; j--)
			{
				temp = (num1[i] - '0')*(num2[j] - '0');
				if (temp < 10)
				{
					vi[res_size - i - j - 2] += temp;
				}
				else
				{
					vi[res_size - i - j - 1] += temp / 10;
					vi[res_size - i - j - 2] += temp % 10;
				}
			}
		for (int i = 0; i < res_size - 1; i++)
			if (vi[i] >= 10)
			{
				vi[i + 1] += vi[i] / 10;
				vi[i] %= 10;
			}
		if (vi[res_size-1] == 0) vi.pop_back();
		string s;
		for (int i = vi.size() - 1; i >= 0; i--)
			s.push_back(vi[i] + '0');
		return s;
	}
};

int main(){
    string num1="123";
    string num2="456";
    Solution solu;
    cout<<solu.multiply(num1,num2);
    return 0;
}