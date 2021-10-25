#include <map>
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        int size = nums.size();
        if(size < 2)
            return false;
        map<int,int> maps;
        maps[nums[0]] = 1; 
        for(int i = 1; i < size; i++){
            if(maps.find(nums[i]) != maps.end())
                return true;
            else
                maps.insert(pair<int, int>(nums[i], 1));
        }

        return false;
    }
};