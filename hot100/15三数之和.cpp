class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> k;
        if(nums.size()<3||nums.size()==0)
            return k;
        sort(nums.begin(),nums.end());
        int l =  0,r = nums.size()-1;
        int  i =0;
        while(i<nums.size()-2){
            if(nums[i]>0)
                return k;
            l = i+1;
            r = nums.size()-1;
            while(l<r){
                if(nums[i]+nums[r]+nums[l]==0){
                    k.push_back({nums[i],nums[l],nums[r]});
                    while(nums[l]==nums[l+1]&&l<r)
                        l++;
                    while(nums[r]==nums[r-1]&&l<r)
                        r--;
                    l++;
                    r--;
                }
                else if(nums[i]+nums[r]+nums[l]>0){
                    r--;
                }
                else{
                    l++;
                }
            }
            while(i+1<nums.size()&&nums[i] == nums[i+1])
                i++;
            i++;
        }
        return k;
    }
};