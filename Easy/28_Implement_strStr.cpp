// Implement strStr().

// Return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

// Example 1:

// Input: haystack = "hello", needle = "ll"
// Output: 2
// Example 2:

// Input: haystack = "aaaaa", needle = "bba"
// Output: -1
#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle.size()==0)
            return 0;
        if(needle.size()>haystack.size())
            return -1;
        for(int i=0;i<=haystack.size()-needle.size();i++)
            if(haystack.substr(i,needle.size())==needle)
                return i;
        return -1;
    }
};

int main(){
    string haystack("hello");
    string needle("ll");
    Solution solu;
    cout<<solu.strStr(haystack,needle)<<endl;
}