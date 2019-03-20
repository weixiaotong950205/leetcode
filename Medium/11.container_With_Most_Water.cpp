// Given n non-negative integers a1, a2, ..., an , where each represents a point at coordinate (i, ai).
// n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). 
// Find two lines, which together with x-axis forms a container, such that the container contains the most water.
// Note: You may not slant the container and n is at least 2

#include<vector>
#include<iostream>

using namespace std;

//暴力搜索法
class Solution {
public:
    int maxArea(vector<int>& height) {
        int size=height.size();
        int most=0;
        for(int i=0;i<=size-2;i++)
            for(int j=i+1;j<=size-1;j++)
            {
                int water=(height[i]<=height[j]?height[i]*(j-i):height[j]*(j-i));
                if(water>most)
                    most=water;
            }
        return most;
    }
};
int main(){
    vector<int> height={1,8,6,2,5,4,8,3,7};
    Solution solu;
    cout<<solu.maxArea(height);
    return 0;
}