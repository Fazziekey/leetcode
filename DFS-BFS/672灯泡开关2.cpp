// 房间中有 n 只已经打开的灯泡，编号从 1 到 n 。墙上挂着 4 个开关 。

// 这 4 个开关各自都具有不同的功能，其中：

// 开关 1 ：反转当前所有灯的状态（即开变为关，关变为开）
// 开关 2 ：反转编号为偶数的灯的状态（即 2, 4, ...）
// 开关 3 ：反转编号为奇数的灯的状态（即 1, 3, ...）
// 开关 4 ：反转编号为 j = 3k + 1 的灯的状态，其中 k = 0, 1, 2, ...（即 1, 4, 7, 10, ...）
// 你必须 恰好 按压开关 presses 次。每次按压，你都需要从 4 个开关中选出一个来执行按压操作。

// 给你两个整数 n 和 presses ，执行完所有按压之后，返回 不同可能状态 的数量。

//  

// 示例 1：

// 输入：n = 1, presses = 1
// 输出：2
// 解释：状态可以是：
// - 按压开关 1 ，[关]
// - 按压开关 2 ，[开]
// 示例 2：

// 输入：n = 2, presses = 1
// 输出：3
// 解释：状态可以是：
// - 按压开关 1 ，[关, 关]
// - 按压开关 2 ，[开, 关]
// - 按压开关 3 ，[关, 开]
// 示例 3：

// 输入：n = 3, presses = 1
// 输出：4
// 解释：状态可以是：
// - 按压开关 1 ，[关, 关, 关]
// - 按压开关 2 ，[关, 开, 关]
// - 按压开关 3 ，[开, 关, 开]
// - 按压开关 4 ，[关, 开, 开]
//  

// 提示：

// 1 <= n <= 1000
// 0 <= presses <= 1000

// 来源：力扣（LeetCode）
// 链接：https://leetcode.cn/problems/bulb-switcher-ii
// 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    set<vector<int>> s;
    int flipLights(int n, int presses) {
        vector<int> v(n, 1);
        presses = min(presses, 4);
        dfs(v, presses);
        for(auto v: s) {
            for(auto i: v) {
                cout << i << " ";
            }
            cout << endl;
        }
        return s.size();
    }
    void change(vector<int>& v, int k) {
        if (k == 1) {
            for (int i = 0; i < v.size(); i++) {
                v[i] = !v[i];
            }
        } else if (k == 2) {
            for (int i = 0; i < v.size(); i++) {
                if (i % 2 == 0) {
                    v[i] = !v[i];
                }
            }
        } else if (k == 3) {
            for (int i = 0; i < v.size(); i++) {
                if (i % 2 == 1) {
                    v[i] = !v[i];
                }
            }
        } else if (k == 4) {
            for (int i = 0; i < v.size(); i++) {
                if (i % 3 == 0) {
                    v[i] = !v[i];
                }
            }
        }
        return;
    }
    void dfs(vector<int>& v, int presses) {
        if (presses == 0) {
            s.insert(v);
            return;
        }
        for (int i = 1; i <= 4; i++) {
            change(v, i);
            dfs(v, presses - 1);
            change(v, i);
        }
        return;
    }
};

int main(){
    int n, presses;
    cin >> n >> presses;
    Solution s;
    cout << s.flipLights(n, presses) << endl;
    return 0;
}