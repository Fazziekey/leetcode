/*
There is N given points(numbered 0 to N-1) on a plane, the K-th point is at coordinates (X[K], Y[K])., and its tag is S[K].

we want to draw a circle centerd at (0,0), the circle should not contain two points with same tag, 
what is the maximum number of points that can lie inside the circle 

eg:
S="ABDCA" X=[2, -1, -4, -3, 3] Y=[2, -2, 4, 1, -3]
*/
#include <algorithm>
#include <map>

int solution(string &S, vector<int> &X, vector<int> &Y) {
    // Implement your solution here

    int n = S.size();
    if(n == 0) return 0;
    if(n == 1) return 1;

    int count = 0;
    vector<vector<int>> dis_and_tag(n, vector<int>(2, 0));
    for(int i = 0; i < n; i++) {
        dis_and_tag[i][0] = X[i] * X[i] + Y[i] * Y[i];
        dis_and_tag[i][1] = S[i] - 'A';
    }
    sort(dis_and_tag.begin(), dis_and_tag.end());
    map<int, int> tag_count;
    for(int i = 0; i < n; i++) {
        if(tag_count.find(dis_and_tag[i][1]) == tag_count.end()){
            tag_count[dis_and_tag[i][1]] = 1;
            count++;
        }
        else {
            if(dis_and_tag[i][0] == dis_and_tag[i-1][0] && dis_and_tag[i][1] == dis_and_tag[i-1][1]){
                return count - 1;
            }
            return count;
        }
    }
    return count; 
}
