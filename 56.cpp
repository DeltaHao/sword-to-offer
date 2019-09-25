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
        if(!pHead) return nullptr;//如果是空结点，直接返回空结点
        ListNode *fast = pHead->next;//不然这一步会出错
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
                fast = pHead->next;//但是这里有一个问题，最后一个节点来不及判断，所以要在循环结束后判断
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
        if(repeatVals.find(pHead->val) != repeatVals.end()) return nullptr;//判断最后一个节点是否重复
        return pHead;
    }
};

int main(){
    int arr[3]{1,3,3};
    ListNode* head = new ListNode(arr[0]);
    ListNode* p = head;   
    for(int i=1;i<3;i++){
        ListNode* q = new ListNode(arr[i]);
        p->next  = q;
        p = q;
    }
    Solution s;
    ListNode* ret = s.deleteDuplication(head);
}