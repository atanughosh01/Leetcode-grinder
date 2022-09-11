class Solution {
public:
    int mostFrequentEven(vector<int> &nums) {
        int cnt = 0;
        map<int, int> mp;
        for (int &num : nums) {
            if (num % 2 == 0) {
                mp[num]++;
                cnt = max(cnt, mp[num]);
            }
        }
        for (auto &[key, value] : mp) {
            if (value == cnt) {
                return key;
            }
        }
        return -1;
    }
};
