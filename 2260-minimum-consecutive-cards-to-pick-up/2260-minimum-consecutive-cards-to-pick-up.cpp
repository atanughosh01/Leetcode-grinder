class Solution {
public:
    int minimumCardPickup(vector<int> &cards) {
        int res = INT_MAX;
        unordered_map<int, int> mp;
        for (int i = 0; i < cards.size(); i++){
            if (mp.find(cards[i]) != mp.end()) {
                res = min(res, i - mp[cards[i]] + 1);
            }
            mp[cards[i]] = i;
        }
        return (res == INT_MAX)? -1 : res;
    }
};
