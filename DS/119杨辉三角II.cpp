#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        if (rowIndex == 0)
            return {1};
        vector<vector<int>> trangle ;
        vector<int> tan{1};
        trangle.push_back(tan);
        for(auto i  = 1;i <= rowIndex;i++){
            vector<int> tan;
            for(auto j = 0;j <= i;j++){
                if(j == 0 || j == i)
                    tan.push_back(1);
                else{

                    int s = trangle[i-1][j-1] + trangle[i-1][j];
                    tan.push_back(s);
                }
            }
            trangle.push_back(tan);
        }
        return trangle[rowIndex];
    }
};
int main(){
    Solution sulotion;
    int m;
    cin >> m;
    cout << m << endl;
    vector<int> k;
    for(int i = 0;i <= m;i++){
        k = sulotion.getRow(i);
        for(auto num : k)
            cout << num;
        cout << endl;
    }
    return 0;
}