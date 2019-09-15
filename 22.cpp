/*二叉树层序遍历
    从上往下打印出二叉树的每个节点，同层节点从左至右打印

先使用队列来存储节点，然后取队头节点，判断这个节点左孩子是否为空，不为空，push左孩子进队列，
判断这个节点右孩子是否为空，不为空，push右孩子进队列，最后将队头节点数据直接push进vector，pop队头，继续出下一个数据。
*/
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) :
        val(x), left(NULL), right(NULL){
        }
};

class Solution{
public:
    vector<int> PrintFromTopToBottom(TreeNode* root){
        vector <int> ret;
        queue <TreeNode*> q;
        
        if(!root) return ret;
        q.push(root);
        while(!q.empty()){
            TreeNode* node = q.front();
            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
            ret.push_back(node->val);
            q.pop();
        }
        return ret;
    }
};