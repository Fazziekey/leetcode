/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        TreeNode *q = root;
        queue<TreeNode*> m;
        vector<int> k;
        string str;
        if(root == NULL)
            return  NULL;
        while(!m.empty()){
            q = m.front();
            m.pop();
            k.push_back(q->val);
            if(q->left != NULL){
                m.push(q->left);
            } 
            else{
                k.push_back(-1);
            }
            if(q->right != NULL){
                m.push(q->right);
            } 
            else{
                k.push_back(-1);
            }
        }
        str.push_back('[');
        for(int i = 0;i<k.size();i++){
            if(k[i]==-1){
                str.push_back('null');
                str.push_back(',');
            }
            else{
                str.push_back(k[i]);
                str.push_back(',');
            }
        }
        str.push_back(']');
        return str;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        return NULL;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));