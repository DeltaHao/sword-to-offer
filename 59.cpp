/*按之字形顺序打印二叉树
    请实现一个函数按照之字形打印二叉树，即第一行按照从左到右的顺序打印，第二行按照从右至左的顺序打印，其他以此类推
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
        bool isEven = 0;//是否是偶数行， 如果是的话，需要逆序
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
            if(isEven)
                reverse(level.begin(), level.end());
            ret.push_back(level);
            isEven = !isEven;
        }
        return ret;
    }
};