/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<int> tree;
    vector<int> preorder(Node* root) {
        if(root == nullptr)
            return tree;
        pre_order(root);
        return tree;
    }

    void pre_order(Node* root){
        tree.push_back(root->val);
        if(root->children.empty())
            return;

        for(auto child : root->children){
            pre_order(child);  
        }

        return;
    }

};



