    void put(int key, int value) {
        auto it = cache.find(key);
        if(it == cache.end()){
            if(cache.size() == cap){
                cache.erase(used.back());
                used.pop_back();
            }
            used.push_front(key);

        }
        else{
            change(it);
        }
        cache[key] = {used.begin(), value};                            
    }
    
private:
    int cap;
    list<int> used;
    unordered_map<int, pair<list<int>::iterator,int>> cache;
    void change(unordered_map<int,pair<list<int>::iterator, int>>::iterator it){
        int key = it->first;
        used.erase(it->second.first);
        used.push_front(key);
        it->second.first = used.begin();
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */
