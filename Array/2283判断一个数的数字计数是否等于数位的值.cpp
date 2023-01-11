class Solution {
public:
    bool digitCount(string num) {
        map<int, int> maps;
        for(auto c : num){
            int n = c - '0';
            maps[n] += 1;
            // cout << n << maps[n] <<endl;
        }
        for(int i = 0; i < num.size();i++){
            if(maps[i] != num[i] - '0'){
                return false;
            }
        }
        return true;
    }
};