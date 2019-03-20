// Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.

// Example:

// Input: 1->2->4, 1->3->4
// Output: 1->1->2->3->4->4
#include<iostream>
using namespace std;

 struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode dummy{0};
        ListNode *res=&dummy;
        while(l1&&l2)
        {
            if(l1->val<=l2->val)
            {
                res->next=l1;
                l1=l1->next;
            }
            else{
                res->next=l2;
                l2=l2->next;
            }
            res=res->next;
        }
        res->next=l1?l1:l2;
        return dummy.next;
        
    }
};

int main(){
    ListNode* L1=new ListNode(1);
    L1->next=new ListNode(2);
    L1->next->next=new ListNode(4);
    ListNode* L2=new ListNode(1);
    L2->next= new ListNode(3);
    L2->next->next=new ListNode(4);
    Solution solu;
    ListNode* head=solu.mergeTwoLists(L1,L2);
    ListNode* cur=head;
    while(head){
        cout<<cur->val<<endl;
        cur=cur->next;
    }

}