/*包含min函数的栈
    定义栈的数据结构，请在该类型中实现一个能够得到栈中所含最小元素的min函数，时间复杂度应为O（1）

**用一个m栈来存储最小数，每次插入数据都与m栈的栈顶数据比较，实时更新m栈顶，使m栈顶一直是那个时候整个栈中最小的数据。
pop栈s栈顶数据时候，如果s栈顶数据和栈顶数据相等，那么说明整个最小数据要pop了，就也要pop掉m栈的栈顶数据。
**注意：m中可以存储多个相同的最小值，否则s中的一个最小值被pop出时会发生错误
*/
#include<iostream>
#include<stack>
using namespace std;

class Solution {
public:
    stack<int> s, m;
    void push(int value){
        s.push(value);
        if(m.empty()) m.push(value);//如果m为空，直接压入m
        else{
            if(value <= m.top())//如果value值比m栈顶的值小(或等于)
                m.push(value);//压入m
        }              
    }
    void pop(){
        if(s.top() == m.top()){//如果s栈顶的元素就是最小值之一， 
            m.pop();//m栈顶的最小值也要弹出一个
        }
        s.pop();
    }
    int top(){
        return s.top();
    }
    int min(){
        return m.top();
    }
};