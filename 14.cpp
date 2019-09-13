/*链表中倒数第k个节点
输入一个链表，输出该链表中倒数第k个节点

**双指针， 一先一后，先令快指针走到第k个节点， 然后快慢指针一起走 ，等快指针到尾的时候，慢指针到第k位 
*/
#include<iostream>

using namespace std;

struct ListNode
{
    int val;
    struct ListNode* next;
    ListNode(int x):
        val(x), next(NULL){
    }
};

class Solution {
public:
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k){
        ListNode* pre_p = pListHead;
        ListNode* post_p = pListHead;
        while(k--){
            if(!pre_p) return NULL;
            pre_p = pre_p->next;            
        }
        while(pre_p){
            pre_p = pre_p->next;
            post_p = post_p->next;
        }
        return post_p;
    }
};
