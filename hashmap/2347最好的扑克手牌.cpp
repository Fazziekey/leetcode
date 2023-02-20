class Solution {
public:
    string bestHand(vector<int>& ranks, vector<char>& suits) {
        for(int i = 0;i < 4; i++){
            if(suits[i] != suits[i+1]){
                break;
            }
            if(i == 3){
                return "Flush";
            }
        }

        map<int, int> maps;
        int max_num = 0;
        for(int i = 0;i < 5;i++){
            maps[ranks[i]] += 1;
            max_num = max(max_num, maps[ranks[i]]);
        }
        if(max_num >= 3){
            return "Three of a Kind";
        }else if(max_num == 2){
            return "Pair";
        }

        return "High Card";
    }
};