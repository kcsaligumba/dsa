class LRUCache {
public:
    unordered_map<int, pair<int, list<int>::iterator>> cache;
    list<int> lru;
    int cap;

    LRUCache(int capacity) {
        cap = capacity;
    }
    
    int get(int key) {
        if (cache.find(key) != cache.end()) {
            lru.erase(cache[key].second);
            lru.push_back(key);
            cache[key].second = --lru.end();
            return cache[key].first;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if (cache.find(key) != cache.end()) lru.erase(cache[key].second);
        else if (cache.size() == cap) {
            cache.erase(lru.front());
            lru.pop_front();
        }
        lru.push_back(key);
        cache[key] = {value, --lru.end()};
    }
};
