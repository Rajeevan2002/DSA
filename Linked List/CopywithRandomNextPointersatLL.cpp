/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) 
    {
        Node* iter=head;
        Node* temp=head;
        
        while(iter!=NULL)
        {
            temp=iter->next;
            
            Node* copy=new Node(iter->val);
            iter->next=copy;
            copy->next=temp;
            
            iter=iter->next->next;
        }
        
        iter=head;
        while(iter!=NULL)
        {
            if(iter->random!=NULL)
            {
                iter->next->random=iter->random->next;
            }
            iter=iter->next->next;
        }
        
        iter = head;
          Node *pseudoHead = new Node(0);
          Node *copy = pseudoHead;

          while (iter != NULL) {
            temp = iter->next->next;

            // extract the copy
            copy->next = iter->next;

            // restore the original list
            iter->next = temp;
              
            copy = copy -> next; 
            iter = temp;
          }

          return pseudoHead->next;
        
    }
};