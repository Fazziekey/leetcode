class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int m =nums.size()-1;
        for(int i = 0;i<nums.size();i++){
            if(nums[i]==val){
                int tmp = nums[i];
                nums[i] = nums[m];
                nums[m] = tmp;
                nums.pop_back();
                m--;
                i--;
            }
        }
        return m+1;
    }
};