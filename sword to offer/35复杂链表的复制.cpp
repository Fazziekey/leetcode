/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == nullptr)
        {
            return head;
        }
        Node* root= new Node(head->val);

        queue<Node*> q;
        // 从原来的结点到拷贝的结点的映射
        unordered_map<Node*, Node*> visited;
        visited[head] = root;

        // 插入原有的根节点
        q.push(head);
        while (!q.empty())
        {
            Node* curr = q.front();
            // cout << curr->val << endl;
            // 下一个节点不为空，且不再visted里，则创建一次
            if (curr->next && visited.find(curr->next) == visited.end())
            {
                visited[curr->next] = new Node(curr->next->val);
                q.push(curr->next);
            }
            // 随机节点不为空，且不再visted里，则创建一次
            if (curr->random && visited.find(curr->random) == visited.end())
            {
                visited[curr->random] = new Node(curr->random->val);
                q.push(curr->random);
            }
            visited[curr]->next = visited[curr->next];
            visited[curr]->random = visited[curr->random];
            q.pop();
        }

        return root;
    }
};
