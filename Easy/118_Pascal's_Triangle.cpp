// Given a non-negative integer numRows, generate the first numRows of Pascal's triangle.

// In Pascal's triangle, each number is the sum of the two numbers directly above it.

// Example:

// Input: 5
// Output:
// [
//      [1],
//     [1,1],
//    [1,2,1],
//   [1,3,3,1],
//  [1,4,6,4,1]
// ]

#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        	vector<vector<int> > res(numRows);
                
			for (int i = 0; i<numRows; i++){
                res[i].push_back(1);
				for (int j = 1; j<i; j++)
					res[i].push_back(res[i-1][j-1]+res[i-1][j]);
                if(i>0)
                res[i].push_back(1);
            
        }
			return res; 
    }
};

int main(){
    Solution solu;
    vector<vector<int > > res=solu.generate(6);
    for(int i=0;i<res.size();i++){
        for(int j=0;j<res[i].size();j++)
            cout<<res[i][j]<<" ";
        cout<<endl;
    } 
    return 0;
}