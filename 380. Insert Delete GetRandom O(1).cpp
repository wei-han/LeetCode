class RandomizedSet {
public:
    /** Initialize your data structure here. */
    RandomizedSet() {
        
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if(hash.find(val)!=hash.end()) return false;
        set.push_back(val);
        hash[val] = set.size()-1;
        return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if(hash.find(val) == hash.end()) return false;
        int last = set.back();
        int target = hash[val];
        set[target] = last;
        hash[last] = target;
        hash.erase(val);
        set.pop_back();
        return true;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        return set[rand()%set.size()];
    }
    
    unordered_map<int, int> hash;
    vector<int> set;
};
