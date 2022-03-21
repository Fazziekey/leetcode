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
    set<int> sets;
    bool flag;
    bool findTarget(TreeNode* root, int k) {
        dfs(root, k);
        return flag;
    }
    void dfs(TreeNode *root, int k){
        if(root == nullptr || flag == true)
            return;
        if(sets.find(k - root->val) != sets.end()){
            flag = true;
            return;
        }else{
            sets.insert(root->val);
            dfs(root->right, k);
            dfs(root->left, k);
        }
    
            
    }
};