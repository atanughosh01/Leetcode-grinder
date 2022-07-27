class MyHashSet {
public:
    vector<bool> hash_table = {};
    int len = 1e6 + 1;
    MyHashSet() {
        hash_table.resize(len, false);
    }
    
    void add(int key) {
        hash_table[key] = true;
    }
    
    void remove(int key) {
        hash_table[key] = false;
    }
    
    bool contains(int key) {
        return hash_table[key];
    }
};


/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */
