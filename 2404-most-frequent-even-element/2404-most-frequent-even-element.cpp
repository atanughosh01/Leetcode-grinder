// Two Pass | O(n) Time | O(n) Space | n = nums.length
class Solution_1 {
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


// One Pass | O(n) Time | O(n) Space | n = nums.length
class Solution {
public:
    int mostFrequentEven(vector<int> &nums) {
        unordered_map<int, int> mp;
        int val = INT_MAX, freq = 0;
        for (int num : nums) {
            if (num % 2 == 0) {
                mp[num]++;
                if (mp[num] > freq || (mp[num] == freq && num < val)) {
                    val = num;
                    freq = mp[num];
                }
            }
        }
        return freq ? val : -1;
    }
};
