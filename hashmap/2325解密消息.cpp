class Solution {
public:
    string decodeMessage(string key, string message) {
        map<char,char> mapping_key;
        int index = 0;
        for(auto k : key){
            if(k >= 'a' && k <='z' && mapping_key.find(k) == mapping_key.end()){
                mapping_key[k] = 'a' + index;
                index++;
            }
        }
        for(int i = 0; i < message.size();i++){
            if(message[i] >= 'a' && message[i] <='z')
                message[i] = mapping_key[message[i]]; 
        }
        return message;
    }
};