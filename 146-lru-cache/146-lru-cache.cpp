class LRUCache {
private:
	list<int> cache;                                    // cache as doubly-linked-list
	unordered_map<int, int> keyVal;                     // hashmap for storing the value corresponding to a key
	unordered_map<int, list<int>::iterator> addrOfKey; // hashmap for storing the address corresponding to a key
	int cacheSize, cacheCapacity;

public:
	LRUCache(int capacity) {
		cacheCapacity = capacity;       		// reset the max capacity of the cache
		cacheSize = 0;                  		// reset the current size of cache
	}

	int get(int key) {
		if (keyVal.find(key) == keyVal.end()) {	// if no such key exists in the record
			return -1;
		}
		auto it = addrOfKey[key];       		// find the address of the key
		cache.erase(it);                		// delete that key from the cache
		addrOfKey.erase(key);           		// delete the address of that key also
		cache.push_front(key);          		// add that key at the beginning of cache bcz now it's MRU
		addrOfKey[key] = cache.begin();  		// store the new-address in the address-map
		return keyVal[key];						// returns the value against the given key
	}

	void put(int key, int value) {
		if (keyVal.find(key) != keyVal.end()) {
			auto it = addrOfKey[key];       	// find the address of the key
			cache.erase(it);                	// delete that key from the cache
			addrOfKey.erase(key);           	// delete the address of that key also
			keyVal.erase(key);					// delete the value stored against that key also
			cacheSize--;						// decrease the size of the cache
		}
		if (cacheSize == cacheCapacity) {		// if size of the cache reaches its maximum capacity
			int keyToBeErased = cache.back();	// find the key that is present at the LRU location
			addrOfKey.erase(keyToBeErased);     // delete the address of that key
			keyVal.erase(keyToBeErased);		// delete the value stored against that key also
			cache.pop_back();					// delete the LRU element from the LRU location also
			cacheSize--;						// decrease the size of the cache
		}
		cache.push_front(key);          		// add that key at the beginning of cache bcz now it's MRU
		addrOfKey[key] = cache.begin();  		// store the new-address in the address-map
		keyVal[key] = value;  					// store the new-value against the given key
		cacheSize++;							// increase the size of the cache
	}
};



/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
