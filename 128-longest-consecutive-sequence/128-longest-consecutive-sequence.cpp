// TC = O(NlogN), SC = O(1)
class Solution_1 {
public:
    int longestConsecutive(vector<int> &nums) {
        int n = (int)(nums.size());
        if (n <= 1) return n;
        int max_len = 1, cur_len = 1;
        sort(nums.begin(), nums.end());
        for (int i = 1; i < n; i++) {
            if (nums[i] == nums[i - 1]) continue;
            if (nums[i] - nums[i - 1] == 1) cur_len++;
            else {
                max_len = max(max_len, cur_len);
                cur_len = 1;
            }
        }
        return max(max_len, cur_len);
    }
};



// TC = O(N), SC = O(N)
class Solution_2 {
public:
    int longestConsecutive(vector<int> &nums) {
        int n = (int)(nums.size());
        if (n <= 1) return n;
        unordered_map<int, int> mp;
        int max_len = 1;
        for (int &num : nums) mp[num] = 1;
        for (int &num : nums) {
            if (mp.find(num - 1) != mp.end()) {
                mp[num] = 0;
            }
        }
        for (int &num : nums) {
            if (mp[num] == 1) {
                int cur_len = 1;
                while (mp.find(num + cur_len) != mp.end()) {
                    cur_len++;
                }
                max_len = max(max_len, cur_len);
            }
        }
        return max_len;
    }
};



// TC = O(N), SC = O(N)
class Solution_3 {
public:
    int longestConsecutive(vector<int> &nums) {
        int n = (int)(nums.size());
        if (n <= 1) return n;
        unordered_set<int> st;
        int max_len = 1;
        for (int &num : nums) st.insert(num);
        for (int &num : nums) {
            if (st.find(num - 1) == st.end()) {
                int cur_num = num;
                int cur_len = 1;
                while (st.find(cur_num + 1) != st.end()) {
                    cur_num++;
                    cur_len++;
                }
                max_len = max(max_len, cur_len);
            }
        }
        return max_len;
    }
};



// TC = O(N), SC = O(N) but slightly more optimised
class Solution {
public:
    int longestConsecutive(vector<int> &nums) {
        int n = (int)(nums.size());
        if (n <= 1) return n;
        unordered_set<int> st;
        int max_len = 1;
        for (int &num : nums) st.insert(num);
        for (auto &itr : st) {
            if (st.find(itr - 1) == st.end()) {
                int cur_num = itr;
                int cur_len = 1;
                while (st.find(cur_num + 1) != st.end()) {
                    cur_num++;
                    cur_len++;
                }
                max_len = max(max_len, cur_len);
            }
        }
        return max_len;
    }
};
