# include <iostream>
# include <vector>
# include <string>
# include <unordered_map>
class Solution {
public:
    bool checkIfPangram(string sentence) {
        if (sentence.size() < 26) {
            return false;
        }
        unordered_map<char, int> alphabet;
        for (int i = 0; i < sentence.size(); i++) {
            alphabet[sentence[i]] = 1;
        }
        if (alphabet.size() == 26) {
            return true;
        }
        return false;
    }
};