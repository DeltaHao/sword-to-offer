/*合并两个有序的链表
    输入两个单调递增的链表， 输出两个链表合成后的链表， 当然我们需要合成后的链表满足单调不减规则。
*/
#include<stdio.h>

using namespace std;
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x):
        val(x), next(NULL){
    }
};
class Solution{
public:
    ListNode* merge(ListNode* pHead1, ListNode* pHead2){
        ListNode* retHead;
        ListNode* p = pHead1;
        ListNode* q = pHead2;
        ListNode* pre, * post;
        if(p->val<q->val){
            retHead = new ListNode(p->val);
            p = p->next;
        }
        else{
            retHead = new ListNode(q->val);
            q = q->next;
        }
        pre = retHead;
        while(p && q){
            if(p->val < q->val){
                post = new ListNode(p->val);
                p = p->next;               
            }
            else{
                post = new ListNode(q->val);
                q = q->next;
            }
             pre->next = post;
             pre = post;
        }
        while(p){
            post = new ListNode(p->val);
            p = p->next;
            pre->next = post;
            pre = post;
        }
        while(q){
            post = new ListNode(q->val);
            q = q->next;
            pre->next = post;
            pre = post;
        }
        return retHead;
    }
};

int main(){
    ListNode* head1 = new ListNode(1);
    ListNode* head2 = new ListNode(2);
    ListNode* p1 = head1;
    ListNode* p2 = head2;   
    for(int i=2;i<5;i++){
        ListNode* q1 = new ListNode(2*i-1);
        ListNode* q2 = new ListNode(2*i);
        p1->next = q1;
        p2->next = q2;
        p1 = q1;
        p2 = q2;
    }
    Solution s;
    ListNode* ret = s.merge(head1, head2);
}