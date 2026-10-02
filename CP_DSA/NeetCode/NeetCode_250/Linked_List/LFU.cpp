class LFUCache {
public:
    int size;
    int max_size;
    int min_freq;

    unordered_map<int, list<int>> freq;
    unordered_map<int, pair<int, int>> store;
    unordered_map<int, list<int>::iterator> pos;

    LFUCache(int capacity) {
        size = 0;
        min_freq = 0;
        max_size = capacity;
        store.reserve(max_size);
        freq.reserve(max_size);
        pos.reserve(max_size);
    }
    
    int get(int key) {
        auto it = store.find(key);
        if(it == store.end()) {
            return -1;
        }

        auto [value, ct] = store[key];
        freq[ct].erase(pos[key]);

        if(freq[ct].empty()) {
            freq.erase(ct);
            if(min_freq == ct) min_freq++;
        }

        store[key].second += 1;
        freq[ct + 1].push_front(key);
        pos[key] = freq[ct + 1].begin();

        return value;
    }
    
    void put(int key, int value) {
        if (max_size == 0) return;

        if (store.count(key)) {
            store[key].first = value;
            get(key); 
            return;
        }

        if (store.size() == max_size) {
            int evict = freq[min_freq].back();
            freq[min_freq].pop_back();

            if (freq[min_freq].empty())
                freq.erase(min_freq);

            store.erase(evict);
            pos.erase(evict);
        }

        store[key] = {value, 1};
        freq[1].push_front(key);
        pos[key] = freq[1].begin();
        min_freq = 1;
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */