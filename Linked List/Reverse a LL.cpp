struct Node* reverseList(struct Node *head)
    {
        // code here
        // return head of reversed list
        Node* dummy=NULL;
        while(head!=NULL)
        {
            Node* next=head->next;
            head->next=dummy;
            dummy=head;
            head=next;
        }
        
        return dummy;
    }