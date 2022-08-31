// 给定 pushed 和 popped 两个序列，每个序列中的 值都不重复，只有当它们可能是在最初空栈上进行的推入 push 和弹出 pop 操作序列的结果时，返回 true；否则，返回 false 。

//  

// 来源：力扣（LeetCode）
// 链接：https://leetcode.cn/problems/validate-stack-sequences
// 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
// 示例 1：

// 输入：pushed = [1,2,3,4,5], popped = [4,5,3,2,1]
// 输出：true
// 解释：我们可以按以下顺序执行：
// push(1), push(2), push(3), push(4), pop() -> 4,
// push(5), pop() -> 5, pop() -> 3, pop() -> 2, pop() -> 1

// 来源：力扣（LeetCode）
// 链接：https://leetcode.cn/problems/validate-stack-sequences
// 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
# include <iostream>
# include <vector>
# include <queue>

using namespace std;
class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        vector<int> q;
        for (int i = 0; i < pushed.size(); i++) {
            q.push_back(pushed[i]);
            while(q.back() == popped.front()) {
                q.pop_back();
                popped.erase(popped.begin());
                if (popped.empty()) return true;
                if(q.empty()) break;
            }
        }
        return false;
    }
};

int main() {
    Solution s;
    vector<int> pushed = {1,0};
    vector<int> popped = {1,0};
    cout << s.validateStackSequences(pushed, popped) << endl;
    return 0;
}