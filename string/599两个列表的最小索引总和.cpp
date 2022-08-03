class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        unordered_map<string,int> hashmap;
        vector<string> min_canteen;
        int index = 0;
        int min_index = 2000;
        for(auto list : list1){
            hashmap.insert(pair<string,int>(list,index));
            index++;
        }
        index = 0;
        for(auto list : list2){
            if(hashmap.find(list) != hashmap.end()){
                if(index + hashmap[list] < min_index){
                    min_index = index + hashmap[list];
                    min_canteen.clear();
                    min_canteen.push_back(list);
                } else if(index + hashmap[list] == min_index){
                    min_canteen.push_back(list);
                }
            }
            index ++;
            if(index > min_index)
                break;
        }
        return min_canteen;
    }
};