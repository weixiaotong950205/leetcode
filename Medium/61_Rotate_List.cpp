// Given a linked list, rotate the list to the right by k places, where k is non-negative.

// Example 1:

// Input: 1->2->3->4->5->NULL, k = 2
// Output: 4->5->1->2->3->NULL
// Explanation:
// rotate 1 steps to the right: 5->1->2->3->4->NULL
// rotate 2 steps to the right: 4->5->1->2->3->NULL
// Example 2:

// Input: 0->1->2->NULL, k = 4
// Output: 2->0->1->NULL
// Explanation:
// rotate 1 steps to the right: 2->0->1->NULL
// rotate 2 steps to the right: 1->2->0->NULL
// rotate 3 steps to the right: 0->1->2->NULL
// rotate 4 steps to the right: 2->0->1->NULL

#include<iostream>
using namespace std;

struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };

  class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(k==0||head==NULL||head->next==NULL)return head;
    int length=1;
    
    for(ListNode* node=head;node->next!=NULL;node=node->next)
        length++;
    int times=k%length;
    for(int i=0;i<times;i++)
        rotateOnce(head);
    return head;
        
    }
private:
   void rotateOnce(ListNode* &head)
    {
        ListNode* node=head;
        while(node->next->next !=NULL )
            node=node->next;
        ListNode* temp=head;
        head=node->next;
        head->next=temp;
        node->next=NULL;
    }
};

int main(){
    ListNode* head=new ListNode(1);
    ListNode* cur=head;
    for(int i=2;i<=5;i++){
        cur->next=new ListNode(i);
        cur=cur->next;
    }
    Solution solu;
    head=solu.rotateRight(head,3);
    cur=head;
    while(cur){
          cout<<cur->val<<endl;
          cur=cur->next;
    }
    return 0;
}