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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (root == nullptr)
        {
            return res;
        }
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty())
        {
            vector<int> currs;
            for (int i = q.size() - 1; i >= 0; --i)
            {
                TreeNode* curr = q.front();
                q.pop();
                currs.push_back(curr->val);
                if (curr->left)
                {
                    q.push(curr->left);
                }
                if (curr->right)
                {
                    q.push(curr->right);
                }
            }
            // 当前res.size()为偶数时无需翻转，否则要翻转
            if (res.size() & 1)
            {
                reverse(currs.begin(), currs.end());
            }
            res.push_back(currs);
        }

        return res;
    }
};


