// 给你一个数组 nums ，数组中有 2n 个元素，按 [x1,x2,...,xn,y1,y2,...,yn] 的格式排列。

// 请你将数组按 [x1,y1,x2,y2,...,xn,yn] 格式重新排列，返回重排后的数组。

// 来源：力扣（LeetCode）
// 链接：https://leetcode.cn/problems/shuffle-the-array
// 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> ans(2n);
        for(int i = 0; i < n; i++) {
            ans[2i] = nums[i];
            ans[2i+1] = nums[i + n];
        }
        return ans;
    }
};
