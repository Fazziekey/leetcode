/*
 There is a broad with 2 rows and N columns. represented by a matrix M,
 Rows are numbered 0 and 1, columns are numbered 0 to N-1 from left to right.
 each cell of the matrix contains either 0 or 1.

 you knows that:
 1.the sum of the integers in the first row is U
2.the sum of the integers in the second row is L
3.the sum of the integers in each column is equal to C[K]

Write a function that returns a string representing the matrix M,

if there is no solution, return "IMPOSSIBLE"
*/ 

string solution(int U, int L, vector<int> &C) {
    // Implement your solution here

    int n = C.size();
    vector<int> row1(n, 0);
    vector<int> row2(n, 0);
    string s;
    int sum1 = 0;
    int sum2 = 0;

    for(int i = 0; i < n; i++) {
        if(C[i] == 2) {
            row1[i] = 1;
            row2[i] = 1;
            sum1++;
            sum2++;
        } else if(C[i] == 1) {
            if(sum1 < U) {
                row1[i] = 1;
                sum1++;
            } else if(sum2 < L) {
                row2[i] = 1;
                sum2++;
            } else {
                return "IMPOSSIBLE";
            }
        }
    }
    
    if(sum1 == U && sum2 == L){
        for(int i = 0; i < n; i++) {
            s += to_string(row1[i]);
        }
        s += ",";
        for(int i = 0; i < n; i++) {
            s += to_string(row2[i]);
        }
        return s;
    } else {
        return "IMPOSSIBLE";
    }
    return "IMPOSSIBLE";
}