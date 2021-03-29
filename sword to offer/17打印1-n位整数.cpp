class Solution {
public:
    vector<int> printNumbers(int n) {
        int max;
        max = pow(10,n)-1;
        vector<int> k;
        for(int i = 1;i <= max;i++){
            k.push_back(i);
        }
        return k;
    }
};