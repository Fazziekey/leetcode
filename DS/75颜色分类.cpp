class Solution {
public:
    void sortColors(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        cout << '[';
        for(auto i = 0;i < nums.size()-1;i++){
                cout << nums[i] << ',';
        }
        cout << nums[nums.size()-1] << ']';
    }
};