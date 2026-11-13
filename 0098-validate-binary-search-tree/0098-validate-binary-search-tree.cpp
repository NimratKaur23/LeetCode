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
void valid(TreeNode* root, TreeNode* &prev,bool &ans) {
    if(root==NULL)
    return;

    valid(root->left,prev,ans);
    
    //firstnode
    if(prev==NULL) {
      prev=root;
    }
    else{
        if(root->val <= prev->val) {
            //wrong
            ans=false; 
     }
      prev=root;  
    }

    valid(root->right,prev,ans);
}
    bool isValidBST(TreeNode* root) {
        bool ans=true;
        TreeNode* prev=NULL;
        
        valid(root,prev,ans);

        return ans;
        
    }
};