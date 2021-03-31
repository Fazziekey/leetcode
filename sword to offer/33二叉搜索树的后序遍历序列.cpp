class Solution {
private:
    bool dfs(vector<int>& postorder, int start, int end)
    {
        // 单个结点，必然是二叉树
        if (start >= end)
        {
            return true;
        }
        // 找左子树的结束位置
        int p = start;
        int rootVal = postorder[end];
        while (postorder[p] < rootVal)
        {
            ++p;
        }
        // 设置左子树结束位置
        int leftEnd = p - 1;

        // 找右子树的结束位置
        while (postorder[p] > rootVal)
        {
            ++p;
        }

        // 右子树结束位置应该正好在end这里
        return p == end && dfs(postorder, start, leftEnd) && dfs(postorder, leftEnd+1, end-1);
    }

public:
    bool verifyPostorder(vector<int>& postorder) {
        return dfs(postorder, 0, postorder.size()-1);
    }
};

