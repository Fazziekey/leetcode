class Solution {
public:
    bool hasAlternatingBits(int n) {
        int now = n % 2;
        while(n > 0){
            n /= 2;
            int tmp = n % 2;
            if(tmp == now)
                return false;
            now = tmp;
        }
        return true;
    }
};