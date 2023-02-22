class Solution {
public:
    int stoneGameII(vector<int>& piles) {
        int n = (int)piles.size();

        int presum[n + 1];
        presum[0] = 0;
        for (int i = 0; i < n; i ++){
            presum[i + 1] = presum[i] + piles[i];
        }

        int dp[n][n + 1];
        memset(dp, 0, sizeof(dp));
        for (int i = n - 1; i > -1; i --){
            for (int m = 1; m < n + 1; m ++){
                if (i + 2 * m >= n){
                    dp[i][m] = (presum[n] - presum[i]);
                }else{
                    for (int x = 1; x < 2 * m + 1; x ++){
                        dp[i][m] = max(dp[i][m], (presum[n]-presum[i]) - dp[i+x][max(m, x)]);
                    }
                }
            }
        }

        int res = dp[0][1];
        return res;
    }
};

