class Solution {
public:
    int reinitializePermutation(int n) {
        int cnt=0,ans=1;

        //置换环
        vector<bool> vis(n,false);
        for(int i=1;i<n-1;i++){
            int j=i;
            while(!vis[j]){
                vis[j]=true;
                cnt++;
                j=j%2==0?(j/2):(n/2+(j-1)/2);
            }
            ans=max(ans,cnt);
            cnt=0;
        }
        return ans;
    }
};