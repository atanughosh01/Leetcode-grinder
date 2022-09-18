class Solution_1 {
private:
    struct cmp {
        bool operator()(const pair<int, string> &a, const pair<int, string> &b) {
            if (a.first != b.first) {
                return a.first > b.first;
            }
            return a.second < b.second;
        }
    };
public:
    vector<string> topKFrequent(vector<string> &words, int k) {
        unordered_map<string, int> freq;
        for (string &word : words) freq[word]++;
        priority_queue<pair<int, string>, vector<pair<int, string>>, cmp> pq;   // Min Heap
        for (auto it = freq.begin(); it != freq.end(); ++it) {
            pq.push(make_pair(it->second, it->first));
            if (pq.size() > k) pq.pop();
        }
        vector<string> res;
        while (!pq.empty()) {
            res.insert(res.begin(), pq.top().second);
            pq.pop();
        }
        return res;
    }
};



// Crisper Code
class Solution {
public:
    vector<string> topKFrequent(vector<string> &words, int k) {
        unordered_map<string, int> umap;
        for (string s : words) umap[s]++;
        priority_queue<pair<int, string>> pq;   // Max Heap
        for (auto it : umap) {
            // minus sign used to build min heap
            pq.push({-it.second, it.first});
            if (pq.size() > k) pq.pop();
        }
        vector<string> res;
        while (k--) {
            res.push_back(pq.top().second);
            pq.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
