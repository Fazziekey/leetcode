class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char,int> hashmap;
        int maxlen = 0;
        int left=0,right=0;
        while(right<s.size()){
            while(hashmap.find(s[right]) == hashmap.end()){
                hashmap.insert(pair<char,int>(s[right],right));
                maxlen = max(maxlen,right-left+1);
                right ++ ;
                if(right == s.size())
                    break;
            }
            if(right == s.size())
                    break;
            left = max(left,hashmap[s[right]]+1);
            maxlen = max(maxlen,right-left+1);
            hashmap[s[right]] = right;
            right++;
        }
        return maxlen;
    }
};