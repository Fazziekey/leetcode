class Solution {
public:
    int majorityElement(vector<int>& nums) {    
//摩尔投票法，投我++，不投--，超过一半以上的人投我，那我稳赢哇
        int count = 0, candidate = 0;
        for(int n : nums)
        {
            if(count == 0)        candidate = n;

            if(n == candidate)    count++;
            else                  count--;
        }
        return candidate;
    }
};



