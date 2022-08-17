// 给你一棵二叉树的根节点 root ，请你返回 层数最深的叶子节点的和 。

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
    int deepestLeavesSum(TreeNode* root) {
        if(root == nullptr) return 0;
        int sum = 0;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            sum = 0;
            int size = q.size();
            for(int i = 0;i < size;i++){
                TreeNode* node = q.front();
                q.pop();
                if(node->left == nullptr && node->right == nullptr){
                    sum += node->val;
                }
                if(node->left != nullptr){
                    q.push(node->left);
                }
                if(node->right != nullptr){
                    q.push(node->right);
                }
            }
        }
        return sum;
    }
};