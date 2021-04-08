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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *p = l1,*q = l2;
        int flag = 0;
        while(1){
            if(flag == 1)
                p->val = p->val+q->val + 1;
            else
               p->val = p->val+q->val; 
            if(p->val >9){
                flag = 1;
                p->val = p->val %10;
            }
            else
                flag = 0;
            if(p->next==nullptr||q->next==nullptr)
                break;
            p = p->next;
            q = q->next;
        }
        if(p->next==nullptr&&q->next==nullptr){
            if(flag==1)
            p->next =new ListNode(1);
            return l1;
        }
        if(p->next==nullptr){
            p->next = q->next;
            q = q->next;
            while(flag==1){
                q->val++;
                if(q->val>9){
                    flag=1;
                    q->val=q->val%10;
                }

                else
                    flag=0;
                if(q->next==nullptr&&flag==1){
                    q->next= new ListNode(1);
                    break;
                }
                q=q->next;
            }
        }
        else if(q->next==nullptr){
            p= p->next;
            while(flag==1){
                p->val++;
                if(p->val>9){
                    flag= 1;
                    p->val=p->val%10;
                }
                else    
                    flag = 0;
                if(p->next==nullptr&&flag==1){
                    p->next= new ListNode(1);
                    break;
                }
                p = p->next;
            }
        }
    return l1;
    }
};