class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.size()==0)
            return {-1,-1};
        int i =0,j=nums.size()-1;
        while(nums[i]!=target&&i<nums.size())
            i++;
        if(i==nums.size())
            return {-1,-1};
        else
            while(nums[j]!=target&&j>0)
                j--;
        return {i,j};
    }
};