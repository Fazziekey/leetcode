class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        if(nums.size() == 0)
            return 0;
        if(nums.size() == 1)
            return nums[0];
        int low = 0;
        int hight = nums.size() - 1;
        while(low < hight){
            int mid = low + (hight - low) / 2;
            if(nums[mid] != nums[mid - 1] && nums[mid] != nums[mid + 1]){
                return nums[mid];
            }   
            else if(nums[mid] == nums[mid - 1]){
                if((hight - mid)%2){
                    low = mid +1;
                } else {
                    hight = mid;
                }

            }
            else if(nums[mid] == nums[mid + 1]){
                if((mid - low)%2){
                    hight = mid - 1;
                } else{
                    low = mid;
                }
            }
        }
        return nums[low];
    }
};