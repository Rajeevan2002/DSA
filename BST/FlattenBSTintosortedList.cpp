void inorder(TreeNode* root,TreeNode* &prev)
{
	if(!root)
		return NULL;
	inorder(root->left,prev);
	prev->left=NULL;
	prev->right=root;
	prev=root;
	inorder(root->right,prev);
}

void flatten(TreeNode* root)
{
	TreeNode* dummy=new TreeNode(-1);
	TreeNode* prev=dummy;
	inorder(root,prev);
	
	prev->left=NULL;
	prev->right=NULL;

	Node* ans=dummy->right;
	return ans; 
}