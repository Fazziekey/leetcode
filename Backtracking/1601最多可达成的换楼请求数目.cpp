class Solution {
private:
    vector<int> delta;
    int ans = 0, cnt = 0, zero, n;

public:
    void dfs(vector<vector<int>> &requests, int pos) {
        if (pos == requests.size()) {
            if (zero == n) {
                ans = max(ans, cnt);
            }
            return;
        }

        // 不选 requests[pos]
        dfs(requests, pos + 1);

        // 选 requests[pos]
        int z = zero;
        ++cnt;
        auto &r = requests[pos];
        int x = r[0], y = r[1];
        zero -= delta[x] == 0;
        --delta[x];
        zero += delta[x] == 0;
        zero -= delta[y] == 0;
        ++delta[y];
        zero += delta[y] == 0;
        dfs(requests, pos + 1);
        --delta[y];
        ++delta[x];
        --cnt;
        zero = z;
    }

    int maximumRequests(int n, vector<vector<int>> &requests) {
        delta.resize(n);
        zero = n;
        this->n = n;
        dfs(requests, 0);
        return ans;
    }
};

