/* 左旋转字符串
    汇编语言中有一种移位指令叫做循环左移（ROL），现在有个简单的任务，就是用字符串模拟这个指令的运算结果。对于一个给定的字符序列S，
    请你把其循环左移K位后的序列输出。例如，字符序列S=”abcXYZdef”,要求输出循环左移3位后的结果，即“XYZdefabc”。是不是很简单？OK，搞定它！
*/

#include<iostream>
#include<queue>
using namespace std;

class Solution {
    string leftRotateString(string str, int n){//利用队列 非常简单
        queue <char> queue;
        string ret;
        for(auto c:str){
            queue.push(c);
        }
        char tmpchar;
        for(int i=0; i<n; i++){
            tmpchar = queue.front();
            queue.pop();
            queue.push(tmpchar);
        }
        while(!queue.empty()){
            ret += queue.front();
            queue.pop();
        }
        return ret;
    }
};