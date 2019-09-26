/*把二叉树打印成多行
    从上到下按层打印二叉树，同一层结点从左至右输出。每一层输出一行。
*/
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

struct TreeNode{
public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x):
        val(x), left(nullptr), right(nullptr){}
};

class Solution {
public:
    
    vector<vector<int>> Print(TreeNode* pRoot){
        vector<vector<int>> ret;
        vector<int> level;
        queue<TreeNode*> q;
        if(!pRoot) return ret;
        q.push(pRoot);
        while(!q.empty()){
            level.clear();
            int len = q.size();//记录每一层的个数
            for(int i=0; i<len; i++){//每一层的元素将子节点全部加入队列后，这一层节点自身都会全部出队
                TreeNode *temp = q.front();
                q.pop();
                level.push_back(temp->val);
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
            }            
            ret.push_back(level);
        }
        return ret;
    }
};