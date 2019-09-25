/*二叉树的下一个节点
    给定一个二叉树和其中一个节点，请找出中序遍历顺序的下一个节点并且返回。注意，树中的节点不仅包含左右节点，同时包含指向父节点的指针
*/
#include<iostream>

using namespace std;

struct TreeLinkNode {
    int val;
    TreeLinkNode *left;
    TreeLinkNode *right;
    TreeLinkNode *next;
    TreeLinkNode(int x):
        val(x), left(nullptr), right(nullptr), next(nullptr){}
};

class Solution{
public:
    TreeLinkNode* GetNext(TreeLinkNode* pNode){
        if(!pNode) return nullptr;
        if(pNode->right){//如果当前节点有右子树
            pNode = pNode->right;
            while(pNode->left)
                pNode = pNode->left;
            return pNode;//找到右子树中最左侧的那个节点（没有左节点就是右子节点本身）
        }
        //如果没有右子树
        while (pNode->next){//
            if(pNode->next->left == pNode){
                return pNode->next;//找到当前节点的一个祖先节点，当前节点必须在其左子树上
            }
            pNode = pNode->next;
        }
        return nullptr;//如果是整棵树最右侧的节点，返回空
    }
};
