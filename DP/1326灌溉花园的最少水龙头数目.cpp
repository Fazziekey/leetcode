class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        vector<vector<int>> interval;
        for(int i = 0;i <= n;i++){
            int start = max(0, i - ranges[i]);
            int end = min(i + ranges[i], n);
            interval.push_back({start, end});
        }
        sort(interval.begin(), interval.end(), [](vector<int> a, vector<int> b){
            return a[0] < b[0];
        });
        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;
        for (auto inter : interval) {
            if (dp[inter[0]] == INT_MAX) {
                return -1;
            }
            for (int j = inter[0]; j <= inter[1]; j++) {
                dp[j] = min(dp[j], dp[inter[0]] + 1);
            }
        }
        return dp[n];
    }
};