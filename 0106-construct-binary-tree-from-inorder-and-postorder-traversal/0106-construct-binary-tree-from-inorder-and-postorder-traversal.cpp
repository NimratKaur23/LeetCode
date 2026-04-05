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
void creatingMapping(vector<int>& inorder, map<int,int> &nodeToIndex, int n) {
    for(int i=0;i<n;i++) {
        nodeToIndex[inorder[i]]=i;
    }
}

TreeNode* solve(vector<int>& inorder, vector<int>& postorder,int &index, map<int,int> &nodeToIndex,int InorderStart, int InorderEnd) {

    //base case
    if(index<0 || InorderStart>InorderEnd) {
        return NULL;
    }

    int ele=postorder[index--];
    TreeNode* root=new TreeNode(ele);

    int pos=nodeToIndex[ele];

    root->right= solve(inorder,postorder,index,nodeToIndex,pos+1,InorderEnd);
    root->left= solve(inorder,postorder,index,nodeToIndex,InorderStart,pos-1);

    return root;
    

}

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        
        int n=inorder.size();
        int postorderIndex=n-1;
        map<int,int> nodeToIndex;

        //craeting map
        creatingMapping(inorder,nodeToIndex,n);

        TreeNode* ans= solve(inorder,postorder,postorderIndex,nodeToIndex,0,n-1);

        return ans;
    }
};