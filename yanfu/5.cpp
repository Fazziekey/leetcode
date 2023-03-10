/*
There are N houses (numbered 1 to N) in a row.

the first type cost X, the second type cost Y, return the minimum cost to build all the houses
given A = [5,3,8,3,2], X = 2, Y = 5
return 2
*/

#include <algorithm>

int solution(vector<int> &A, int X, int Y) {
    // Implement your solution here
    int n = A.size();
    sort(A.begin(), A.end(), [](int a, int b) {return a > b;});

    int min_cost = n * Y;
    int sum = 0;
    for(int i = 0; i < n; i++) {
        sum += A[i];
    }

    for(int i = 0; i < n; i++) {
        int cost = 0;
        int count = 0;
        for(int j = 0; j < i; j++) {
            cost += Y;
            count += A[j];
        }
        if(count >= sum - count) {
            min_cost = min(min_cost, cost);
            break;
        }

        int end = n - 1;
        while (count >= A[end] && end > i)
        {
            count -= A[end];
            end--;
        }

        cost += (end - i + 1) * X;
        min_cost = min(min_cost, cost);
    }
    return min_cost;
}

2 2 2 2 1

3 + 