class Solution {
public:
    int countDigitOne(int n) {
        if(n==1)
            return 1;
        int times;
        while(n!=0){
            if(n%10 == 1)
                times++;
            n = n/10;
        }
        return times + countDigitOne(n-1); 
    }
};