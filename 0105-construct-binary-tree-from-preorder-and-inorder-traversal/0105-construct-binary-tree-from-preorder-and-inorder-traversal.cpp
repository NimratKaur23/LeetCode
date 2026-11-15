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
TreeNode* build(vector<int>& preorder,unordered_map<int,int> &m,int low,int high,int &idx) {
    if(low>high)
     return NULL;
    
    TreeNode* node=new TreeNode(preorder[idx]);
    idx++;
    
    int id=m[node->val];
    node->left=build(preorder,m,low,id-1,idx);
    node->right=build(preorder,m,id+1,high,idx);

    return node;
}
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        unordered_map<int,int> m;
        for(int i=0;i<inorder.size();i++) {
            m[inorder[i]]=i;
        }

        int low=0;
        int high=inorder.size()-1;
        int idx=0;
        return build(preorder,m,low,high,idx);
    }
};