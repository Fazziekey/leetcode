class Solution {
public:
    string convertToBase7(int num) {
        int flag = 1;
        int sum = 0;
        int i = 1;
        if(num == 0)
            return to_string(num);
        if(num < 0){
            num = (- num);
            flag = -1;
        }
        while(num > 0){
            sum = sum + (num % 7) * i;
            i *= 10;
            num /= 7;
        }
        if(flag == -1)
            sum = -sum;

        return to_string(sum);

    }
};