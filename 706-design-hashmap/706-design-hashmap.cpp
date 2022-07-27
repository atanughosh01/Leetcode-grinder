class MyHashMap {
private:
	int prime;
	vector<list<pair<int, int>>> table;

	int hash(int key) {
		return key % prime;
	}

	list<pair<int, int>>::iterator search(int key) {
		int h = hash(key);
		auto it = table[h].begin();
		while (it != table[h].end()) {
			if (it->first == key) {
				return it;
			}
			it++;
		}
		return it;
	}

public:
	MyHashMap() : prime(1000000), table(prime) {}

	void put(int key, int value) {
		int h = hash(key);
		auto it = search(key);
		if (it == table[h].end()) {
			table[h].push_back({key, value});
		} else {
			remove(h);
			table[h].push_back({key, value});
		}
	}

	void remove(int key) {
		int h = hash(key);
		auto it = search(key);
		if (it != table[h].end()) {
			table[h].erase(it);
		}
	}

	int get(int key) {
		int h = hash(key);
		auto it = search(key);
		if (it != table[h].end()) {
			return it->second;
		}
		return -1;
	}
};


/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */
