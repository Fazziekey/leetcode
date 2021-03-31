class Solution {
public:
    int findNthDigit(int n) {
         long long i = 1, s = 9, base = 1;//i表示是几位数，s表示位数共有多少个，base表示位数的起始值。
         while(n > i * s) {   
             n -= i * s;       
             i ++;               
             s *= 10;
             base *= 10;
         }
         int number = base + (n -1)/ i ; 
         int r = (n-1) % i;           
         for (int j = 0; j < i - r - 1; j ++) number /= 10; 
         return number % 10;
    }
};