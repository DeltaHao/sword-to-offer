/*二叉树中和为某一值的路径
输入一颗二叉树的根节点和一个整数， 打印出二叉树中结点值的和为输入整数的所有路径。路径定义为从树的根节点开始往下一直到叶节点所经过的节点
注意：在返回值的list中，数组长度大的数组靠前
*/
#include<iostream>
#include<vector>
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
    
    vector<vector<int> > FindPath(TreeNode* root, int expectNumber) {
        vector<vector<int> > ret;
        vector<int> path;
        if(root) DFS(root, expectNumber, ret, path);
        return ret; 
    }
    
    void DFS(TreeNode* root, int expectNumber, vector<vector<int> > &ret, vector<int> &path){
        path.push_back(root->val);
        if(!root->left && !root->right){//如果到了叶节点
            if(root->val == expectNumber){//如果路径和等于路程
                ret.push_back(path);//加入ret中
            }
        }
        if(root->left)
            DFS(root->left, expectNumber-root->val, ret, path);
        if(root->right)
            DFS(root->right, expectNumber-root->val, ret, path);
        path.pop_back();//pop出一位，返回上一个分支 
    }
};