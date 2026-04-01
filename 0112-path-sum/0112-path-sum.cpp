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
    void isPath(TreeNode* root, int targetSum, int sum,bool &ans) {
        

        if(root==NULL) {
            return;
        }

        sum+=root->val;

        if(root->left==NULL && root->right==NULL) {
            if(sum==targetSum) {
                ans=true;
                return;
            }
            else {
                return;
            }
        }

         isPath(root->left,targetSum,sum,ans);
         isPath(root->right,targetSum,sum,ans);


    }

    bool hasPathSum(TreeNode* root, int targetSum) {

       bool ans=false; 

        if(root==NULL) {
            return ans;
        }

        int sum=0;

        isPath(root,targetSum,sum,ans);

        return ans;
        
    }
};