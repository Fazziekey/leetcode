class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if(n == 0)
            return 1;
        if(n == 1)
            return 10;
        vector<int> dp(n + 1, 0);
        dp[0] = 1;
        for(int i = 1;i <= n;i++){
            dp[i] = dp[i-1] * (11 - i);
            for(int j = 0;j< i - 1;j++){
                dp[i] = dp[i] + dp[j];
            }
        }
        return dp[n];
    }
};