/*链表中环的入口结点
    给一个链表，若其中包含环，请找出该列表的环的入口节点，否则 输出NULL

**reinterpret_cast 用来重新解释数据的含义，如可以将4位的指针值解释为整型值

*/

#include<iostream>
#include<vector>
using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x):
        val(x), next(nullptr){}
};

class Solution{
public:
    ListNode* EntryNodeOfLoop(ListNode* pHead){
        vector<int> pointers;//用来将地址转化为整型存起来
        ListNode *p = pHead;
        while(p){
            for( auto numP: pointers){
                if(numP == reinterpret_cast<int>(p)){//如果数组中已经有该指针指向的地址（即该节点已被走过）
                    return p;
                }
            }
            pointers.push_back(reinterpret_cast<int>(p));//将节点地址加入数组
            p = p->next;
        }
        return p;
    }
};

int main(){
    ListNode *head = new ListNode(2);
    head->next = head;
    Solution s;
    cout << s.EntryNodeOfLoop(head);
}