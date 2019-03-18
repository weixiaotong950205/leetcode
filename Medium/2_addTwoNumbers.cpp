
// You are given two non-empty linked lists representing two non-negative integers. 
// The digits are stored in reverse order and each of their nodes contain a single digit. 
// Add the two numbers and return it as a linked list.
// You may assume the two numbers do not contain any leading zero, except the number 0 itself.
// Example:
// Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
// Output: 7 -> 0 -> 8
// Explanation: 342 + 465 = 807.

#include<iostream>
using namespace std;

struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
 };

#include<iostream>
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *head=NULL;
        head=new ListNode(0);
        ListNode *p=head;     
        int sum=0,carry=0;
       while(1)
       {
 
         carry=0;
         if( l1!=NULL)
         {
             p->val+=l1->val;
            l1=l1->next;
         }
        if(l2!=NULL)
         {
            p->val+=l2->val;
            l2=l2->next;
         }
         if(p->val>=10)
         {
            carry=1;
            p->val-=10;
         }
          if(l1!=NULL || l2!=NULL || carry==1)
          {
                p->next=new ListNode(carry);
                p=p->next;
          }
          else
              break;
        
       }
                            
        return head;      
        
        
    }
};

int main()
{
    ListNode *num1= new ListNode(2);
    num1->next=new ListNode(4);
    num1->next->next=new ListNode(3);
    ListNode *num2= new ListNode(5);
    num2->next=new ListNode(6);
    num2->next->next=new ListNode(4);
    Solution solu;
    ListNode* res=solu.addTwoNumbers(num1,num2);
    ListNode* cur=res;
    while(cur){
        cout<<cur->val<<endl;
        cur=cur->next;
    }
    return 0;
}