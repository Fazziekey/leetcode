class Solution {
public:
    vector<int> numberOfLines(vector<int>& widths, string s) {
        vector<int> result;
        map<char, int> alpha_map;
        for(int i = 0;i<26;i++){
            alpha_map['a' + i] = widths[i];
        }
        int sum = 0;
        int row = 1;
        for(auto c : s){
            if(sum + alpha_map[c] <= 100){
                sum += alpha_map[c];
            }else{
                sum = alpha_map[c];
                row++;
            }
        }
        result.push_back(row);
        result.push_back(sum);
        return result;
    }
};