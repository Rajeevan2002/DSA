int CountNodes(Node* root)
{
    Node* curr=root;
    int count=0;
    stack<Node*> st;
    
    while(curr)
    {
        if(!curr->left)
        {
            count+=1;
            curr=curr->right;
        }
        else
        {
            Node* temp=curr->left;
            
            while(temp->right && temp->right!=curr)
                temp=temp->right;
                
            if(temp->right==NULL)
            {
                temp->right=curr;
                curr=curr->left;
            }
            else if(temp->right==curr)
            {
                temp->right=NULL;
                count+=1;
                curr=curr->right;
            }
        }
    }
    return count;
}
float findMedian(struct Node *root)
{
    //Code here
    int count=CountNodes(root);
    int currCount = 0;
    struct Node *current = root, *pre, *prev;
 
    while (current != NULL)
    {
        if (current->left == NULL)
        {
            // count current node
            currCount++;
 
            // check if current node is the median
            // Odd case
            if (count % 2 != 0 && currCount == (count+1)/2)
                return prev->data;
 
            // Even case
            else if (count % 2 == 0 && currCount == (count/2)+1)
                return float(float((prev->data + current->data))/2.0);
 
            // Update prev for even no. of nodes
            prev = current;
 
            //Move to the right
            current = current->right;
        }
        else
        {
            /* Find the inorder predecessor of current */
            pre = current->left;
            while (pre->right != NULL && pre->right != current)
                pre = pre->right;
 
            /* Make current as right child of its inorder predecessor */
            if (pre->right == NULL)
            {
                pre->right = current;
                current = current->left;
            }
 
            /* Revert the changes made in if part to restore the original
              tree i.e., fix the right child of predecessor */
            else
            {
                pre->right = NULL;
 
                prev = pre;
 
                // Count current node
                currCount++;
 
                // Check if the current node is the median
                if (count % 2 != 0 && currCount == (count+1)/2 )
                    return float(current->data);
 
                else if (count%2==0 && currCount == (count/2)+1)
                    return float(float((prev->data+current->data))/2);
 
                // update prev node for the case of even
                // no. of nodes
                prev = current;
                current = current->right;
 
            } /* End of if condition pre->right == NULL */
        } 
    } 
}