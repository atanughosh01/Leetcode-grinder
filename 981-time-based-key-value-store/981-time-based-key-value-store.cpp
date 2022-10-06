class TimeMapOne {
public:
    unordered_map<string, map<int, string>> hash;
    TimeMapOne() {}

    void set(string key, string value, int timestamp) {
        hash[key][timestamp] = value;
    }

    string get(string key, int timestamp) {
        if (!hash.count(key)) return "";
        auto it = hash[key].upper_bound(timestamp);
        if (it == hash[key].begin()) return "";
        return (--it)->second;
    }
};



class TimeMap {
private:
    unordered_map<string, vector<pair<string, int>>> hash;
    string searchVal(vector<pair<string, int>> &vec, const int &timestamp) {
        int low = 0;
        int high = vec.size() - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (vec[mid].second > timestamp) {
                high = mid - 1;
            } else if (vec[mid].second < timestamp) {
                low = mid + 1;
            } else {
                return vec[mid].first;
            }
        }
        return (high >= 0) ? vec[high].first : "";
    }
public:
    TimeMap() {}

    void set(string key, string value, int timestamp) {
        hash[key].push_back({value, timestamp});
    }

    string get(string key, int timestamp) {
        if (!hash.count(key)) return "";
        return searchVal(hash[key], timestamp);
    }
};



/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */
