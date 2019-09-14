/*树的子结构
    输入两颗二叉树A，B， 判断B是不是A的子结构。（PS：我们约定空树不是任意一个树的子结构）

**注意：树的子结构和子树是两个概念， 子树是包含了一个节点，就得包含这个节点下所有节点， 子结构是指包含了一个节点，可只取左子树或右子树，也可不取
*/
#include<iostream>

using namespace std;
struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x): 
        val(x), left(NULL), right(NULL){}
};
class Solution{
public:
    //判断2是否是1的子树
    bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2){
        if(!pRoot1 || !pRoot2) return false;//如果任何一个是空，则树2不为树1的子树
        if (ifEqual(pRoot1, pRoot2)) return true;//如果两树相等， 树2为树1的子树
        else{//如果俩树不相等， 递归看树1的左右子树是否与树2相等
            return (HasSubtree(pRoot1->left, pRoot2) || HasSubtree(pRoot1->right, pRoot2));
        }
    }
    bool ifEqual(TreeNode* p1, TreeNode* p2){//判断俩树是否相等
        if(p1 == NULL && p2 == NULL) return true;//若都为空则相等
        if(p1 == NULL || p2 == NULL) return false;//若有一个为空， 另一个不为空， 不相等
        if(p1->val != p2->val) return false;//若根节点不相等， 则不相等
        else{//若根节点相等， 递归判断左右子树是否相等
            if(ifEqual(p1->left, p2->left) && ifEqual(p1->right, p2->right))
                return true;
        }
    }



    //判断2是否是1的子结构
    bool HasSubstructure(TreeNode* pRoot1, TreeNode* pRoot2){
        if(!pRoot1 || !pRoot2) return false;//如果任何一个是空，则树2不为树1的子结构
        return(ChildLegal(pRoot1, pRoot2) || HasSubstructure(pRoot1->left, pRoot2) || HasSubstructure(pRoot1->right, pRoot2));
        //若树2是树1的子结构， 共有3种情况：树1与树2的根节点相同 或 树2的根节点在树1的左子树或右子树中
    }    
    bool ChildLegal(TreeNode*p1,TreeNode*p2){//在根节点相同的前提下， 判断2是否为1的子结构
        if(!p2)return true;//如果树2已经被递归为空， 说明其祖先节点都符合， 是子结构
        if(!p1)return false;//如果树1为空，说明这个节点不是树2的根节点， 返回否
        if(p1->val!=p2->val)return false;//如果值不相同，说明这个节点不是树2的根节点， 返回否
        return ChildLegal(p1->left,p2->left)&&ChildLegal(p1->right,p2->right);//递归判断左右根节点
    }
};