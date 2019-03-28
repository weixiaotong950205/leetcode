// The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: 
//(you may want to display this pattern in a fixed font for better legibility)

// P   A   H   N
// A P L S I I G
// Y   I   R
// And then read line by line: "PAHNAPLSIIGYIR"

// Write the code that will take a string and make this conversion given a number of rows:

// string convert(string s, int numRows);
// Example 1:

// Input: s = "PAYPALISHIRING", numRows = 3
// Output: "PAHNAPLSIIGYIR"
// Example 2:

// Input: s = "PAYPALISHIRING", numRows = 4
// Output: "PINALSIGYAHRPI"
// Explanation:

// P     I    N
// A   L S  I G
// Y A   H R
// P     I

//主要思路：用nRows个链表来存储Z字表里面每行的字符
//这样就可以忽略Z字表的实际形态

#include<iostream>
#include<vector>
#include<string>

using namespace std;
struct charNode
{
    char val;
    charNode *next;
    charNode(char c) : val(c),next(NULL){}
};

class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows==1)
            return s;
        if(s.size()<=numRows)
            return s;
        int i,k;
        vector<charNode*> vhead;
        for(i=0;i<numRows;i++){
            charNode* head=new charNode(s[i]);
            vhead.push_back(head);
        }
         vector<charNode*> curNode(vhead.begin(),vhead.end());
        bool turnUp=true;
        k=numRows-1;
        for(;i<s.size();i++){ //i记录字符串中的索引位置
            if(turnUp){//向上填充Z字表
                --k;
                charNode *node=new charNode(s[i]);
                curNode[k]->next=node;
                curNode[k]=curNode[k]->next;
                if(k==0)
                    turnUp=!turnUp;
            }
            else{//向下填充
                ++k;
                charNode *node=new charNode(s[i]);
                curNode[k]->next=node;
                curNode[k]=curNode[k]->next;
                if(k==numRows-1)
                    turnUp=!turnUp;
            }   
        }
        string res;
        for(i=0;i<numRows;i++){
            curNode[i]=vhead[i];
            while(curNode[i]){
                res.push_back(curNode[i]->val);
                curNode[i]=curNode[i]->next;
            }
        }
        return res;
    }
};

int main(){
    Solution solu;
    cout<<solu.convert("PAYPALISHIRING",4);
   
}