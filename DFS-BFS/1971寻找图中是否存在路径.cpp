# include <iostream>
# include <vector>
# include <unordered_map>
# include <queue>
using namespace std;
class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        if (source == destination) return true;
        unordered_map<int, vector<int>> graph;
        for (auto edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        vector<bool> visited(n, false);
        visited[source] = true;
        queue<int> q;
        q.push(source);
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            for (auto neighbor : graph[node]) {
                if (neighbor == destination) return true;
                if (visited[neighbor]) continue;
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
        return false;
    }
};