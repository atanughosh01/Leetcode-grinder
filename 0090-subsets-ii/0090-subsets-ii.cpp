class Solution_1 {
public:
    vector<vector<int>> subsetsWithDup(vector<int> &nums) {
        vector<vector<int>> subs = {{}};
        set<vector<int>> st = {{}};
        for (int &num : nums) {
            int sz = subs.size();
            for (int i = 0; i < sz; i++) {
                vector<int> sub = subs[i];
                sub.push_back(num);
                subs.push_back(sub);
                sort(sub.begin(), sub.end());
                st.insert(sub);
            }
        }
        vector<vector<int>> res(st.begin(), st.end());
        return res;
    }
};



class Solution_2 {
public:
    vector<vector<int>> subsetsWithDup(vector<int> &nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> subs = {{}};
        set<vector<int>> st = {{}};
        for (int &num : nums) {
            int sz = subs.size();
            for (int i = 0; i < sz; i++) {
                vector<int> sub = subs[i];
                sub.push_back(num);
                subs.push_back(sub);
                st.insert(sub);
            }
        }
        vector<vector<int>> res(st.begin(), st.end());
        return res;
    }
};



class Solution_3 {
public:
    vector<vector<int>> subsetsWithDup(vector<int> &nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> subs = {{}};
        int j = -1;
        for (int i = 0; i < nums.size(); i++) {
            int sz = subs.size();
            if (i == 0 || nums[i] != nums[i-1]) j = 0;
            for (; j < sz; j++) {
                vector<int> sub = subs[j];
                sub.push_back(nums[i]);
                subs.push_back(sub);
            }
        }
        return subs;
    }
};



class Solution_4 {
public:
    vector<vector<int>> subsetsWithDup(vector<int> &nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> subs = {{}};
        for (int &num : nums) {
            int sz = subs.size();
            for (int i = 0; i < sz; i++) {
                vector<int> sub = subs[i];
                sub.push_back(num);
                if (find(subs.begin(), subs.end(), sub) == subs.end()) {
                    subs.push_back(sub);
                }
            }
        }
        return subs;
    }
};



class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int> &nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> subs = {{}};
        int sz = 0, startIdx = 0;
        for (int i = 0; i < nums.size(); i++) {
            startIdx = (i >= 1 && nums[i] == nums[i - 1]) ? sz : 0;
            sz = subs.size();
            for (int j = startIdx; j < sz; j++) {
                vector<int> sub = subs[j];
                sub.push_back(nums[i]);
                subs.push_back(sub);
            }
        }
        return subs;      
    }
};
