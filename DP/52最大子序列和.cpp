class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        vector<int> k(nums.size(),0);
        int Max;
        Max = k[0] = nums[0];
        int i = 1;
        for(int i = 1;i<nums.size();i++){
            k[i] = max(nums[i],k[i-1]+nums[i]);
            Max = max(k[i],Max);
        }
        return Max;
    }
};