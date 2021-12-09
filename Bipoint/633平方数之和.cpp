class Solution {
public:
    bool judgeSquareSum(int c) {
        long i = 0;
        long j = sqrt(c);
        while(i <= j){
            long count = i * i + j * j;
            if(count == c)
                return true;
            else if(count < c)
                i++;
            else    
                j--;
        }
        return false;

    }
};