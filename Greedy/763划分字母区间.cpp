class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> sp;
        auto start = 0;
        auto end = s.size();
        auto p = 0;
        auto q = s.size();

        while(p < s.size()){
            set<int> sets;
            start = p;
            end = s.find_last_of(s[p]);
            while(p < end){
                if(sets.count(p) == 0){
                    sets.insert(p);
                    q = s.find_last_of(s[p]);
                    end = max(q,end);
                }
                p++;
            }
            int len = end - start + 1;
            sp.push_back(len);
            p = end + 1;
        }

        return sp;
    }
};