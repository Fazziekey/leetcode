class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        map<int,vector<int>> maps;
        vector<vector<int>> group;
        int len = 0;
        for(int i = 0;i < groupSizes.size();i++){
            if(maps.find(groupSizes[i]) == maps.end()){
                maps[groupSizes[i]] = {len,1};
                group.push_back(vector<int>{i});
                len++;
            }else{
                if(maps[groupSizes[i]][1] == groupSizes[i]){
                    group.push_back(vector<int>{i});
                    maps[groupSizes[i]][1] = 1;
                    maps[groupSizes[i]][0] = len;
                    len++;
                }else{
                    group[maps[groupSizes[i]][0]].push_back(i);
                    maps[groupSizes[i]][1]++;
                }
            }
        }
        return group;
    }
};