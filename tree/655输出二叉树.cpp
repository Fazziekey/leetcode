// 给你一棵二叉树的根节点 root ，请你构造一个下标从 0 开始、大小为 m x n 的字符串矩阵 res ，用以表示树的 格式化布局 。构造此格式化布局矩阵需要遵循以下规则：

// 树的 高度 为 height ，矩阵的行数 m 应该等于 height + 1 。
// 矩阵的列数 n 应该等于 2height+1 - 1 。
// 根节点 需要放置在 顶行 的 正中间 ，对应位置为 res[0][(n-1)/2] 。
// 对于放置在矩阵中的每个节点，设对应位置为 res[r][c] ，将其左子节点放置在 res[r+1][c-2height-r-1] ，右子节点放置在 res[r+1][c+2height-r-1] 。
// 继续这一过程，直到树中的所有节点都妥善放置。
// 任意空单元格都应该包含空字符串 "" 。
// 返回构造得到的矩阵 res 。

//  

// 来源：力扣（LeetCode）
// 链接：https://leetcode.cn/problems/print-binary-tree
// 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
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
    vector<vector<string>> printTree(TreeNode* root) {
        int m = getHeight(root);
        int n = pow(2,m) - 1;
        vector<vector<string>> res(m, vector<string>(n, ""));
        res[0][(n-1)/2] = to_string(root->val);
        queue<pair<TreeNode*,pair<int,int>>> q;
        q.push({root,{0,(n-1)/2}});
        while (q.empty() == false) 
        {
            int size = q.size();
            for(int i = 0;i < size;i++){
                auto p = q.front();
                q.pop();
                int r = p.second.first;
                int c = p.second.second;
                if(p.first->left != nullptr){
                    q.push({p.first->left,{r+1,c-pow(2,(m-r-2))}});
                    res[r+1][c-pow(2,(m-r-2))] = to_string(p.first->left->val);
                }
                if(p.first->right != nullptr){
                    q.push({p.first->right,{r+1,c+pow(2,(m-r-2))}});
                    res[r+1][c+pow(2,(m-r-2))] = to_string(p.first->right->val);
                }
            }
        }
        return res;
        
    }
    int getHeight(TreeNode* root){
        if(root == nullptr)
            return 0;
        return max(getHeight(root->left),getHeight(root->right)) + 1;
    }
};