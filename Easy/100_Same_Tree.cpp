// Given two binary trees, write a function to check if they are the same or not.

// Two binary trees are considered the same if they are structurally identical and the nodes have the same value.

// Example 1:

// Input:     1         1
//           / \       / \
//          2   3     2   3

//         [1,2,3],   [1,2,3]

// Output: true
// Example 2:

// Input:     1         1
//           /           \
//          2             2

//         [1,2],     [1,null,2]

// Output: false
// Example 3:

// Input:     1         1
//           / \       / \
//          2   1     1   2

//         [1,2,1],   [1,1,2]

// Output: false
#include<iostream>

using namespace std;

struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };

//按照两种遍历序列进行对比是错误的，反例就如题设中例二
//还有一种思路,将两棵树的遍历结果分别放入一个tupe中，先对比tupe的size,再依序对比元素
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(!p&&!q) return true;
        if(!p||!q) return false;
        if(p->val==q->val) return isSameTree(p->left,q->left)&&isSameTree(p->right,q->right);
        return false;
    }

};

int main(){
    TreeNode* p=new TreeNode(1);
    p->left=new TreeNode(2);
    p->right=new TreeNode(1);
    TreeNode* q=new TreeNode(1);
    q->left =new TreeNode(2);
    q->left =new TreeNode(1);
    Solution solu;
    cout<<solu.isSameTree(p,q)<<endl;
    return 0;
}