class Solution {
public:
    int bestRotation(vector<int>& A) {
        int n = A.size(), resK = 0;//resK用于记录当K = resK时，此时A数组中部分的个数最少（即A数组中得分的个数最多）
        vector<int> myK(n, 0);//myK[k]代表当K = k时，A数组中不得分的个数
        //第一步：将A数组中所有元素都向左移动(i - A[i] + 1 + n) % n个位置，即K = (i - A[i] + 1 + n) % n，此时A[i]刚好不得分
        for (int i = 0; i < n; ++i) {
            myK[(i - A[i] + 1 + n) % n] += 1;//当K = (i - A[i] + 1 + n) % n时，不得分的个数自增
        }
        //第二步：寻找最优的resK（当K = resK时，此时A数组中部分的个数最少（即A数组中得分的个数最多））
        for (int i = 1; i < n; ++i) {
            //递推式当K = i - 1增大到到K = i时
            //在K = i - 1时不得分的继续不得分，蛋式当K = i - 1转换到K = i时，处于A[0]的元素开始得分
            myK[i] += myK[i - 1] - 1;
            if (myK[i] < myK[resK]){//K = resK时，此时A数组中部分的个数最少（即A数组中得分的个数最多）
                resK = i;
            }
        }
        return resK;
    }
};