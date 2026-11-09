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
void PathSum(TreeNode* root, int target, int sum, bool &ans) {
    if(root==NULL)
    return;

    sum+=root->val;

    if(root->left==NULL && root->right==NULL) {
        if(sum==target) {
            ans=true;
            return;
        }
    }

    PathSum(root->left,target,sum,ans);
    PathSum(root->right,target,sum,ans);

    return ;


}
    bool hasPathSum(TreeNode* root, int targetSum) {
      bool ans=false;

      if(root==NULL)
       return ans;

       int sum=0;
      
      PathSum(root,targetSum,sum,ans);

      return ans;


        
    }
};