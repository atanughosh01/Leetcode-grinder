class Solution {
public:
    int maxProduct(vector<string> &words) {
        int best = 0, n = words.size();
        vector<int> bitsets(n);
        for (int i = 0; i < n; i++) {
            string word = words[i];
            int bitset = 0;
            for (char &c : word) {
                bitset |= (1 << (c - 'a'));
            }
            for (int j = 0; j < i; j++) {
                if ((bitsets[j] & bitset) == 0) {
                    int temp = (int)(word.size() * words[j].size());
                    best = max(best, temp);
                }
            }
            bitsets[i] = bitset;
        }
        return best;
    }
};
