// Given a sorted linked list, delete all duplicates such that each element appear only once.

// Example 1:

// Input: 1->1->2
// Output: 1->2
// Example 2:

// Input: 1->1->2->3->3
// Output: 1->2->3
#include<iostream>

using namespace std;

 struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* cur=head;
        while(cur!=NULL)
        {
            if(cur->next!=NULL&&cur->val==cur->next->val)//首先判断最后一个节点是否为空,用->比用.取值速度提高了一倍
            {
                 ListNode* p=cur->next->next;
                 //free(cur->next);
                 cur->next=p;
                 continue;
            }
            cur=cur->next;
        }
        return head;
    }
};

int main(){
    ListNode *head=new ListNode(1);
    head->next=new ListNode(1);
    head->next->next=new ListNode(2);
    Solution solu;
    ListNode* res=solu.deleteDuplicates(head);
    ListNode* cur=res;
    while(cur){
        cout<<cur->val<<endl;
        cur=cur->next;
    }
    return 0;
}