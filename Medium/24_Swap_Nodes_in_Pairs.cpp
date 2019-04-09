// Given a linked list, swap every two adjacent nodes and return its head.

// You may not modify the values in the list's nodes, only nodes itself may be changed.

 

// Example:

// Given 1->2->3->4, you should return the list as 2->1->4->3.

#include<iostream>

using namespace std;

  struct ListNode {
     int val;
      ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
  };
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(head==NULL) return head;
        
        ListNode* preNode= new ListNode(-1);
        ListNode* left=preNode;
        ListNode* mid=head;
        preNode->next=head;
        if(head->next==NULL)//此处出现了错误，用了=而非==导致程序到这里后就会跳出
            return head;
        ListNode *right=mid->next;
        while(mid &&mid->next){
            mid->next=right->next;
            right->next=mid;
            left->next=right;

            left=mid;
            mid=left->next;
            if(mid)
                right=mid->next;
        }
        return preNode->next;
    }
};

int main(){
    ListNode* head=new ListNode(1);
    ListNode* cur=head;
    for(int i=2;i<=4;i++)
    {
        cur->next=new ListNode(i);
        cur=cur->next;
    }
    cur=head;
    // while(cur){
    //     cout<<cur->val<<endl;
    //     cur=cur->next;
    // }
    Solution solu;
    ListNode *nhead= solu.swapPairs(head);
    cur=nhead;
    while(cur){
        cout<<cur->val<<endl;
        cur=cur->next;
    }
}