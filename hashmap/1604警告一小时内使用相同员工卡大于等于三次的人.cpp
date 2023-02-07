class Solution {
public:
    vector<string> alertNames(vector<string>& keyName, vector<string>& keyTime) {
        map<string, vector<string>> time_map;
        vector<string> result;
        for(int i = 0;i < keyName.size(); i++){
            if(time_map.find(keyName[i]) == time_map.end()){
                time_map[keyName[i]].push_back(keyTime[i]);
            }else{
                time_map[keyName[i]].push_back(keyTime[i]);
                int s = time_map[keyName[i]].size();
                if(s >= 3){
                    string time_start = time_map[keyName[i]][s-3];
                    string time_end = time_map[keyName[i]][s-1];
                    int time_gap = culculateTime(time_start, time_end);
                    if(time_gap <= 60 && time_gap > 0){
                        result.push_back(keyName[i]);
                    }
                }
            }
        }
        sort(result.begin(),result.end());
        return result;
    }
    int culculateTime(string time_start, string time_end){
        int hour = (time_end[0] - '0') * 10 + (time_end[1] - '0') - (time_start[0] - '0') * 10 - (time_start[1] - '0');
        int second  = (time_end[3] - '0') * 10 + (time_end[4] - '0') - (time_start[3] - '0') * 10 - (time_start[4] - '0');
        return hour * 60 + second;
    }
};