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
    int deep (TreeNode* root){
        if(root)
            return max(deep(root->left),deep(root->right)) + 1;
        else
            return 0;
    }
    bool isBalanced(TreeNode* root) {
        if(root == nullptr)
            return true;
        else if(abs(deep(root->left)-deep(root->right))>1)
            return false;
        else 
            return isBalanced(root->left)&&isBalanced(root->right);
    }
};