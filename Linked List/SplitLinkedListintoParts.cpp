vector<ListNode*> splitListToParts(ListNode* head, int k) 
    {
        int count=0;
        ListNode* temp=head;
        while(temp)
        {
            temp=temp->next;
            count+=1;
        }
        
        vector<ListNode*> res;
        int numNodes=count/k;
        int extra=count%k;
         temp=head;
        while(temp)
        {
            res.push_back(temp);
            int curr=1;
            while(curr<numNodes)
            {
                temp=temp->next;
                curr+=1;
            }
            
            if(extra>0 && count>k)
            {
                temp=temp->next;
                extra-=1;
            }
            
            ListNode* prev=temp->next;
            temp->next=NULL;
            temp=prev;
        }
        
        while(count<k)
        {
            res.push_back(NULL);
            count+=1;
        }
        
        return res;