// Compiled with: g++ -Wall -std=c++14 -pthread

#include <iostream>
#include <vector>
#include <string>
using namespace std;

/*
P1: Find the total islands on a 2d map

0 1 0 0
0 1 0 1
0 0 1 0


void dfs(vector<vector<int>> island, vector<vector<int>> visit, int i, int j, int m, int n){
    if(island[i][j] == 0 || visit[i][j] == 1){
        return;
    }
    visit[i][j]= 1;
    if(i > 0){
        dfs(island, visit, i - 1, j, m, n);
    }
    if(j > 0){
        dfs(island, visit, i, j-1, m, n);
    }
    if(i < m){
        dfs(island, visit, i + 1, j, m, n);
    }
    if(j < n){
        dfs(island, visit, i, j + 1, m, n);
    }
    return;
}


int main(){
    cout << "Hello, World!" << endl;

    vector<vector<int>> island();
    
    time(n^2)
    Memory(n^2)
    
        
    vector<vector<int>> visit(m,vector<int>(n,0));
    int count = 0;
    
    
    for(int i = 0; island.size();i++){
        for(int j = 0; island[0].size();j++){
            if(island[i][j] == 1){
                if(visit[i][j] == 1){
                    continue;
                }else{
                    dfs(island, visit, i, j, m, n);
                    count ++;
                }
            }
        }
    }
    return 0;
}

*/


/*
Given a 2d matrix A, A[x, y] != A[i, j] ((x, y) != (i, j)) and A[x, y] > A[x - 1, y] and A[x, y] > A[*, y - 1], Search for an input K


 1  4  5   6
 7  9  15 18
20 24  30 99

147
258
369

k = 6
=> (2, 1)
*/

vector<int> search(vector<vector<int>> matrix, int k){
    int low = 0;
    int row = matrix.size();
    int col = matrix[0].size();
    int high = row * col;
    int mid = (low + high)/2;
     
    int i = mid / row;
    int j = mid % row;
    
    if(matrix[i][j] == k){
        return {i,j};
    }
    while(mid != low && mid != high){
        if(matrix[i][j] > k){
            high = mid;
        }else{
            low = mid;
        }
        mid = (low + high)/2;
        i = mid / row;
        j = mid % row;
        if(matrix[i][j] == k){
            return {i,j};
        }
    }
    return {-1,-1};
    
}







