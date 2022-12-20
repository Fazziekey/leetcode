class Solution {
public:
    int minElements(vector<int>& nums, int limit, int goal) {
        long long sum = 0;
        for (auto num : nums) sum += num;
        long long diff = abs(goal - sum);
        return (diff + limit - 1) / limit;
    }
};