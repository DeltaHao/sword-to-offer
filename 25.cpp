/*复杂链表的复制
    输入一个复杂链表（每个节点中有节点值，以及两个指针，一个指向下一个节点，另一个特殊指针指向任意一个节点，返回结果为复制后复杂链表的head
*/
#include<iostream>

using namespace std;
struct RandomListNode{
    int label;
    RandomListNode *next, *random;
    RandomListNode(int x): 
        label(x), next(NULL), random(NULL){}
};
class Solution {
public:
    RandomListNode* clone(RandomListNode* pHead){
        RandomListNode* p = pHead;
        //在每一个节点后插入由它复制出的新节点
        while(p){
            RandomListNode* node = new RandomListNode(p->label);
            node->next = p->next;
            p->next = node;
            p = node->next;
        }
        //重新遍历链表， 以复制随机指针， 新链表random指向的节点在旧链表random指向的节点的后一位
        p = pHead;
        RandomListNode* q = pHead->next;
        while(p){
            if(p->random)
                q->random = p->random->next;
            p = p->next->next;
            q = q->next?q->next->next:NULL;
        }
        //分离新旧链表
        p = pHead;
        RandomListNode* qHead = pHead->next;
        q = qHead;
        while(p){
            p->next = p->next->next;
            q->next = q->next?q->next->next:NULL;
            p = p->next;
            q = q->next;
        }
        return qHead;
    }
};

int main(){
    RandomListNode* head1 = new RandomListNode(0);
    RandomListNode* p1 = head1;   
    for(int i=1;i<5;i++){
        RandomListNode* q1 = new RandomListNode(i);
        if(i%2)
            q1->random = q1;
        else 
            q1->random = head1;
        p1->next = q1;
        p1 = q1;
    }
    Solution s;
    RandomListNode* head2 =  s.clone(head1);
}