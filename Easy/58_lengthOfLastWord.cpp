// Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of last word in the string.

// If the last word does not exist, return 0.

// Note: A word is defined as a character sequence consists of non-space characters only.

// Example:

// Input: "Hello World"
// Output: 5
#include<string>
#include<iostream>
using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        int len=0;
        bool flag=false;
        for(int i=s.size()-1;i>=0;i--){
            if(flag&&s[i]==' ') break;
            if((s[i]>='A'&&s[i]<='Z') || (s[i]>='a'&&s[i]<='z'))
            {
                ++len;
                flag=true;
            }
        }
        return len;
    }
};

int main(){
    string s("hello world");
    Solution solu;
    cout<<solu.lengthOfLastWord(s)<<endl;
}