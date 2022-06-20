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
    ListNode* reverseLL(ListNode* head)
    {
        ListNode* temp=NULL;
        while(head!=NULL)
        {
            ListNode* next=head->next;
            head->next=temp;
            temp=head;
            head=next;
        }
        return temp;
    }
    bool isPalindrome(ListNode* head) 
    {
        ListNode* slow=head;
        ListNode* fast=head;
        
        while(fast->next && fast->next->next)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        slow->next=reverseLL(slow->next);
        
        ListNode* temp=head;
        slow=slow->next;
        while(slow!=NULL)
        {
            if(slow->val!=temp->val)
                return false;
            slow=slow->next;
            temp=temp->next;
        }
        return true;
    }
};