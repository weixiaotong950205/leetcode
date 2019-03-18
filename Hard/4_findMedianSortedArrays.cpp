// There are two sorted arrays nums1 and nums2 of size m and n respectively.

// Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).

// You may assume nums1 and nums2 cannot be both empty.

// Example 1:

// nums1 = [1, 3]
// nums2 = [2]

// The median is 2.0
// Example 2:

// nums1 = [1, 2]
// nums2 = [3, 4]

// The median is (2 + 3)/2 = 2.5

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m=nums1.size();
        int n=nums2.size();
     if(m==0) return n%2 ? nums2[n/2] : (nums2[n/2]+nums2[n/2-1])/2.0 ; 
     if(n==0) return m%2 ? nums1[m/2] : (nums1[m/2]+nums1[m/2-1])/2.0;   
        vector<int> mer_num(m+n);
        std::merge(nums1.begin(),nums1.end(),nums2.begin(),nums2.end(),mer_num.begin());
        return (m+n)%2 ? mer_num[(m+n)/2] : (mer_num[(m+n)/2-1]+mer_num[(m+n)/2])/2.0;
    }
};

int main(){
    int a1[2]={1,2};
    int a2[2]={3,4};
    vector<int> nums1(a1,a1+2);
    vector<int> nums2(a2,a2+2);
    Solution solu;
    cout<<solu.findMedianSortedArrays(nums1,nums2)<<endl;
}
