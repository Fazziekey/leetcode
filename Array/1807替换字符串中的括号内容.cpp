class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        string res;
        int i = 0;
        int size = s.size();
        map<string, string> maps;

        for(auto v : knowledge){
            maps[v[0]] = v[1];
        }

        while(i < size){
            string tmp;
            while(s[i] != '(' && i < size){
                res += s[i];
                i++;
            }
            i++;
            if(i >= size){
                break;
            }
            while(s[i] != ')' && i < size){
                tmp += s[i];
                i++;
            }
            if(i >= size){
                break;
            }
            if(maps.find(tmp) != maps.end()){
                res += maps[tmp]; 
            }else{
                res += '?';
            }
            i++;
        }
        return res;
    }
};