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
    ListNode* reverseList(ListNode* head) {
        if(head == NULL)
            return NULL;
        if(head -> next == NULL)
            return head;
        struct ListNode *newhead ,*p = head,*q;
        newhead = new ListNode;
        newhead->val = p->val;
        for(p = head->next;p!=NULL;p=p->next){
            q = new ListNode;
            q->val = p->val;
            q->next = newhead;
            newhead = q;
        }
        return newhead;
    }
};