
class Solution {
public:
    int rob(vector<int>& nums) {
        int max_value;
        int size = nums.size() - 1;
        if(size == 0)
            return nums[0];
        if(size == 1)
            return max(nums[0], nums[1]);
        vector<int> dp1(size, 0);
        vector<int> dp2(size, 0);
        dp1[0] = nums[0];
        dp1[1] = max(nums[0], nums[1]);
        for(int i = 2;i < size;i++){
            dp1[i] = max(dp1[i - 1], dp1[i - 2] + nums[i]); 
        }
        dp2[0] = nums[1];
        dp2[1] = max(nums[1], nums[2]);
        for(int i = 2;i < size;i++){
            dp2[i] = max(dp2[i - 1], dp2[i -2] + nums[i + 1]); 
        }
        return max(dp1[size - 1], dp2[size - 1]);
    }
};