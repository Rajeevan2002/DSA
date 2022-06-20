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
    ListNode* mergeKLists(vector<ListNode*>& lists) 
    {
        if(lists.size()==0)
            return NULL;
        
        
        while(lists.size()>1)
        {
            vector<ListNode*> merge;
            
            for(int i=0;i<lists.size();i+=2)
            {
                ListNode* l1=lists[i];
                ListNode* l2;
                if(i+1<lists.size())
                    l2=lists[i+1];
                else
                    l2=NULL;
                
                merge.push_back(mer(l1,l2));
            }
            lists=merge;
        }
        
        return lists[0];
    }
    
    ListNode* mer(ListNode* l1,ListNode* l2)
    {
        if(l2==NULL)
            return l1;
        else if(l1==NULL)
            return l2;
        
        
        if(l1->val > l2->val)
        {
            ListNode* temp=l1;;
            l1=l2;
            l2=temp;
        }
        
        ListNode* res=l1;
        while(l1!=NULL && l2!=NULL)
        {
            ListNode* tmp=l1;
            while(l1!=NULL && l1->val<=l2->val)
            {
                tmp=l1;
                l1=l1->next;
            }
            
            tmp->next=l2;
            
            tmp=l1;
            l1=l2;
            l2=tmp;
        }
        
        return res;
    }
};