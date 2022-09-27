// 给定两个字符串 s1 和 s2，请编写一个程序，确定其中一个字符串的字符重新排列后，能否变成另一个字符串。

// 示例 1：

// 输入: s1 = "abc", s2 = "bca"
// 输出: true 
// 示例 2：

// 输入: s1 = "abc", s2 = "bad"
// 输出: false
// 说明：

// 0 <= len(s1) <= 100
// 0 <= len(s2) <= 100
// 通过次数91,526提交次数141,710

// 来源：力扣（LeetCode）
// 链接：https://leetcode.cn/problems/check-permutation-lcci
// 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

class Solution {
public:
    bool CheckPermutation(string s1, string s2) {
        unordered_map<char,int> m1;
        for(auto c:s1){
            m1[c]++;
        }
        for(auto c:s2){
            m1[c]--;
        }
        for(auto p:m1){
            if(p.second!=0)return false;
        }
        return true;
    }
};