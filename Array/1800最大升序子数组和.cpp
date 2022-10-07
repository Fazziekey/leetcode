class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int sum = 0,result = 0;
        int size = nums.size();
        int end = 0;
        while(end < size){
            while(end < size - 1&& nums[end] < nums[end+1]){
                sum += nums[end];
                end++;
            }
            sum += nums[end];
            result = max(result,sum);
            end++;
            sum = 0;
        }
        return result;
    }
};