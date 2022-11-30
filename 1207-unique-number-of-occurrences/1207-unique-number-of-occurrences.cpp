class Solution {
public:
    bool uniqueOccurrences(vector<int> &arr) {
        unordered_map<int, int> freq;
        unordered_set<int> freqSet;
        for (int &num : arr) freq[num]++;
        for (auto &[key, value] : freq) {
            freqSet.insert(value);
        }
        return freqSet.size() == freq.size();
    }
};
