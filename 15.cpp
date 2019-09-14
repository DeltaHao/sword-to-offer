/*反转链表
    输入一个链表， 反转链表后， 输出新链表的表头。
*/
#include<iostream>
#include<stack>
using namespace std;

struct ListNode{
    int val;
    struct ListNode* next;
    ListNode(int x) :
        val(x), next(NULL){
        }
};

class Solution {
public:
    ListNode* ReverseList(ListNode* pHead){
        stack<int> s;
        ListNode* p = pHead;
        while(p){//先将原链表依次入栈
            s.push(p->val);
            p = p->next;
        }
        ListNode* retHead = new ListNode(s.top());//创建一个新链表
        s.pop();
        p = retHead;
        while(!s.empty()){//依次出栈为新链表赋值
            ListNode* q = new ListNode(s.top());
            s.pop();
            p->next = q;
            p = q;        
        }
        return retHead;
    }
};

int main(){
    ListNode* head = new ListNode(0);
    ListNode* p = head;
    for(int i=1;i<5;i++){
        ListNode* q = new ListNode(i);
        p->next  = q;
        p = q;
    }
    Solution s;
    ListNode* ret = s.ReverseList(head);
}