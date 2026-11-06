/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
void LCA(TreeNode* root, TreeNode* p, TreeNode* q, TreeNode* &ans) {
    if(root==NULL)
    return;

    if(root==p || root==q) {
        ans=root;
        return;
    }

    if(root->val< p->val) {
        LCA(root->right,p,q,ans);
    }
    else if(root->val > q->val) {
        LCA(root->left,p,q,ans);
    }
    else{
        ans=root;
        return;
    }
}
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* ans=NULL;

        if(p->val < q->val) {
            LCA(root,p,q,ans);
        }
        else {
            LCA(root,q,p,ans);
        }

        return ans;
    }
};