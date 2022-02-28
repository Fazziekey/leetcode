class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        if(pairs.size() == 1)
            return 1;

        sort(pairs.begin(), pairs.end(), [](vector<int> &a, vector<int>b) {
            if (a[0] == b[0]) return a[1] < b[1];
            return a[0] < b[0];
        });
        int end = pairs[0][1];
        vector<int> dp(pairs.size(),0);
        dp[0] = 1;
        for(int i = 1;i < pairs.size();i++){
            if(end < pairs[i][0]){
                dp[i] = dp[i - 1] + 1;
                end = pairs[i][1];
            }else if(end >= pairs[i][0]){
                dp[i] = dp[i -  1];
                end =  min(end,pairs[i][1]);
            }
        }

        return dp[pairs.size() - 1];
    }
};