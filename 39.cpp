/*平衡二叉树
输入一颗二叉树，判断其是否是平衡二叉树
*/

#include <iostream>

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
    bool isBalenced(TreeNode* root){
        int high;
        return isBalenced(root, high);
    }
    bool isBalenced(TreeNode* root, int &high){//重载，判断函数， 加上用以记录节点高度的参数
        if(!root){//当是叶子节点时
            high == 0;//高度为0
            return true;//是平衡二叉树
        } 
        int left, right;//用来记录左右子树的高度
        if(isBalenced(root->left, left) && isBalenced(root->right, right)){//后序遍历
            int sub = abs(left - right);
            if(sub < 2){//如果左右子树高度差小于2
                high = 1 + max(left, right);//更新本层高度
                return true;//是平衡二叉树
            }
        }
        return false;
    }

};