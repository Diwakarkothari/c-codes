
 /* Definition for singly-linked list.*/
 struct ListNode {
     int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
};

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void reorderList(ListNode* head) {
        if(head->next==NULL)
            return;
        if(head==NULL)
            return;
        stack<ListNode*> s;
        ListNode* fast=head;
        ListNode* slow=head;
        while(fast!=NULL && fast->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode* h1=head;
        ListNode* h2=slow->next;
        slow->next=NULL;

        ListNode* curr=h2;
        ListNode* pre=NULL;
        while(curr!=NULL)
        {
            ListNode* forward=curr->next;
            curr->next=pre;
            pre=curr;
            curr=forward;
        }
        h2=pre;

        ListNode* ptr1=h1;
        ListNode* ptr2=h2;
        while(ptr1!=NULL && ptr2!=NULL)
        {
            ListNode* n1=ptr1->next;
            ptr1->next=ptr2;

            ListNode* n2=ptr2->next;
            ptr2->next=n1;

            ptr1=n1;
            ptr2=n2;
        }

    }
};