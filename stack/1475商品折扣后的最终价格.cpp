// 给你一个数组 prices ，其中 prices[i] 是商店里第 i 件商品的价格。

// 商店里正在进行促销活动，如果你要买第 i 件商品，那么你可以得到与 prices[j] 相等的折扣，其中 j 是满足 j > i 且 prices[j] <= prices[i] 的 最小下标 ，如果没有满足条件的 j ，你将没有任何折扣。

// 请你返回一个数组，数组中第 i 个元素是折扣后你购买商品 i 最终需要支付的价格。

// 来源：力扣（LeetCode）
// 链接：https://leetcode.cn/problems/final-prices-with-a-special-discount-in-a-shop
// 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

# include <iostream>
# include <vector>
using namespace std;
class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        int size = prices.size();
        vector<int> ans(size);
        for(int i = 0; i < size; i++) {
            ans[i] = prices[i];
            for(int j = i + 1; j < size; j++) {
                if(prices[j] <= prices[i]) {
                    ans[i] = min(ans[i],(prices[i] - prices[j]));
                }
            }
        }
        return ans;
    }
};

int main(){
    Solution s;
    vector<int> prices = {8,4,6,2,3};
    vector<int> ans = s.finalPrices(prices);
    for(int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}