class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = nums[0];
        if (nums.size() > 1) {
        for (int i = 1; i < nums.size(); i++) {
            ans = ans ^ nums[i];
        }
        }
        return ans;
    }
};