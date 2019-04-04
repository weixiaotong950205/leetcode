// Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as one sorted array.

// Note:

// The number of elements initialized in nums1 and nums2 are m and n respectively.
// You may assume that nums1 has enough space (size that is greater or equal to m + n) to hold additional elements from nums2.
// Example:

// Input:
// nums1 = [1,2,3,0,0,0], m = 3
// nums2 = [2,5,6],       n = 3

// Output: [1,2,2,3,5,6]

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
//此题较为简单，主要测试一下自己写的版本和std标准库的区别
//标准库版本的不能用于输出与输入相同的情况
//标准库版本8ms,超越百分之五十
// class Solution {
// public:
//     void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
//         vector<int> res(m+n);
//         std::merge(nums1.begin(),nums1.begin()+m,nums2.begin(),nums2.end(),res.begin());
//         copy(res.begin(),res.end(),nums1.begin());
//     }
// };

class Solution {    //尝试优化
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
       //同时排除空数组的情况
       if(n==0) return;
       if(m==0){
         std::copy(nums2.begin(),nums2.end(),nums1.begin()); 
         return ;
       }
       if(nums2[0]>=nums1[m-1]){//如果nums2可以直接放到nums1的后面
            std::copy(nums2.begin(),nums2.end(),nums1.begin()+m); 
            return;
       }
       if(nums2[n-1]<=nums1[0]){  //如果nums2可以直接放到nums1的前面
            std::copy_backward(nums1.begin(),nums1.begin()+m,nums1.begin()+m-1);
            std::copy(nums2.begin(),nums2.end(),nums1.begin());
            return;
       }
       //参考其他人的答案，可从后往前合并
       int i=m-1,j=n-1,cur=m+n-1;
       while(i>=0&&j>=0)
       {
            if(nums2[j]>nums1[i])
                nums1[cur--]=nums2[j--];
            else
                nums1[cur--]=nums1[i--];
       }
       if(j<0) return;
       copy(nums2.begin(),nums2.begin()+j+1,nums1.begin());
    }
};

int main(){
    vector<int> nums1={2,0};
    vector<int> nums2={1};
    Solution solu;
    solu.merge(nums1,1,nums2,1);
    for(int i:nums1)
        cout<<i<<endl;
}