//test test test test test test

// Given a string containing digits from 2-9 inclusive, 
// return all possible letter combinations that the number could represent.
// A mapping of digit to letters (just like on the telephone buttons) is given below. 
// Note that 1 does not map to any letters.

//解题思路：（参考https://www.cnblogs.com/ganganloveu/p/4175384.html）
// 枚举所有情况。

// 对于每一个输入数字，对于已有的排列中每一个字符串，分别加入该数字所代表的每一个字符。

// 所有是三重for循环。

// 举例：

// 初始化排列{""}

// 1、输入2，代表"abc"

// 已有排列中只有字符串""，所以得到{"a","b","c"}

// 2、输入3，代表"def"

// (1)对于排列中的首元素"a"，删除"a"，并分别加入'd','e','f'，得到{"b","c","ad","ae","af"}

// (2)对于排列中的首元素"b"，删除"b"，并分别加入'd','e','f'，得到{"c","ad","ae","af","bd","be","bf"}

// (2)对于排列中的首元素"c"，删除"c"，并分别加入'd','e','f'，得到{"ad","ae","af","bd","be","bf","cd","ce","cf"}

#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
    vector<string> ret;
    if (digits.length()==0)
        return ret;
    vector<string> num_map={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    ret.push_back("");
    for(int i=0;i<digits.length();i++){
        int size=ret.size();
        for(int j=0;j<size;j++){
            string curhead=ret[0];
            ret.erase(ret.begin());
            int cur_num=digits[i]-'0';
            for(int k=0;k<num_map[cur_num].size();k++)
                ret.push_back(curhead+num_map[cur_num][k]);
        }
    }
    return ret;
        
    }
};

int main(){
  Solution solu;
  vector<string> ret=solu.letterCombinations("23");
  for(auto s : ret)
    cout<<s<<endl;
}
