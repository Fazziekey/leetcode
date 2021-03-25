class Solution {
public:
    vector<int> reversePrint(ListNode* head) {
        vector <int> vec;
        for(auto p = head;p!=NULL;p=p->next){
            vec.insert(vec.begin(),p->val);
        }
            return vec;
    }

};