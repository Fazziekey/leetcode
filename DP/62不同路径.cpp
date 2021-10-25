class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> k (m,vector(n,1));
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                k[i][j]=k[i-1][j]+k[i][j-1];
            }
        }
        return k[m-1][n-1];
    }
};