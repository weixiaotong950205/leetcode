// Given a set of candidate numbers (candidates) (without duplicates) and a target number (target), 
// find all unique combinations in candidates where the candidate numbers sums to target.
// The same repeated number may be chosen from candidates unlimited number of times.

// Note:

// All numbers (including target) will be positive integers.
// The solution set must not contain duplicate combinations.
// Example 1:

// Input: candidates = [2,3,6,7], target = 7,
// A solution set is:
// [
//   [7],
//   [2,2,3]
// ]
// Example 2:

// Input: candidates = [2,3,5], target = 8,
// A solution set is:
// [
//   [2,2,2,2],
//   [2,3,3],
//   [3,5]
// ]

//思路：回溯，参考https://www.cnblogs.com/jimmycheng/p/7198156.html?utm_source=itdadao&utm_medium=referral与https://blog.csdn.net/zkj126521/article/details/76422344
// 题目给了我们一个candidates array 和一个 target， 让我们从array 里找到所有的组合，它的和是等于target的。任何组合只要是它的和等于target的话，都需要找到，但是不需要重复的。
//这道题中是可以重复利用一个数字的，那么我们就需要每次都代入同一个数字，直到它之和达到target 或者它超过了target， 然后在倒退回去一个数字，继续找下一个数字，这种情况肯定是要用递归了。
//这里是backtracking，每次倒退回一个数字，需要继续递归下去，在倒退，一直重复直到搜索了所有的可能性。

// 　　我们可以看原题中的例子：

// 　　[2,3,6,7]  target 7

// 　　2                                  选2，sum = 2

// 　　2+2                              选2，sum = 4

// 　　2+2+2                          选2，sum = 6

// 　　2+2+2+2                      选2，sum = 8 这时候 sum已经超出target，需要返回到上一个数字

// 　　2+2+2+3                      选3，sum = 9， 也超出了target， 这里我们可以发现，如果是sorted array的话，从小到大，只要一次超出，后面的数字必然也会超出target，所以可以在第一次超出的时候就直接跳出这一个迭代

// 　　2+2+3                          选3，sum = 7，等于target， 此时返回并且跳出这一个迭代，因为后面的数字肯定超出（array里不会有重复的数字）

// 　　2+3                              选3，sum = 5，小于target，继续递归同一个数字

// 　　2+3+3                          选3，sum = 8，超出target，返回上一个数字

// 　　2+6                              选6，sum = 8，超出target，返回上一个数字

// 　　3                                  选3，这里继续从3开始递归

// 　　...

// 　　...

// 　　...

// 　　我们可以看出，一开始有一个迭代从2，一直到7，然后把每一个数字递归下去，包括它自己，每次递归下去的数字，会继续有一个迭代，一旦超出或者等于了，返回前面一个数字继续递归。
//所以把array sort一下就可以提早跳出那一轮的迭代。

//递归写法参考的后者博客，并没有在已经大于target的情况下放弃遍历后面的数字，因此有修改的空间
//一定要理解回溯算法，学会写递归

//存在问题：输入为[2],1时，出现了runtime error;
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int> > ans;
    int search_range;
    vector<vector<int> > combinationSum(vector<int>& candidates, int target) {
        vector<int> vec;
        sort(candidates.begin(),candidates.end());
        vector<int>::iterator it=lower_bound(candidates.begin(),candidates.end(),target);
        if(it==candidates.begin()&& *it>target) //若只这么写的的话，像[1],1这样的测试用例就会出现输出为空的情况，因此后面还要加*it>target的判断
            return ans;
        search_range=it-candidates.begin()+1; //只写这一步的话如果target大于所有数值时会出现越界情况
        if(search_range>candidates.size())//修复上条注释提到的问题 
            --search_range;
        dfs(candidates,target,vec,0,0);
        return ans;
    }
private:
    void dfs(vector<int>&candidates,int target,vector<int>& vec,int sum,int begin){
        for(int i=begin;i<search_range;++i){
            int temp=sum+candidates[i];
            if(temp<target){
                vec.push_back(candidates[i]);
                dfs(candidates,target,vec,temp,i);
            }
            else if(temp==target){
                vec.push_back(candidates[i]);
                ans.push_back(vec);
                vec.pop_back();
                vec.pop_back();
                return ;
            }
            else{ //temp>target
                sum-=vec.back();//此行忘记添加，无输出
                vec.pop_back();
                return;
            }

        }
        vec.pop_back();//一次for循环完成后回到上层需要将最后的元素pop出，例如：2+2+2+  3、6、7，当回溯到更上一层for循环时，需要将尾部2pop()出来
    }
};

int main(){
    vector<int> candinates={1};
    Solution solu;
    vector<vector<int> >ans=solu.combinationSum(candinates,1);
    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[i].size();j++)
            cout<<ans[i][j]<<" ";
        cout<<endl;
    }
}