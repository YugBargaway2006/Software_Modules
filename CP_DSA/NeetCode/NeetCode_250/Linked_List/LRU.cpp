class LRUCache {
public:
    int max_size;
    int size;
    unordered_map<int, list<pair<int, int>>::iterator> store;
    list<pair<int, int>> dll;

    LRUCache(int capacity) {
        max_size = capacity;
        size = 0;
        store.reserve(max_size);
    }
    
    int get(int key) {
        auto it = store.find(key);
        if(it == store.end()) {
            return -1;
        }

        auto list_it = it -> second;
        int value = list_it -> second;

        dll.splice(dll.end(), dll, list_it);
        return value;
    }
    
    void put(int key, int value) {
        if(get(key) != -1) {
            auto it = prev(dll.end());
		    it -> second = value;
		    return;
        }

        pair<int, int> cur = {key, value};

        if(size == max_size) {
            int key = dll.front().first;
            dll.pop_front();
            
            store.erase(key);		
            size -= 1;
        }

        dll.push_back(cur);
        auto it = prev(dll.end());
        
        store[key] = it;
        size += 1;
    }
};
