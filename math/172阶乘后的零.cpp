class Solution {
public:
    int trailingZeroes(int n) {
        if(n == 0)
            return 0;
        // long long sum = 1;
        // for(int i = 1;i<= n;i++){
        //     sum *= i;
        // }
        // cout << "sum" << sum << endl;
        return n/5 + n/25 + n/125 + n/625 + n/3125;
    }
};