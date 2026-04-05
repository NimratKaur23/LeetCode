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
int position(vector<int> &inorder,int ele,int n) {

    for(int i=0;i<n;i++) {
        if(inorder[i]==ele) {
            return i;
        }
    }

    return -1;

}
TreeNode* solve(vector<int>& preorder, vector<int>& inorder, int &index,int InorderStart, int InorderEnd, int n) {

    //base condintion
    if(index>n || InorderStart>InorderEnd) {
        return NULL;
    }

    int ele= preorder[index++];
    TreeNode* root=new TreeNode(ele);

    int pos= position(inorder,ele,n);

    root->left= solve(preorder,inorder,index,InorderStart,pos-1,n);
    root->right= solve(preorder,inorder,index,pos+1,InorderEnd,n);

    return root;
}
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        int preorderIndex=0;
        int n=inorder.size();
        TreeNode* ans= solve(preorder,inorder,preorderIndex,0,n-1,n);

        return ans;
    }
};