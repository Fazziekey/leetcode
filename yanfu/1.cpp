# include <iosfwd>

# include <regex>
/*
a class that can be used to iterate over a stream of integers
a valid stream is a sequence of integers separated by whitespac

*/
class Solution {

public:
    Solution(istream& s){
        char c;
        string tmp;
        while(s >> c) {
            if(c == ' ') {
                data.push_back(atoi(tmp.c_str()));
                tmp.clear();
            } else {
                tmp += c;
            }
        }
    }
    class iterator;

    iterator begin(){return data.begin();};
    iterator end(){return data.end();};

private:
    vector<int> data;

};
    


/**
 Solution sol(stream):
    for(Suolution::iterator it = sol.begin(); it != sol.end(); ++it) {
        it x = *it;
        cout << x << endl;
    }

*/