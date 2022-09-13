// 给定一个非负整数，你至多可以交换一次数字中的任意两位。返回你能得到的最大值。

// 示例 1 :

// 输入: 2736
// 输出: 7236
// 解释: 交换数字2和数字7。
// 示例 2 :

// 输入: 9973
// 输出: 9973
// 解释: 不需要交换。
// 注意:

// 给定数字的范围是 [0, 108]

// 来源：力扣（LeetCode）
// 链接：https://leetcode.cn/problems/maximum-swap
// 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
class Solution {
public:
    int maximumSwap(int num) {
        vector<int> arr;
        for(; num; num /= 10) arr.emplace_back(num % 10);
        reverse(arr.begin(), arr.end());
        int n = arr.size();
        vector<int> max(n);
        max[n - 1] = n - 1;
        for(int i = n - 2; i >= 0; --i) {
            if(arr[i] > arr[max[i + 1]]) max[i] = i;
            else max[i] = max[i + 1];
        }
        for(int i = 0; i < n; ++i) {
            if(arr[i] < arr[max[i]]) {
                swap(arr[i], arr[max[i]]);
                break;
            }
        }
        int res = 0;
        for(int i = 0; i < n; ++i) {
            res = res * 10 + arr[i];
        }
        return res;
    }
};