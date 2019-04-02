// Given an integer, write a function to determine if it is a power of two.

// Example 1:

// Input: 1
// Output: true 
// Explanation: 20 = 1
// Example 2:

// Input: 16
// Output: true
// Explanation: 24 = 16
// Example 3:

// Input: 218
// Output: false

#include<iostream>
using namespace std;
//自己的解法:反复除以2，在1之前若出现奇数，则非2的的幂
//遇到的问题，没有考虑负数，0的情况
//用abs将负数转换为正数后，出现了最大负整数转换取绝对值后超出相应长度最大正整数的范围
// class Solution {
// public:
//     bool isPowerOfTwo(int n) {
//         if(n<=0) return false;
//         while(n>1){
//             if(n%2)return false;
//             n/=2;
//         }
//         return true;
//     }
// };

//按位与方法
class Solution {
public:
    bool isPowerOfTwo(int n) {
        return n>0 &&(n&(n-1))==0;
    }
};


int main(){
    Solution solu;
    cout<<solu.isPowerOfTwo(2);
}