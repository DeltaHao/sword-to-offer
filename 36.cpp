/*输入两个链表，找出他们的第一个公共节点*/

#include<iostream>

using namespace std;
struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x):
        val(x), next(NULL){}
};

class Solution {
    ListNode* FindFirstCommenNode(ListNode* pHead1, ListNode* pHead2){
        ListNode* p1 = pHead1;
        ListNode* p2 = pHead2;
        int len1=0, len2=0;
        int sub;
        while(p1){//计算链表1的长度
            len1++;
            p1= p1-> next;
        }
        while(p2){//计算链表2的长度
            len2++;
            p2= p2-> next;
        }
        p1 = pHead1;
        p2 = pHead2;
        if(len1>len2){//若链表1长， 让其先走
            sub = len1 - len2;
            while(sub){
                p1= p1-> next;
                sub--;
            }
        }
        if(len1<len2){//若链表2长， 让其先走
            sub = len2 - len1;
            while(sub){
                p2= p2-> next;
                sub--;
            }
        }
        while(p1){//一起走，返回第一个相同的节点
            if(p1 == p2) return p1;
            p1 = p1->next;
            p2 = p2->next;
        }
        return NULL;
    }
};