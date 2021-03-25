#include <string>
#include <iostream>
class Solution {
public:
    string replaceSpace(string s) {
        int count=0,len=s.size();
        for (char c: s){
            if(c==' ')
                count++;
        }
        s.resize(len+2*count);
        int i = len,j=s.size();
        for(;i>=0;i--){
            if(s[i] != ' '){
                s[j]=s[i];
                j--;
            }
            else {
                s[j]='0';
                s[j-1]='2';
                s[j-2]='%';
                j=j-3;
            }
        }
        return s;
    }

};