class MyHashSet {
public:
    int mxn = 1e6+1;
    vector<bool> storage;

    MyHashSet() {
        storage.assign(mxn, false);
    }
    
    void add(int key) {
        storage[key] = storage[key] || true;
    }
    
    void remove(int key) {
        storage[key] = false;
    }
    
    bool contains(int key) {
        return storage[key];
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */