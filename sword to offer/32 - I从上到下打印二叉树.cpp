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

    vector<int> levelOrder(TreeNode* root) {
        vector<int> m;
        queue<TreeNode*> q;
        if(root == NULL)
            return m;
        q.push(root);
        while(!q.empty()){
            TreeNode *cur = q.front();
            int temp = cur->val;
            m.push_back(temp);
            q.pop();
            if(cur->left != NULL)
                q.push(cur->left);
            if(cur->right!=NULL)
                q.push(cur->right);
        }
        return m;
    }
};