class Solution {
private:
    int idx = 0;
    vector<int> e, ne, h; 
    vector<bool> st;
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) 
    {
        if (edges.size() == 0) return {0};

        vector<int> d(n, 0);
        e = vector<int>(n * 2);
        ne = vector<int>(n * 2);
        st = vector<bool>(n, false);
        h = vector<int>(n, -1);
        for (int i = 0; i < n - 1; i ++ )
        {
            int a = edges[i][0], b = edges[i][1];
            add(a, b), add(b, a);
            d[a] ++ , d[b] ++ ;
        }

        queue<int> q;
        vector<int> res;
        for (int i = 0; i < n; i ++ )
            if (d[i] == 1)
                q.push(i);
        int cnt = 0;
        while (cnt < n - 2)
        {
            int m = q.size();
            cnt += m;
            for (int i = 0; i < m; i ++ )
            {
                auto t = q.front();
                q.pop();
                st[t] = true;
                
                for (int i = h[t]; ~i; i = ne[i])
                {
                    int j = e[i];
                    if (st[j]) continue;
                    if (-- d[j] == 1) q.push(j);
                }
            }
        }

        while(q.size())
        {
            res.push_back(q.front());
            q.pop();
        }
        
        return res;
    }

    void add(int a, int b)
    {
        e[idx] = b, ne[idx] = h[a], h[a] = idx ++ ;
    }
};
