ListNode* swapPairs(ListNode* head)
    {
        if(head==NULL) return NULL;
        if(!head->next)
            return head;
        ListNode* dummy=new ListNode(-1);
        ListNode* prev=dummy,*curr=head;
        
        while(curr && curr->next)
        {
            ListNode* nxtptr=curr->next->next;
            ListNode* second=curr->next;
            
            
            second->next=curr;
            curr->next=nxtptr;
            prev->next=second;
            
            prev=curr;
            curr=nxtptr;
        }
        
        return dummy->next;
    }