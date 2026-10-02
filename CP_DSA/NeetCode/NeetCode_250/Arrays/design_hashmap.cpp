class MyHashMap {
public:
    int mxn = 1e6+1;
    vector<int> storage;

    MyHashMap() {
        storage.assign(mxn, -1);
    }
    
    void put(int key, int value) {
        storage[key] = value;
    } 
    
    int get(int key) {
        return storage[key];
    }
    
    void remove(int key) {
        storage[key] = -1;
    } 
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */