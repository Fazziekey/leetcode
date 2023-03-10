/*
算 24点
*/

#include <iostream>
#include <algorithm>
using namespace std;
bool Cal(int a, int b, int c, int d){
    int arr[4] = {a, b, c, d};
    sort(arr, arr + 4);
    do{
        if(arr[0] + arr[1] + arr[2] + arr[3] == 24) return true;
        if(arr[0] + arr[1] + arr[2] - arr[3] == 24) return true;
        if(arr[0] + arr[1] - arr[2] - arr[3] == 24) return true;
        if(arr[0] - arr[1] - arr[2] - arr[3] == 24) return true;
        if(arr[0] + arr[1] - arr[2] + arr[3] == 24) return true;
        if(arr[0] - arr[1] + arr[2] - arr[3] == 24) return true;
        if(arr[0] - arr[1] + arr[2] + arr[3] == 24) return true;
        if(arr[0] + arr[1] + arr[2] * arr[3] == 24) return true;
        if(arr[0] + arr[1] * arr[2] * arr[3] == 24) return true;
        if(arr[0] * arr[1] * arr[2] * arr[3] == 24) return true;
        if(arr[0] * arr[1] * arr[2] + arr[3] == 24) return true;
        if(arr[0] * arr[1] + arr[2] + arr[3] == 24) return true;
        if(arr[0] * arr[1] + arr[2] * arr[3] == 24) return true;
        if(arr[0] * arr[1] - arr[2] - arr[3] == 24) return true;
        if(arr[0] * arr[1] - arr[2] + arr[3] == 24) return true;
        if(arr[0] * arr[1] - arr[2] * arr[3] == 24) return true;
        if(arr[0] * arr[1] + arr[2] - arr[3] == 24) return true;
        if(arr[0] * arr[1] * arr[2] - arr[3] == 24) return true;
        if(arr[0] * arr[1] - arr[2] * arr[3] == 24) return true;
        if(arr[0] * arr[1] - arr[2] * arr[3] == 24) return true;
        if(arr[0] + arr[1] + arr[2] / arr[3] == 24) return true;
        if(arr[0] + arr[1] / arr[2] / arr[3] == 24) return true;
        if(arr[0] / arr[1] / arr[2] / arr[3] == 24) return true;
        if(arr[0] / arr[1] / arr[2] + arr[3] == 24) return true;
        if(arr[0] / arr[1] + arr[2] + arr[3] == 24) return true;
        if(arr[0] / arr[1] + arr[2] / arr[3] == 24) return true;
        if(arr[0] / arr[1] - arr[2] - arr[3] == 24) return true;
        if(arr[0] / arr[1] - arr[2] + arr[3] == 24) return true;
        if(arr[0] / arr[1] - arr[2] / arr[3] == 24) return true;
        if(arr[0] / arr[1] + arr[2] - arr[3] == 24) return true;
        if(arr[0] / arr[1] * arr[2] * arr[3] == 24) return true;
        if(arr[0] / arr[1] * arr[2] + arr[3] == 24) return true;
        if(arr[0] / arr[1] * arr[2] - arr[3] == 24) return true;
        if(arr[0] / arr[1] * arr[2] / arr[3] == 24) return true;
        if(arr[0] / arr[1] + arr[2] * arr[3] == 24) return true;
        if(arr[0] / arr[1] - arr[2] * arr[3] == 24) return true;
        if(arr[0] / arr[1] * arr[2] - arr[3] == 24) return true;
        if(arr[0] / arr[1] * arr[2] / arr[3] == 24) return true;
        if(arr[0] + arr[1] * arr[2] / arr[3] == 24) return true;
        if(arr[0] * arr[1] * arr[2] / arr[3] == 24) return true;
        if(arr[0] * arr[1] / arr[2] / arr[3] == 24) return true;
        if(arr[0] * arr[1] / arr[2] + arr[3] == 24) return true;
        if(arr[0] * arr[1] / arr[2] - arr[3] == 24) return true;
        if(arr[0] * arr[1] / arr[2] * arr[3] == 24) return true;
        if(arr[0] * arr[1] / arr[2] / arr[3] == 24) return true;
        if(arr[0] * arr[1] + arr[2] / arr[3] == 24) return true;
        if(arr[0] * arr[1] - arr[2] / arr[3] == 24) return true;
        if(arr[0] * arr[1] / arr[2] - arr[3] == 24) return true;
        if(arr[0] * arr[1] / arr[2] * arr[3] == 24) return true;
        if(arr[0] * arr[1] / arr[2] / arr[3] == 24) return true;
        if(arr[0] + arr[1] / arr[2] * arr[3] == 24) return true;
        if(arr[0] / arr[1] / arr[2] * arr[3] == 24) return true;
        if(arr[0] / arr[1] * arr[2] / arr[3] == 24) return true;
        if(arr[0] / arr[1] * arr[2] + arr[3] == 24) return true;
    }while(next_permutation(arr, arr + 4));
    return false;
}

int main(){
    int a, b, c, d;
    while(cin >> a >> b >> c >> d){
        if(Cal(a, b, c, d)) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    return 0;
}