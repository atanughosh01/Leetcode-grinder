class Solution_1 {
public:
    vector<int> answerQueries(vector<int> &nums, vector<int> &queries) {
        sort(nums.begin(), nums.end());
        for (int i = 1; i < nums.size(); i++) {
            nums[i] += nums[i - 1];
        }
        vector<int> ans;
        for (int query : queries) {
            int j = 0;
            for (; j < nums.size(); j++) {
                if (nums[j] > query) break;
            }
            ans.emplace_back(j);
        }
        return ans;
    }
};


class Solution {
public:
    vector<int> answerQueries(vector<int> &nums, vector<int> &queries) {
        sort(nums.begin(), nums.end());
        vector<int> res;
        for (int i = 0; i < queries.size(); i++) {
            int sum = 0, sz = 0;
            for (int j = 0; j < nums.size(); j++) {
                if (sum + nums[j] <= queries[i]) {
                    sz++;
                    sum += nums[j];
                } else {
                    break;
                }
            }
            res.push_back(sz);
        }
        return res;
    }
};
