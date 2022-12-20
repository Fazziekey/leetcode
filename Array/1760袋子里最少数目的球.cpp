#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    int minimumSize(vector<int>& nums, int maxOperations) {
        int l = 1, r = *max_element(nums.begin(), nums.end());
        while (l < r) {
            int mid = l + r >> 1;
            int cnt = 0;
            for (auto x : nums) {
                cnt += (x - 1) / mid;
            }
            if (cnt <= maxOperations) r = mid;
            else l = mid + 1;
        }
        return l;
      
    }
};