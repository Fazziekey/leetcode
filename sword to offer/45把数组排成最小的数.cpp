class Solution {
public:
    string minNumber(vector<int>& nums) {
        vector<string> strs;
        string res;
        for(auto num:nums)
            strs.push_back(to_string(num));
        sort(strs.begin(),strs.end(),compare);
        for(auto str:strs)
            res+=str;
        return res;
    }
private:
    static bool compare(const string &a,const string &b)
    {
        return a+b<b+a;
    }
};