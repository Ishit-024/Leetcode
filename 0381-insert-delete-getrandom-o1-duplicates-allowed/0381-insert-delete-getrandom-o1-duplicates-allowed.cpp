class RandomizedCollection {
public:
    RandomizedCollection() {
        // RandomizedCollection obj=new RandomizedCollection();
    }
    bool insert(int val) {
        values.push_back(val);
        mp[val]++;
        if(mp[val]==1){
            return true;
        }
        return false;
        }
    bool remove(int val) {
       if (mp[val] == 0) {
            return false;
        }

        mp[val]--;
        auto it = find(values.begin(), values.end(), val);
        if (it != values.end()) {
            swap(*it,values[values.size()-1]);
            values.pop_back();
        }
        return true;
    }
    int getRandom(){
        int randomIndex = rand() % values.size();
        return values[randomIndex];
    }
    private:
    std::vector<int> values;
    std::unordered_map<int,int> mp;
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */