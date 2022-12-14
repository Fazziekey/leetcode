# include<vector>
# include<algorithm>
# include<iostream>
# include<queue>
# include<unordered_map>
using namespace std;

class Solution {
public:
    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList, vector<vector<int>>& queries) {
        vector<bool> ans(queries.size(), false);
        unordered_map<int, unordered_map<int,int>> edgeMap;
        unordered_map<int, unordered_map<int,int>> distanceMap;
        for (int i = 0; i < edgeList.size(); i++) {
            if (edgeMap[edgeList[i][0]].find(edgeList[i][1]) == edgeMap[edgeList[i][0]].end()) {
                edgeMap[edgeList[i][0]][edgeList[i][1]] = edgeList[i][2];
                distanceMap[edgeList[i][0]][edgeList[i][1]] = edgeList[i][2];
            }
            else {
                edgeMap[edgeList[i][0]][edgeList[i][1]] = max(edgeMap[edgeList[i][0]][edgeList[i][1]], edgeList[i][2]);
                distanceMap[edgeList[i][0]][edgeList[i][1]] = max(distanceMap[edgeList[i][0]][edgeList[i][1]], edgeList[i][2]);
            }
            if (edgeMap[edgeList[i][1]].find(edgeList[i][0]) == edgeMap[edgeList[i][1]].end()) {
                edgeMap[edgeList[i][1]][edgeList[i][0]] = edgeList[i][2];
                distanceMap[edgeList[i][1]][edgeList[i][0]] = edgeList[i][2];
            }
            else {
                edgeMap[edgeList[i][1]][edgeList[i][0]] = max(edgeMap[edgeList[i][1]][edgeList[i][0]], edgeList[i][2]);
                distanceMap[edgeList[i][1]][edgeList[i][0]] = max(distanceMap[edgeList[i][1]][edgeList[i][0]], edgeList[i][2]);
            }
        }
        for (int i = 0; i < queries.size(); i++) {
            if(distanceMap[queries[i][0]].find(queries[i][1]) != distanceMap[queries[i][0]].end() && distanceMap[queries[i][0]][queries[i][1]] < queries[i][2]){
                ans[i] = true;
                continue;
            }
            queue<int> q;
            vector<bool> visited(n, false);
            q.push(queries[i][0]);
            visited[queries[i][0]] = true;
            while (!q.empty()) {
                int cur = q.front();
                q.pop();
                if (cur == queries[i][1]) {
                    ans[i] = true;
                    break;
                }
                for (auto it = edgeMap[cur].begin(); it != edgeMap[cur].end(); it++) {
                    if (!visited[it->first] && it->second < queries[i][2]) {
                        q.push(it->first);
                        visited[it->first] = true;
                        if (distanceMap[queries[i][0]].find(it->first) == distanceMap[queries[i][0]].end()) {
                            distanceMap[queries[i][0]][it->first] = it->second;
                        }
                        else{
                            distanceMap[queries[i][0]][it->first] = max(distanceMap[queries[i][0]][it->first], it->second);
                        }
                    }
                }
            }

        }
        return ans;
    }
};

int main() {
    int n;
    vector<vector<int>> edgeList;
    vector<vector<int>> queries;
    cin >> n;
    for (int i = 0; i < n; i++) {
        vector<int> edge;
        int a, b, c;
        cin >> a >> b >> c;
        edge.push_back(a);
        edge.push_back(b);
        edge.push_back(c);
        edgeList.push_back(edge);
    }
    int m;
    cin >> m;
    for (int i = 0; i < m; i++) {
        vector<int> query;
        int a, b, c;
        cin >> a >> b >> c;
        query.push_back(a);
        query.push_back(b);
        query.push_back(c);
        queries.push_back(query);
    }
    Solution().distanceLimitedPathsExist(n, edgeList, queries);
}
