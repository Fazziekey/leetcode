class Solution {
public:
    int getLucky(string s, int k) {
        int ans = 0;
        string num;
        for (int i = 0; i < s.size(); i++) {
            num = num + to_string(s[i] - 'a' + 1);
        }
        for (int i = 0; i < k; i++) {
            ans = 0;
            for (int j = 0; j < num.size(); j++) {
                ans += num[j] - '0';
            }
            num = to_string(ans);
        }
        return ans;
    }
};