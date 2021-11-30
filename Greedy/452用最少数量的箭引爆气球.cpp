class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        if(points.size() == 1)
            return 1;
        auto cmp = [](const vector<int>& lhs, const vector<int>& rhs) {
            return lhs[1] < rhs[1];
        };
        sort(points.begin(), points.end(), cmp);
        int pos = points[0][1];
        int ans = 1;
        for (const vector<int>& balloon: points) {
            if (balloon[0] > pos) {
                pos = balloon[1];
                ++ans;
            }
        }
        return ans;
    }
};