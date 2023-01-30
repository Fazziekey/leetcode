/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* node_a = list1;
        ListNode* node_b = list1;
        ListNode* node_c = list2;
        for(int i = 0; i < a-1; i++){
            node_a = node_a->next;
        }
        for(int i = 0; i < b+1; i++){
            node_b = node_b->next;
        }
        node_a->next = list2;
        while(node_c->next != nullptr){
            node_c = node_c->next;
        }
        node_c->next = node_b;
        return list1;
    }
};