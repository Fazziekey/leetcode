// Input
// The input consists of:

// one line with one integer  (), the number of submissions;

//  lines, each with a result of the judging by DOMjudge, in arbitrary order;

//  lines, each with a result of the judging by Kattis, in arbitrary order.

// Each result is a string of length between  and  characters (inclusive) consisting of lowercase letters.

// Output
// Output one line with the maximum number of judging results that could have been the same for both systems.

// Sample Input 1	Sample Output 1
// 5
// correct
// wronganswer
// correct
// correct
// timelimit
// wronganswer
// correct
// timelimit
// correct
// timelimit

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    map<string,int> domjudge;
    map<string,int> kattis;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        domjudge[s]++;
    }
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        kattis[s]++;
    }
    int count = 0;
    for (auto it = domjudge.begin(); it != domjudge.end(); it++) {
        count += min(it->second, kattis[it->first]);
    }
    cout << count << endl;
    return 0;
}