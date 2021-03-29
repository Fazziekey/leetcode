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
    TreeNode* mirrorTree(TreeNode* root) {
        struct TreeNode *p,*q;
        if(root == NULL)
            return NULL;
        if(root->left == NULL && root->right == NULL)
            return root;
        if(root->left == NULL){
            root->left = root->right;
            root->right = NULL;
            mirrorTree(root->left);
            return root;
        }
        if(root->right == NULL){
            root->right = root->left;
            root->left = NULL;
            mirrorTree(root->right);
            return root;
        }
        p = root->left;
        q = root->right;
        root->right = p;
        root->left = q;
        mirrorTree(root->left);
        mirrorTree(root->right);
        return root;
    }
};