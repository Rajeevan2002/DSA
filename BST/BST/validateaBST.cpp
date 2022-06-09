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
    bool isValidBST(TreeNode* root) {
        if(root->val==INT_MAX && root->left==NULL && root->right==NULL)
            return true;
        if(root->val==INT_MIN && root->left==NULL && root->right==NULL)
            return true;
            
        return isValid(root,LLONG_MIN,LLONG_MAX);
    }
    
    bool isValid(TreeNode* root,long long mini,long long maxi)
    {
        if(root==NULL)
            return true;
        
        if((root->val>maxi) || (root->val<mini))
            return false;
        
        if(isValid(root->left,mini,(long long)root->val-1) && (isValid(root->right,(long long)root->val+1,maxi)))
            return true;
        
        return false;
    }
};