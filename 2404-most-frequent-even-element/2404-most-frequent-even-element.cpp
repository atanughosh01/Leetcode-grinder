class Solution {
public:
    int mostFrequentEven(vector<int> &nums) {
        map<int, int> mp;
        for (int &num : nums) {
            if (num % 2==0) {
                mp[num]++;
            }
        }
        int res = 0, cnt = 0;
        for (auto it = mp.begin(); it != mp.end(); it++) {
            int val = (it->second);
            cnt = max(cnt, val);
        }
        for (auto it = mp.begin(); it != mp.end(); it++) {
            if (it->second == cnt) {
                return it->first;
            }
        }
        return -1;
    }
};
