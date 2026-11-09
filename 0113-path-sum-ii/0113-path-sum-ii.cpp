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
void PS(TreeNode* root, int target, int sum,vector<vector<int>> &ans, vector<int> diary) {
    if(root==NULL)
    return;

    sum=sum+root->val;
    diary.push_back(root->val);

    if(root->left==NULL && root->right==NULL) {
        if(sum==target) {
            ans.push_back(diary);
            diary.pop_back();
            return;
        }
    }

    PS(root->left,target,sum,ans,diary);
    PS(root->right,target,sum,ans,diary);
    diary.pop_back();
    return;
}
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> diary;
        int sum=0;

        PS(root,targetSum,sum,ans,diary);

        return ans;
    }
};