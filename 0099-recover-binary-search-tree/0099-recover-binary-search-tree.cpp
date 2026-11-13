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
void inorder(TreeNode* root, TreeNode* &prev, TreeNode* &galat1first, TreeNode* &galat1sec, 
            TreeNode* &galat2first,TreeNode* &galat2sec,int &galat) {
        if(root==NULL)
            return;

        inorder(root->left,prev,galat1first,galat1sec,galat2first,galat2sec,galat);

        if(prev==NULL)
          prev=root;
        else{
            if(root->val<=prev->val) {
                if(galat==0) {
                    //first wring
                    galat1first=prev;
                    galat1sec=root;
                    galat++;
                }
                else {
                    //second wrong
                    galat2first=prev;
                    galat2sec=root;
                    galat++;
                }
            }
            prev=root;
        }

        inorder(root->right,prev,galat1first,galat1sec,galat2first,galat2sec,galat);
 }

    void recoverTree(TreeNode* root) {
        TreeNode* prev=NULL;
        TreeNode* galat1first=NULL;
        TreeNode* galat1sec=NULL;
        TreeNode* galat2first=NULL;
        TreeNode* galat2sec=NULL;
        int galat=0;

        inorder(root,prev,galat1first,galat1sec,galat2first,galat2sec,galat);

        if(galat==1) {
            swap(galat1first->val,galat1sec->val);
        }
        else{
            swap(galat1first->val,galat2sec->val);
        }

        return;

    }
};