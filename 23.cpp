/*二叉搜索树的后序遍历序列
    输入一个整数数组，判断它是不是某二叉搜索树的后续遍历的结果。

二叉查找树（Binary Search Tree），（又：二叉搜索树，二叉排序树）它或者是一棵空树，或者是具有下列性质的二叉树： 若它的左子树不空，则左子树上
所有结点的值均小于它的根结点的值； 若它的右子树不空，则右子树上所有结点的值均大于它的根结点的值； 它的左、右子树也分别为二叉排序树。

**这里存在一个疑问： 牛客网上有一个测试用例，输入空数组，返回false。 然而据以上来自百度百科的定义， 空树也是一棵二叉查找树。
*/
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    bool VerifySquenceOfBST(vector<int> sequence){
        if(sequence.size() == 0) return true;//空树是二叉搜索树
        bool flag = 1;
        int len = sequence.size();
        vector<int> left, right;
        for(int i=0;i<len-1;i++){//遍历sequence
            if(sequence[i]>sequence[len-1]){//出现比根节点大的数， 
                flag = 0;//说明进入右子树区
            }
            if(flag) left.push_back(sequence[i]);//若在左子树区，加入左子树数组
            else{
                if(sequence[i]<sequence[len-1]) return false;//若在进入右子树区之后发现有比根节点小的数， 说明这不是一个二叉搜索树
                else right.push_back(sequence[i]);//没有的话加入右子树区
            }
        }
        return (VerifySquenceOfBST(left) && VerifySquenceOfBST(right));
    }
};
int main(){
    vector<int> sequence{7, 3, 2, 5, 1, 6, 4};
    Solution s;
    cout << s.VerifySquenceOfBST(sequence);
}