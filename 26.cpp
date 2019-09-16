/*二叉树与双向链表
    输入一颗二叉搜索树， 将该二叉搜索树转换成一个排序的双向链表。要求不能创建任何新的节点，只能调整树中结点指针的指向。

    定义了head和tail分别作为新双链表的头结点尾节点，按照中序顺序将节点重新连接。
*/
#include<iostream>
#include<vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x): 
        val(x), left(NULL), right(NULL){}
};

class Solution1 {//违反了不能申请新空间的要求
public:
    TreeNode* Convert(TreeNode* pRootOfTree){
        vector<TreeNode*> v;
        Inorder(pRootOfTree, v);
        //依次连接
        v[0]->left = NULL;
        v[0]->right = v[1];
        for(int i=1;i<v.size()-1;i++){            
            v[i]->left = v[i-1];
            v[i]->right = v[i+1];
        }
        v[v.size()-1]->left = v[v.size()-2];
        v[v.size()-1]->right = NULL;
        //返回链表头
        return v[0];
    }

    void Inorder(TreeNode* root, vector<TreeNode*> &v){//中序遍历，存入数组
        if(root->left) Inorder(root->left, v);
        v.push_back(root);
        if(root->right) Inorder(root->right, v);
    }
};

class Solution2 {//中序遍历，逐步延长尾部
public:
    TreeNode* head = NULL,*tail = NULL;//分别代表链表的头与尾， 逐步延长
    TreeNode* Convert(TreeNode* pRootOfTree){
        if(!pRootOfTree) return NULL;
        Convert(pRootOfTree->left);
        if(!tail){//此时到达了最左侧的叶子节点
            head = pRootOfTree;
            tail = pRootOfTree;//头和尾都是它
        }
        else{
            pRootOfTree->left = tail;
            tail->right = pRootOfTree;//将当前节点与尾节点连接
            tail = pRootOfTree;//更新尾节点
        }
        Convert(pRootOfTree->right);
        return head;
    }
};