# include <iostream>
# include <algorithm>
# include <vector>
# include <priority_queue>
using namespace std;
class Solution {
public:
    int maximumScore(int a, int b, int c) {
        priority_queue<int> q;
        q.push(a), q.push(b), q.push(c);
        int res = 0;
        while (q.size() > 1) {
            int x = q.top(); q.pop();
            int y = q.top(); q.pop();
            res ++ ;
            if (-- x) q.push(x);
            if (-- y) q.push(y);
        }
        return res;
    }
};