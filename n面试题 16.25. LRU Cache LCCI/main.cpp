// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

class LRUCache {
public:
    LRUCache(int capacity) {
        this->cap = capacity;
    }
    
    int get(int key) {
        auto it = map.find(key);
        if(it != map.end()) {
            auto kv = *map[key];
            cache.erase(map[key]);
            cache.push_front(kv);
            map[key] = cache.begin();
            return kv.second;
        } else {
            return -1;
        }
    }
    
    void put(int key, int value) {
        auto it = map.find(key);
        if(it != map.end()) {
            cache.erase(map[key]);
        } else {
            if(cap == cache.size()) {
                auto lst = cache.back();
                map.erase(lst.first);
                cache.pop_back();
            }
        }
        cache.push_front(make_pair(key, value));
        map[key] = cache.begin();
    }

private:
    int cap;
    list<pair<int, int>> cache;
    unordered_map<int, list<pair<int, int>>::iterator> map;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
