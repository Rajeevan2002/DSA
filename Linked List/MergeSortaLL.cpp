/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeList(ListNode* l1,ListNode* l2)
    {
        ListNode* dummy=new ListNode(-1);
        ListNode* curr=dummy;
        
        while(l1 && l2)
        {
            if(l1->val<=l2->val)
            {
                curr->next=l1;
                l1=l1->next;
            }
            else
            {
                curr->next=l2;
                l2=l2->next;
            }
            curr=curr->next;
        }
        
        if(l1)
        {
            curr->next=l1;
            curr=curr->next;
        }
        if(l2)
        {
            curr->next=l2;
            curr=curr->next;
        }
        
        return dummy->next;
    }
    ListNode* sortList(ListNode* head) 
    {
        if(!head || !head->next)
            return head;
        
        ListNode* temp=head;
        ListNode* slow=head;
        ListNode* fast=head;
        
        while(fast && fast->next)
        {
            temp=slow;
            slow=slow->next;
            fast=fast->next->next;
        }
        
        
        temp->next=NULL;
        ListNode* l1=sortList(head);
        ListNode* l2=sortList(slow);
        
        return mergeList(l1,l2);
        
    }
};