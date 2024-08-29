/*
 * Definition for singly-linked list.*/
#include<bits/stdc++.h>
using namespace std;
 struct ListNode {
     int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
 
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        //   2 PASS  NOT OPTIMAL
        // int count=0;
        // ListNode* ptr=head;
        // while(ptr!=NULL)
        // {
        //     count++;
        //     ptr=ptr->next;
        // }

        // if(count==1 && n>=1)
        //     return NULL;

        // int diff=count-n;
        // if(diff==0)
        //     return head->next;
        // ptr=head;
        // for(int i=0;i<diff-1;i++)
        // {
        //     ptr=ptr->next;
        // }
        // ptr->next=ptr->next->next;
        // return head;

        // 1 PASS mein OPTIMAL
        ListNode* newnode=new ListNode();
        newnode->next=head;
        ListNode* slow=newnode;
        ListNode* fast=newnode;

        // GAP create kar rahe hai
        for(int i=1;i<=n;i++)
        {
            fast=fast->next;
        }

        while(fast->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next;
        }
        // SLOW ka next delete karna hai
        ListNode* p=slow->next;
        slow->next=slow->next->next;
        delete p;
        return newnode->next;
    }
};