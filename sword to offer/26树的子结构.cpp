class Solution {
public:
    bool check(TreeNode* A, TreeNode* B) {
        if(A == nullptr && B == nullptr)
            return true;
        else if(A == nullptr && B != nullptr)
            return false;
        else if(A != nullptr && B == nullptr)
            return true;
        else if(A->val != B->val)
            return false;
        else
            return check(A->left, B->left) && check(A->right, B->right);
    }
    bool isSubStructure(TreeNode* A, TreeNode* B) {
        if(B == nullptr)
            return false;
        if(check(A,B))
            return true;
        bool l = false, r = false;
        if(A->left)
            l = isSubStructure(A->left, B);
        if(A->right)
            r = isSubStructure(A->right, B);
        return l || r;
    }
};

