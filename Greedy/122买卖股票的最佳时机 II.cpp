class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int sum = 0;
        int start = 0;
        int end = 0;
        while(end < prices.size()){
            if(end == prices.size() - 1){
                sum = sum + prices[end] - prices[start];
                end++;
            }
            else if(prices[end+1] > prices[end]){
                end++;
            }
            else{
                sum = sum + prices[end] - prices[start];
                end++;
                start = end;
            }

        }
        return sum;
    }
};