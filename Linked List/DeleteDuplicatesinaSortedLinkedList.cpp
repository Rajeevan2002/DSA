ListNode* deleteDuplicates(ListNode* head) 
    {
        ListNode* dummy=head;
        while(head && head->next)
        {
            while(head->next && head->val==head->next->val)
            {
                head->next=head->next->next;
            }
            head=head->next;
        }
        return dummy;
        
    }