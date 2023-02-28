class Solution {
public:
    vector<vector<int>> mergeSimilarItems(vector<vector<int>>& items1, vector<vector<int>>& items2) {
        map<int, int> maps;
        vector<vector<int>> result;
        for(auto it : items1){
            maps[it[0]] += it[1];
        }
        for(auto it : items2){
            maps[it[0]] += it[1];
        }
        for(auto [key, value] : maps){
            result.push_back({key, value});
        }
        sort(result.begin(), result.end());
        return result;
    }
};