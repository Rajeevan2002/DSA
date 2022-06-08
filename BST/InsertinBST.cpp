/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) 
    {
        TreeNode* nd=new TreeNode(val);
        if(root==NULL)
            return nd;
        TreeNode* curr=root;
        while(true)
        {
            if(val>curr->val)
            {
                if(curr->right==NULL)
                {
                    curr->right=nd;
                    return root;
                }
                else
                {
                    curr=curr->right;
                }
            }
            else if(val<curr->val)
            {
                if(curr->left==NULL)
                {
                    curr->left=nd;
                    return root;
                }
                else
                    curr=curr->left;
            }
        }
        
        return NULL;
        
    }
};