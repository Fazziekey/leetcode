class RandomizedSet {
public:
    
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(this->sets.find(val) != this->sets.end()){
            return false;
        }else{
            this->sets.insert(val);
            return true;
        }
        return false;
    }
    
    bool remove(int val) {
        if(this->sets.find(val) != this->sets.end()){
            this->sets.erase(val);
            return true;
        }else{
            return false;
        }
        return false;
    }
    
    int getRandom() {
        int lenth = this->sets.size();
        int random = rand() % lenth;
        auto iter = this->sets.begin();
        while(random > 0){
            iter++;
            random--;
        }
        return *iter;
    }

private:
    set<int> sets;

};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */