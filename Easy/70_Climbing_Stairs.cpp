// You are climbing a stair case. It takes n steps to reach to the top.

// Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

// Note: Given n will be a positive integer.

// Example 1:

// Input: 2
// Output: 2
// Explanation: There are two ways to climb to the top.
// 1. 1 step + 1 step
// 2. 2 steps
// Example 2:

// Input: 3
// Output: 3
// Explanation: There are three ways to climb to the top.
// 1. 1 step + 1 step + 1 step
// 2. 1 step + 2 steps
// 3. 2 steps + 1 step

//及斐波那契数列
//当n>=3时，可以将问题转换为两个子问题：
//当到n-1级阶梯时，再迈一步到n
//当到n-2级阶梯时，再迈两步到n
//及an=an-1+an-2
#include<iostream>

using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        int n_1=1;
        int n_2=0;
        int tmp;
        for(int i=1;i<=n;i++)
        {
            tmp=n_1+n_2;
            n_2=n_1;
            n_1=tmp;
        }
        return tmp;
    }
};

int main(){
    Solution solu;
    cout<<solu.climbStairs(5)<<endl;
}