class Solution {
public:
    bool areNumbersAscending(string s) {
        int pre = 0;
        int tmp = 0;
        for (auto c : s) {
            cout << c;
            if (c >= '0' && c <= '9') {
                tmp = tmp * 10 + c - '0';
            } else {
                if (tmp) {
                    if (tmp <= pre) {
                        return false;
                    }
                    pre = tmp;
                    tmp = 0;
                }
            }
        }
        if (tmp) {
            if (tmp <= pre) {
                return false;
            }
        }
        return true;
    }
};