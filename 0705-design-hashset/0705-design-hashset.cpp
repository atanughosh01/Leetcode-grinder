/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */


class MyHashSet_1 {
public:
    vector<bool> hash_table;
    int len = 1e6 + 1;
    MyHashSet_1() {
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


class MyHashSet {
private:
    int prime;
    vector<list<int>> table;
    
    int hash(int key) {
        return key % prime;
    }
    
    list<int>::iterator search(int key) {
        int h = hash(key);
        return find(table[h].begin(), table[h].end(), key);
    }
public:
    MyHashSet() : prime(100), table(prime) {}
    
    void add(int key) {
        int h = hash(key);
        if (!contains(key)) {
            table[h].push_back(key);
        }
    }
    
    void remove(int key) {
        int h = hash(key);
        auto it = search(key);
        if (contains(key)) {
            table[h].erase(it);
        }
    }
    
    bool contains(int key) {
        int h = hash(key);
        auto it = search(key);
        return it != table[h].end();
    }
};
