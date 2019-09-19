/*二叉树的深度
*/
#include<iostream>

using namespace std;

#define max(a, b) a>b?a:b
struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x):
        val(x), left(NULL), right(NULL){}
};

class Solution {
public:
    int TreeDepth(TreeNode* root){//基本操作
        if(!root) return 0;
        return 1 + max(TreeDepth(root->left), TreeDepth(root->right));
    }
};