/*二叉搜索树的第K个节点
    给定一个二叉搜索树，请找出其中第k小的节点
*/
#include<iostream>
#include<vector>
using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x):
        val(x), left(nullptr), right(nullptr){}
};

class Solution{
public:
    int count = 0;
    TreeNode*  ret = nullptr;
    TreeNode* KthNode(TreeNode* pRoot, int k){
        //空结点直接返回
        if(!pRoot) return nullptr;
        //中序遍历， 先看左子树
        if(pRoot->left){
            ret = KthNode(pRoot->left, k);
        }
        if(ret) return ret;
        //再看根节点
        count++;
        if(count == k) return pRoot;
        //最后看右子树
        if(pRoot->right){
            ret = KthNode(pRoot->right, k);//由于count是全局变量，所以这里仍然可以用k做参数
        }
        if(ret) return ret;
    }
};