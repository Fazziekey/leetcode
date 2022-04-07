class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.size() != goal.size())
            return false;

        int size = s.size();
        bool flag = false;
        for(int i = 0;i < size;i++){
            for(int j = 0;j < size;j++){
                if(s[(j + i)%size] != goal[j])
                    break;
                if(j == size - 1)
                    flag = true;
            }
            if(flag == true)
                break;
        }
        return flag;
    }
};