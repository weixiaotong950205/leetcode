#include<iostream>

using namespace std;

  struct ListNode {
     int val;
     ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };
 
 class Solution {
 public:
	 ListNode* removeNthFromEnd(ListNode* head, int n) {
		 int count = 0;
		 ListNode *cur = head;
		 while (cur)
		 {
			 ++count;
			 cur = cur->next;
		 }
		 if (n == 0 || n > count) return head;
		 if (n == count)
		 {
			 ListNode *newhead = head->next;
			 delete head;
			 return newhead;
		 }
		 cur = head;
		 for (int i = 1; i < count - n; i++, cur = cur->next)
			 ;

		 if (cur->next)
		 {
			 ListNode* tmp = cur->next;
			 cur->next = tmp->next;
			 delete tmp;
			 tmp = NULL;
		 }
		 else
		 {
			 head = cur->next;
			 delete cur;
		 }
		 return head;
	 }
  };

 int main()
 {
	 
	 ListNode *head = new ListNode(1);
	 ListNode *cur = head;
	 for (int i = 2; i <= 5; i++)
	 {
		 cur->next = new ListNode(i);
		 cur = cur->next;
	 }
	 cur = head;
	 while (cur)
	 {
		 cout << cur->val << endl;
		 cur = cur->next;
	 }
	
	 system("pause");
	 return 0;
 }
