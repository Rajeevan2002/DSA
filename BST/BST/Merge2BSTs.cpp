class Solution
{
    public:
    //Function to return a list of integers denoting the node 
    //values of both the BST in a sorted order.
    void ino(Node *root,vector<int> &res1)
    {
        if(root==NULL)
            return;
        ino(root->left,res1);
        res1.push_back(root->data);
        ino(root->right,res1);
    }
    vector<int> merge(Node *root1, Node *root2)
    {
       //Your code here
       vector<int> res1;
       //vector<int> res2;
       ino(root1,res1);
       ino(root2,res1);
       sort(res1.begin(),res1.end());
       return res1;
    }
};