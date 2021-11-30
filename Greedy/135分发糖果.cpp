#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int candy(vector<int>& ratings) {
        int size = ratings.size();
        if(size == 1)
            return 1;
        vector<int> candy(size,1);
        for(auto i = 0;i < size - 1;i++){
            if(ratings[i] < ratings[i+1]){
                candy[i+1] = candy[i] + 1;
            }
        }
        for(auto i = size - 1;i > 0;i--){
            if(ratings[i] < ratings[i-1]){
                candy[i-1] = max(candy[i] + 1,candy[i - 1]);
            }
        }
        int sum = 0;
        for(auto num : candy){
            sum+=num;
            cout << num << endl;
        }
        return sum;
    }
};

int main(){
    Solution s;
    vector<int> k{1,3,4,5,2};
    cout << s.candy(k) << endl;

}