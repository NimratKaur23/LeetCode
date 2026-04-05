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
int Height(TreeNode* root) {

    if(root==NULL) {
        return 0;
    }

    int leftHeight= Height(root->left);
    int rightHeight= Height(root->right);

    int ans=max(leftHeight,rightHeight)+1;
    return ans;
}

pair<bool,int> isBalancedFast(TreeNode* root) {

    if(root==NULL) {
        pair<bool,int> p=make_pair(true,0);
        return p;
    }

    pair<bool,int> left=isBalancedFast(root->left);
    pair<bool,int> right=isBalancedFast(root->right);

    bool leftAns=left.first;
    bool rightAns=right.first;

    pair<bool,int> ans;
    ans.second=max(left.second,right.second)+1;

    bool difference= abs(left.second-right.second)<=1;


    if(leftAns && rightAns && difference) {
        ans.first= true;
    }
    else {
        ans.first=false;
    }


return ans;

}


    bool isBalanced(TreeNode* root) {


/*
        if(root==NULL) {
            return true;
        }

        bool left=isBalanced(root->left);
        bool right=isBalanced(root->right);

        bool ans= abs(Height(root->left)-Height(root->right))<=1;

        if(left&& right && ans) {
            return true;
        }
        else {
            return false;
        }
        */


        return isBalancedFast(root).first;
        

    
        
    }
};