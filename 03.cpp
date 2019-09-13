/*从头到尾打印链表
输入一个链表， 按链表值从尾到头地返回一个ArrayList
*/
#include<iostream>
#include<vector>
#include<stack>
using namespace std;
struct ListNode{
    int val;
    struct ListNode* next;
    ListNode(int x):
        val(x), next(NULL){
    }
};

class Solution {
public:
    vector<int> printListFromTailToHead(ListNode* head){
        stack<int> s;//建立一个栈，先进后出
        ListNode *p = head;
        vector<int> array;
        while(p){
            s.push(p->val);
            p = p->next;
        }
        p = head;
        int count = 0;
        while(!s.empty()){
            array.push_back(s.top());
            s.pop();
        }
        return array;
    }
};
