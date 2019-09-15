/*栈的压入弹出序列
    输入两个整数序列， 第一个序列表示栈的压入顺序，请判断第二个序列是否可能为该栈的弹出序列，假设压入栈的所有数字都不相等
*/
#include<iostream>
#include<stack>
#include<vector>
using namespace std;
class Solution {
public:
    bool isPopOrder_1(vector<int> pushV, vector<int> popV){
        stack<int> s;//用一个栈来模拟弹入弹出过程
        int i=0,j=0;//分别是弹入弹出序列的下标

        s.push(pushV[i++]);//先将弹入序列压入一位
        while(j<popV.size()){//循环终止条件：弹出序列读完
            if(s.top() != popV[j]){//如果栈顶不是弹出元素
                if(i<pushV.size())//如果弹入序列还有元素
                    s.push(pushV[i++]);//弹入序列压入一位
                else return false;//栈顶不是弹出元素且弹入序列已空，说明不符合条件
            }
            else{
                s.pop();
                j++;//弹出栈顶元素
            }
        }
        return true;//如果s为空，说明该序列可以实现 
    }


    bool isPopOrder_2(vector<int> pushV, vector<int> popV){//更好的写法
        stack<int> s;
        int idx = 0;
        for(int i=0;i<pushV.size();i++){
            s.push(pushV[i]);
            while(s.top() == popV[idx]){
                s.pop();
                idx++;
            }
        }
        return s.empty();
    }
};
int main(){
    vector<int> pushV{1, 2, 3, 4, 5};
    vector<int> popV{3, 4, 5, 1, 2};
    Solution s;
    cout<< s.isPopOrder_2(pushV, popV);   
}