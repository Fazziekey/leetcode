#include <string>
#include <map>
class Solution {
public:
    string greatestLetter(string s) {
        map<char, int> maps;
        string cur = ""; 
        for(auto c: s){
            if(c >= 'a' && c <= 'z'){
                if(maps.find(c + 'A' - 'a') != maps.end()){
                    if(cur == "" || c + 'A' - 'a' > cur[0]){
                        cur = c + 'A' - 'a';
                    }
                }
                maps[c] = 1;
            }else if(c >= 'A' && c <='Z'){
                if(maps.find(c + 'a' - 'A') != maps.end()){
                    if(cur == "" || c > cur[0]){
                        cur = c;
                    }
                }
                maps[c] = 1;
            }
        }
        return cur;
    }
};