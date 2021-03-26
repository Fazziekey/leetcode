class Solution {
public:
    int cuttingRope(int n) {
        int max = 0,multi = 1;
        int m = 2;
        for(m = 2;m <= n;m++){
            vector<int> k(m,1);
            for(int i=0;i< n % m;i++){
                k[i] = (n + (m - n % m))/m;
                multi = multi * k[i];
            }
            for(int i = n % m;i < m;i++){
                k[i] = n / m;
                multi = multi * k[i];
            }
            if(multi >= max)
                max = multi;
                multi = 1;
        }
        return max;
    }
};