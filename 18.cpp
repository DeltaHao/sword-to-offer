/*二叉树的镜像
    操作给定的二叉树，使其变为指定二叉树的镜像
*/
#include<iostream>

using namespace std;
struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x):
        val(x), left(NULL), right(NULL){}
};

class Solution {
public:
    void Mirror(TreeNode* pRoot){
        if(!pRoot) return;
        swap(pRoot->left, pRoot->right);
        Mirror(pRoot->left);
        Mirror(pRoot->right);       
    }
};