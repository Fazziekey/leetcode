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
    ListNode* deleteNode(ListNode* head, int val) {
        struct ListNode *p,*q;
        for(p = head;p!=NULL;p = p->next){
            if(p->val == val){
                if(p == head){
                    head = p->next;
                    //delete p; 
                }
                else{
                    q ->next = p->next;
                    //delete p;        
                }
                break;
            }
            q = p;
        }
        return head;
    }
};