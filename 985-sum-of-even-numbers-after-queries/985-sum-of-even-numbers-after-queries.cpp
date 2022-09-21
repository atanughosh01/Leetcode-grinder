// O(n * m) Time | O(1) Space | n = nums.length, m = queries.length
class Solution_1 {
public:
    vector<int> sumEvenAfterQueries(vector<int> &nums, vector<vector<int>> &queries) {
        vector<int> res;
        for (vector<int> &query : queries) {
            nums[query[1]] += query[0];
            int sum = 0;
            for (int &num : nums) {
                if (num % 2 == 0) {
                    sum += num;
                }
            }
            res.push_back(sum);
        }
        return res;
    }
};


// O(n) + O(m) Time | O(1) Space | n = nums.length, m = queries.length
class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int> &nums, vector<vector<int>> &queries) {
        vector<int> res;
        int sum = 0;
        for (int &num : nums) {
            if (num % 2 == 0) {
                sum += num;
            }
        }
        for (vector<int> &query : queries) {
            if (nums[query[1]] % 2 == 0) sum -= nums[query[1]];
            nums[query[1]] += query[0];
            if (nums[query[1]] % 2 == 0) sum += nums[query[1]];
            res.push_back(sum);
        }
        return res;
    }
};
