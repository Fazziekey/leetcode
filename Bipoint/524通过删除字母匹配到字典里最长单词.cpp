class Solution {
public:
    string findLongestWord(string s, vector<string>& dictionary) {
        int len = 0;
        string longset;
        for(auto d : dictionary){
            if(match(s,d)){
                if(len < d.size()){
                    len = d.size();
                    longset = d;
                }else if(len == d.size() && longset > d){
                    longset = d;
                }
                    
            }
            
        }
        return longset;
    };

    bool match(string s, string d){
        if(d.size() > s.size())
            return false;
        int i = 0;
        int j = 0;
        while(j < d.size() && i < s.size()){
            if(s[i] != d[j]){
                i++;
            }else{
                i++;
                j++;
            }
        }
        if(j != d.size())
            return false;
        return true;

    };
};