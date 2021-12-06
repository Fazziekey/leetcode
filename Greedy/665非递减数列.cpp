#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int count = 0;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] < nums[i - 1]) {
                if (i == 1 || nums[i] >= nums[i - 2]) {
                    nums[i - 1] = nums[i];
                } else {
                    nums[i] = nums[i - 1];
                }
                count ++;
            }
        }
        return count <= 1;
    }
};


int main(){
    Solution s;
    vector<int> k{4,2,3};
    cout << s.checkPossibility(k) << endl;

}
