// Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

// Integers in each row are sorted from left to right.
// The first integer of each row is greater than the last integer of the previous row.
// Example 1:

// Input:
// matrix = [
//   [1,   3,  5,  7],
//   [10, 11, 16, 20],
//   [23, 30, 34, 50]
// ]
// target = 3
// Output: true
// Example 2:

// Input:
// matrix = [
//   [1,   3,  5,  7],
//   [10, 11, 16, 20],
//   [23, 30, 34, 50]
// ]
// target = 13
// Output: false

#include<vector>
#include<iostream>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int> >& matrix, int target) {
        if(matrix.size()==0||matrix[0].size()==0)
            return false;
        int m=matrix.size();
        int n=matrix[0].size();
        for(int i=0;i<m;++i)
            if(matrix[i][0]<=target&&target<=matrix[i][n-1])
               return this->binarySearch(matrix[i], 0, n-1,  target);
         return false;       
            }
    bool binarySearch(vector<int> array, int low, int high, int target) {  
         int middle = (low + high)/2;  
            if(low > high) {  
                return false;  
            }  
            if(target == array[middle]) {  
                return true;  
            }  
            if(target < array[middle]) {  
                return binarySearch(array, low, middle-1, target);  
            }  
            if(target > array[middle]) {  
                return binarySearch(array, middle+1, high, target);  
            }   
        }     
       
    
};

int main(){
    vector<vector<int> > matrix={{1,   3,  5,  7},{10, 11, 16, 20},{23, 30, 34, 50}};
    Solution solu;
    cout<<solu.searchMatrix(matrix,13);
    return 0;
}