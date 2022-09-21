// 对于某些非负整数 k ，如果交换 s1 中两个字母的位置恰好 k 次，能够使结果字符串等于 s2 ，则认为字符串 s1 和 s2 的 相似度为 k 。

// 给你两个字母异位词 s1 和 s2 ，返回 s1 和 s2 的相似度 k 的最小值。

//  

// 示例 1：

// 输入：s1 = "ab", s2 = "ba"
// 输出：1
// 示例 2：

// 输入：s1 = "abc", s2 = "bca"
// 输出：2
//  

// 提示：

// 1 <= s1.length <= 20
// s2.length == s1.length
// s1 和 s2  只包含集合 {'a', 'b', 'c', 'd', 'e', 'f'} 中的小写字母
// s2 是 s1 的一个字母异位词
// 通过次数7,937提交次数19,271

// 来源：力扣（LeetCode）
// 链接：https://leetcode.cn/problems/k-similar-strings
// 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
class Solution {
    int res = INT_MAX;
public:
    void dfs(string &s1, string &s2, int cur, int n, int ans){
        if(cur == n){
            res = min(res, ans);
            return;
        }
        if(ans >= res){
            return;
        }
        if(s1[cur] != s2[cur]){
            for(int i = cur + 1; i < n; ++i){
                if(s1[i] != s2[i] && s2[i] == s1[cur]){
                    swap(s2[i], s2[cur]);
                    dfs(s1, s2, cur+1, n, ans + 1);
                    swap(s2[i], s2[cur]);
                }
            }
        }else{
            dfs(s1, s2, cur+1, n, ans);
        }
    }

    int kSimilarity(string s1, string s2) {
        dfs(s1, s2, 0, s1.size(), 0);
        return res;
    }
};