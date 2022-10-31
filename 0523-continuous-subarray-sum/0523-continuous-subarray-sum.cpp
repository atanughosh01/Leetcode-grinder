class Solution_1 {
public:
    bool checkSubarraySum(vector<int> &nums, int k) {
        int n = nums.size();
        if (n == 1) return false;
        for (int i = 0; i < n; i++) {
            int sum = nums[i];
            for (int j = i + 1; j < n; j++) {
                sum += nums[j];
                if (sum % k == 0) return true;
            }
        }
        return false;
    }
};


class Solution_2 {
public:
    bool checkSubarraySum(vector<int> &nums, int k) {
        int n = nums.size();
        vector<int> pref(n, nums[0]);
        for (int i = 1; i < n; i++) {
            pref[i] = pref[i - 1] + nums[i];
            if (pref[i] % k == 0) return true;
        }
        for (int i = 2; i < n; i++) {
            for (int j = 0; j <= i - 2; j++) {
                if ((pref[i] - pref[j]) % k == 0) {
                    return true;
                }
            }
        }
        return false;
    }
};


class Solution_3 {
public:
    bool checkSubarraySum(vector<int> &nums, int k) {
        int n = nums.size(), sum = 0;
        if (n == 1) return false;
        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++) {
            sum += nums[i];
            int rem = sum % k;
            if (rem == 0 && i > 0) return true;
            if (mp.find(rem) != mp.end()) {
                if (i - mp[rem] > 1) return true;
            } else {
               mp[rem] = i;
            }
        }
        return false;
    }
};


class Solution_4 {
public:
    bool checkSubarraySum(vector<int> &nums, int k) {
        int n = nums.size();
        if (n == 1) return false;
        long long sum = 0, rem = 0;
        unordered_map<int, int> mp{{0, 0}};
        for (int i = 0; i < n; i++) {
            sum += nums[i];
            rem = sum % k;
            if (!mp.count(rem)) {
               mp[rem] = i + 1;
            } else if (mp[rem] < i) {
                return true;
            }
        }
        return false;
    }
};


class Solution_5 {
public:
    bool checkSubarraySum(vector<int> &nums, int k) {
        int n = nums.size();
        if (n == 1) return false;
        long long sum = 0, rem = 0;
        unordered_map<int, int> mp{{0, -1}};
        for (int i = 0; i < n; i++) {
            sum += nums[i];
            rem = sum % k;
            if (!mp.count(rem)) {
               mp[rem] = i;
            } else if (mp[rem] < i - 1) {
                return true;
            }
        }
        return false;
    }
};



class Solution {
public:
    bool checkSubarraySum(vector<int> &nums, int k) {
        int n = nums.size();
        if (n == 1) return false;
        long long sum = 0, rem = 0, pre = 0;
        unordered_set<int> modk;
        for (int i = 0; i < n; ++i) {
            sum += nums[i];
            rem = sum % k;
            if (modk.count(rem)) return true;
            modk.insert(pre);
            pre = rem;
        }
        return false;
    }
};
