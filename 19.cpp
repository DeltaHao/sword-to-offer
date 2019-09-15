/*顺时针打印矩阵
    输入一个矩阵， 按照从外到里以顺时针的顺序依次打印出每一个数字。
*/
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> printMatrix(vector<vector<int> > matrix){
        vector<int> ret;
        int left = 0, right = matrix[0].size()-1, top = 0, bottom = matrix.size()-1;
        while(left<=right&&top<=bottom){
            for(int i=left;i<=right;i++) ret.push_back(matrix[top][i]);//从左到右
            for(int i=top+1;i<=bottom;i++) ret.push_back(matrix[i][right]);//从上到下
            if(top!=bottom)//从右到左 加一个判断，避免重复输出奇数行中最中间的那一行
                for(int i=right-1;i>=left;i--) ret.push_back(matrix[bottom][i]);
            if(left!=right)//从下到上 加一个判断，避免重复输出奇数列中最中间的那一列
                for(int i=bottom-1;i>top;i--) ret.push_back(matrix[i][left]);//注意这里是i>top而不是i>=top， 避免了将第一个数字重复输出
            left++, right--,top++, bottom--;
        }
        return ret;
    }
};
