class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int count = 0;
        int index = 0;
        for(int i = 0;i < s1.size();i++){
            if(s1[i] != s2[i]){
                if(count == 0){
                    count++;
                    index = i;
                }else if(count == 1){
                    if(s1[index] != s2[i] || s2[index] != s1[i]){
                        return false;
                    }else{
                        count++;
                    }
                }else{
                    return false;
                }
            }            
        }
        if(count != 0 && count != 2)
            return false;
        return true;
    }
};