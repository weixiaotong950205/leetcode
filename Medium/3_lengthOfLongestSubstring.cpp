

#include<string>
#include<iostream>

using namespace std;


class Solution { //leetcode第三题
public:
	int lengthOfLongestSubstring(string s) {
		if (s.size() == 1)
			return 1;
		string str;
		int search_begin = 0, max_length = 0;
		for (int i = 0; i<s.size(); i++)
		{
			if (str.find(s[i]) == str.npos)
				str.push_back(s[i]);
			else
			{
				
				
				i = s.find(s[i],search_begin);
				search_begin=i+1 ;
				if (str.size()>max_length)
				{
					max_length = str.size();
				}
				str.clear();
			}
		}
		return max_length > str.size() ? max_length : str.size();
	}
};



int main(){
    string s("abcabcbb");
    Solution solu;
    cout<<solu.lengthOfLongestSubstring(s)<<endl;
}