//两层循环,双指针
#include <vector>
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        if(nums.size() < 4)
            return {};
        vector<vector<int>> vecs;
        sort(nums.begin(),nums.end());
        if(nums.front() > 0 && nums.front() > target)
            return {};
        for(auto i = 0;i < nums.size() - 3;i++){
            if(i > 0 && nums[i] == nums[i - 1] && i < nums.size())
                continue;
            for(auto j = i + 1;j < nums.size() - 2;j++){
                if(j > i + 1 && nums[j] == nums[j - 1] && j < nums.size() - 2)
                    continue;
                auto start = j + 1;
                auto end = nums.size() - 1;
                while(start < end){
                    if(nums[i] + nums[j] == target - nums[start] - nums[end]){
                        vector<int> vec{nums[i],nums[j],nums[start],nums[end]};
                        vecs.push_back(vec);
                        start++;
                        while(nums[start] == nums[start - 1] && start < end)
                            start++;
                        end--;
                        while(nums[end] == nums[end + 1] && start < end)
                            end--;
                    } else if(nums[i] + nums[j] < target - nums[start] - nums[end]){
                        start++;
                        while(nums[start] == nums[start - 1] && start < end)
                            start++;
                    }
                    else{
                        end--;
                        while(nums[end] == nums[end + 1] && start < end)
                            end--;
                    }
                }


            }
        }

        return vecs;
    }
};