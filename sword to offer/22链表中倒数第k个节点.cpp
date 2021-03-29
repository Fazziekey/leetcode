/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* getKthFromEnd(ListNode* head, int k) {
        struct ListNode * m =head;
        int count = 0;
        while(m!=NULL){
            m = m->next;
            count ++;
        }
        m =head;
        for(int i = 0;i<count-k;i++){
            m=m->next;
        }
        return m;
    }
};