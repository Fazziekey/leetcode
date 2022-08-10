class Solution {
public:
    string solveEquation(string equation) {
        int x = 0;
        int num = 0;
        int flag = 1;
        int op = 1;
        int lenth = equation.size();
        for(int i = 0;i < lenth;i++){
            if(equation[i] >= '0' && equation[i] <= '9'){
                int n = equation[i] - '0';
                op = 1;
                if(i > 0){
                    if(equation[i-1] == '-'){
                        op = -1;
                    }
                }
                while(i <= lenth - 1 && equation[i+1] >= '0' && equation[i+1] <= '9'){
                    i++;
                    n = n * 10 + equation[i] - '0';
                }
                if(i <= lenth - 1 && equation[i+1] == 'x'){
                    x = x + flag * op * n;
                    i++;
                }else{
                    num = num + flag * op * n;
                }
            }
            else if(equation[i] == '='){
                flag = -1;
            }else if(equation[i] == 'x'){
                op = 1;
                if(i > 0){
                    if(equation[i-1] == '-'){
                        op = -1;
                    }
                }
                x += flag * op;
            }
        } 
        if(x == 0){
            if(num != 0){
                return "No solution";
            }
            return "Infinite solutions";
        }
        cout << "num" << num << "x" << x;
        int result = -num / x;
        return "x=" + to_string(result);
    }
};