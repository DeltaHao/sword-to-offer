/*用两个栈实现一个队列
用两个栈来实现一个队列， 完成push和pop操作。队列中元素为int类型

心得：栈1与栈2底对底形成一个队列 必要时将尾部的移动到头部
*/
#include<iostream>
#include<stack>
using namespace std;

class Solution{
public:
    void push(int node){//入队列，直接进栈1
        stack1.push(node);
    }
    int pop(){//出队列
        if(stack2.empty()){//如果栈2为空，将栈1依次压入栈2
            while(!stack1.empty()){
                stack2.push(stack1.top());
                stack1.pop();
            }
        } 
        int ret = stack2.top();//若不为空，弹出栈2
        stack2.pop();  
        return ret;   
    }
private:
    stack<int> stack1;
    stack<int> stack2;
};