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
bool Mirror(TreeNode* r1, TreeNode* r2) {

    //base case
    if(r1==NULL && r2==NULL) {
        return true;
    }

    if(r1==NULL || r2==NULL) {
        return false;
    }

    bool left= Mirror(r1->left, r2->right);
    bool right= Mirror(r1->right, r2->left);
    bool value= r1->val == r2->val;

    if(left && right && value) {
        return true;
    }
    else {
        return false;
    }
}
    bool isSymmetric(TreeNode* root) {
        return Mirror(root->left,root->right);
    }
};