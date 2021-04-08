#include<iostream>
#include<string>
#include<vector>
#include<algorithm

using namespace std;

# include<algorithm>
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> maps;
        vector<int> tag;
        for(int i = 0;i<nums.size();i++){
            if(maps.find(nums[i])==maps.end()){
                maps.insert(pair<int,int>(target-nums[i],i));
            }
            else{
                tag.push_back(maps[nums[i]]);
                tag.push_back(i);
                return tag;
            }
        }
        return tag;
    }
};