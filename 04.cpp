/*重建二叉树
输入某二叉树的前序遍历和中序遍历的结果，重建出该二叉树。假设输入的前序中序遍历都不含重复的数字

要点：
1.当排列已经为零的时候 要记着返回 空指针
2.无法通过ret->val = x的方式为私有成员赋值， 需要new一个新对象，用构造函数赋值
3.当vector为空时，不能通过下标直接赋值，而是要使用push_back()函数
*/
#include<iostream>
#include<vector>
using namespace std;
struct TreeNode
{
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
    TreeNode(int x): 
        val(x), left(NULL), right(NULL){
    }
};
class Solution {
public:
    TreeNode* reConstructBinaryTree(vector<int> pre, vector<int> vin){
        if(!pre.size()) return nullptr;//当前序排列已经为零的时候 返回空指针
        
        vector <int> vinLeft, vinRight, preLeft, preRight;//分别是左右子树的中序、前序排列
        int leftlen = 0; int rightlen = 0;//左右子树的大小
        int root = pre[0]; //根节点的值是前序排列第一个
        struct TreeNode* ret = new TreeNode(root);
        int flag = 0;
        for(int i=0;i<vin.size();i++){//遍历中序排列
            if(vin[i] == root){//若找到根节点
                flag = 1;
                continue;
            }
            if(!flag){//若没找到根节点，是左子树的一部分
                vinLeft.push_back(vin[i]);
                leftlen++;
            }
            else{//在找到根节点之后，是右子树的一部分
                vinRight.push_back(vin[i]);
                rightlen++;
            }
            
        }
        for(int i=0;i<leftlen;i++){//给左子树的前序排列赋值
            preLeft.push_back(pre[i+1]); 
        }
        for(int i=0;i<rightlen;i++){//给右子树的前序排列赋值
            preRight.push_back(pre[i+1+leftlen]);
        }
        ret->left = reConstructBinaryTree(preLeft, vinLeft);
        ret->right = reConstructBinaryTree(preRight, vinRight);
        
        return ret;
    }
};

int main(){
    Solution s;
    vector<int> pre{1,2,4,7,3,5,6,8};
    vector<int> vin{4,7,2,1,5,3,8,6};
    s.reConstructBinaryTree(pre, vin);
}