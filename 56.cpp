/*删除链表中重复的节点
    在一个排序的链表中，存在重复的节点，请删除该链表中重复的节点，重复的节点不保留 返回头指针
*/

#include<iostream>
#include<set>
using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x):
        val(x), next(nullptr){}
};

class Solution{
public:
    ListNode* deleteDuplication(ListNode* pHead){
        ListNode *fast = pHead->next;
        ListNode *slow = pHead;
        set <int> repeatVals;
        while(fast){//第一遍 记录下所有重复的节点
            if(fast->val == slow->val){
                repeatVals.insert(fast->val);
            }
            fast = fast->next;
            slow = slow->next;
        }
        //重置指针
        fast = pHead->next;
        slow = pHead;
        while(fast){//第二遍，如果有重复的节点，删除之
            if(repeatVals.find(pHead->val) != repeatVals.end()){//如果头结点重复，直接删除头结点                               
                pHead = pHead->next;
                //重置fast和slow                               
                slow = pHead;
                fast = pHead->next;
                if(!pHead->next) return nullptr;//如果已经是最后一位.返回空节点
                continue;                                
            }
            if(repeatVals.find(fast->val) != repeatVals.end()){//如果有重复的节点，删除之
                fast = fast->next;
                slow->next = fast;
            }
            else{
                fast = fast->next;
                slow = slow->next;
            }
        }
        return pHead;
    }
};

int main(){
    ListNode* head = new ListNode(1);
    ListNode* p = head;
    int arr[7]{1,1,2,3,4,4,5};
    for(int i=1;i<7;i++){
        ListNode* q = new ListNode(arr[i]);
        p->next  = q;
        p = q;
    }
    Solution s;
    ListNode* ret = s.deleteDuplication(head);
}