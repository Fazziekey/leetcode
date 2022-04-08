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
    vector<vector<int>> levelOrder(Node* root) {
        queue<Node *> q;
        Node* cur_node;
        vector<vector<int>> list;
        if(!root)
            return list;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            vector<int> tmp;
            while(size--){
                cur_node = q.front();
                q.pop();
                tmp.push_back(cur_node->val);
                for(auto child : cur_node->children){
                    q.push(child);
                }
            }
            list.push_back(tmp);
        }
        return list;
    }
};