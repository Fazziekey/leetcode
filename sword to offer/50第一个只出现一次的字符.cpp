class Solution {
public:
    char firstUniqChar(string s) {
        map<char,int> hash;
        for(int i = 0;i<s.size();i++){
            if(hash.find(s[i]) == hash.end())
                hash.insert(pair<char,int>(s[i],i));
            else
                hash[s[i]] = -1;
        }
        for(int i = 0;i<s.size();i++)
            if(hash[s[i]]!=-1)
                return s[i];
        return ' ';
    }
};