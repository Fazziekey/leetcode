/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
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
        if (root != nullptr)
        {
            queue<TreeNode*> q;
            q.push(root);
            while (!q.empty())
            {
                int n = q.size();
                vector<int> items;
                // 遍历当前层的全部元素
                for (int i = 0; i < n; ++i)
                {
                    TreeNode* curr = q.front();
                    items.push_back(curr->val);
                    q.pop();
                    if (curr->left != nullptr)
                    {
                        q.push(curr->left);
                    }
                    if (curr->right != nullptr)
                    {
                        q.push(curr->right);
                    }
                }
                res.emplace_back(items);
            }
        }

        return res;
    }
};
