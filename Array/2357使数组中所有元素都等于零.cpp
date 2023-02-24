class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int tmp  = 0;
        int count = 0;
        for(int i = 0; i < nums.size();i++){
            if(nums[i] != 0){
                if (nums[i] > tmp){
                    tmp = nums[i];
                    count++;
                }
            }
        }
        return count;
    }
};