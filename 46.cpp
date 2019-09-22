/*孩子们的游戏
    约瑟夫环问题。有n个元素，每逢第m个删除。输出剩下的最后一个。    
*/
#include<iostream>

using namespace std;

struct ListNode{
    int val;
    struct ListNode* next;
    ListNode(int x):
        val(x), next(NULL){}
};

class Solution{
public:
    int LastRemaining_Solution(int n, int m){
        //构建环形链表
        if(!n) return -1;
        ListNode *head, *tail;
        int i = 0;
        head = new ListNode(i++);
        tail = head;
        while(i<n){
            ListNode *node = new ListNode(i++);
            tail->next = node;
            tail = node;
        }
        tail->next = head;
        //模拟过程
        ListNode *p = head;
        while(n>1){
            for(int i=0; i<m-2; i++) //要删除m-1位的数，需要在m-2处停下来，          
                p = p->next;
            p->next = p->next->next;//将next指向它的后方   
            p = p->next;//前进一位
            n--;
        }
        return p->val;
    }
};

int main(){
    Solution s;
    cout << s.LastRemaining_Solution(5, 3);
}