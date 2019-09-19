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
        int high = 0;
        return isBalenced(root, high);
    }
    bool isBalenced(TreeNode* root, int &high){
        if(!root){
            high == 0;
            return true;
        } 
        int left, right;
        if(isBalenced(root->left, left) && isBalenced(root->right, right)){
            int sub = abs(left - right);
            if(sub < 2){
                high = 1 + max(left, right);
                return true;
            }
        }
        return false;
    }

};