// Given a 32-bit signed integer, reverse digits of an integer.

// Example 1:

// Input: 123
// Output: 321
// Example 2:

// Input: -123
// Output: -321
// Example 3:

// Input: 120
// Output: 21
// Note:
// Assume we are dealing with an environment which could only store integers within the 32-bit signed integer range: [−231,  231 − 1].
// For the purpose of this problem, assume that your function returns 0 when the reversed integer overflows.

// 1、Int32 //等于int, 占4个字节. 取值范围：-2147483648 2147483647

// 2、Int8 //等于byte,

// 3、Int16 //等于short, 占2个字节. -32768 32767

// 4、Int64 //等于long, 占8个字节. -9223372036854775808 9223372036854775807
#include<iostream>
#include<sstream>
#include<algorithm>
#include<string>

using namespace std;

class Solution {
public:
	int reverse(int x) {
		std::string str = to_string(x);
		if (str.size() == 1) //所有只有一位的情况
			return x;
		std::reverse(str.begin(), str.end());
        string res=str.substr(str.find_first_not_of('0'));
        int len=res.size();
		char symbol = res[len - 1];
        
		if (symbol == '-') {
            if(--len>10)
                return 0;
            else if(len==10){
                string num=str.substr(0,len);
                return num>"2147483648" ? 0:-1*stoi(num);
            }
            return -1*stoi(str.substr(0,len));
		}
        else{
            if(len>10)
                return 0;
            if(len==10)
                return res>"2147483647" ? 0: stoi(res);
            return stoi(res);
        }
        
	}
};

int main() {
	Solution solu;
	cout << solu.reverse(-10) << endl;
	system("pause");
}