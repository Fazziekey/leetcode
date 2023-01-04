#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxValue(int n, int index, int maxSum) {
        vector<int> nums(n);
        int low = 0;
        int high = maxSum - 1;
        int mid = 0;
        int sum = 0;
        int tmp = 0;
        if (Sums(n, index, high) < maxSum) {
            return high;
        }
        while (low <= high) {
            mid = (low + high) / 2;
            sum = Sums(n, index, mid);
            if (sum > maxSum) {
                high = mid - 1;
            } else {
                low = mid + 1;
                tmp = mid;
            }
        }
        return mid;
    }

    int Sums(int n, int index, int num_index) {
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += (num_index > abs(i - index) ? num_index - abs(i - index) : 0);
        }
        return sum;
    }
};