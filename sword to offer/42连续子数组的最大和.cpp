class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int mx = INT_MIN, cur = 0;
        for(int& n : nums){
            cur = (n > cur + n) ? n : cur + n;
            mx = max(mx, cur);
        }
        return mx;
    }
};

