/*对称的二叉树
    请实现一个函数，用来判断一颗二叉树是不是对成的。注意，如果一个二叉树同此二叉树的镜像是同样的，定义其为对称的。
*/
#include<iostream>

using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x):
        val(x), left(nullptr), right(nullptr){}
};

class Solution{
public:
    bool isSymmetrical(TreeNode* pNode){
        if(!pNode) return true;
        return isMirror(pNode->left, pNode->right);//判断它的左右子树是否互为镜像
    }
    bool isMirror(TreeNode* lNode, TreeNode* rNode){
        if(!lNode && !rNode) return true;//都为空 是
        if(!lNode || !rNode) return false;//一个为空 一个不为空 否
        if(lNode->val != rNode->val) return false;//值不相等， 否
        return isMirror(lNode->right, rNode->left) && isMirror(lNode->left, rNode->right);//递归判断他们的子树是否互为镜像
    }
};