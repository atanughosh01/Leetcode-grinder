/*
    class Solution {
    public:
        int maximumUniqueSubarray(vector<int> &nums) {
            int n = nums.size(), max_sum = INT_MIN;
            for (int i = 0; i < n; i++) {
                int sum = 0;
                unordered_map<int, int> mp;
                for (int j = i; j < n; j++) {
                    sum += nums[j];
                    mp[nums[j]]++;
                    if (mp[nums[j]] > 1) {
                        sum -= nums[j];
                        break;
                    }
                }
                max_sum = max(max_sum, sum);
            }
            return max_sum;
        }
    };
*/



/*
    class Solution {
    public:
        int maximumUniqueSubarray(vector<int> &nums) {
            int sum = 0, max_sum = INT_MIN;
            unordered_set<int> st;
            int l = 0, r = 0;
            while (r < nums.size()) {
                while (st.count(nums[r]) > 0) {
                    st.erase(nums[l]);
                    sum -= nums[l];
                    l++;
                }
                sum += nums[r];
                st.insert(nums[r++]);
                max_sum = max(max_sum, sum);
            }
            return max_sum;
        }
    };
*/



class Solution {
public:
    int maximumUniqueSubarray(vector<int> &nums) {
        int sum = 0, max_sum = INT_MIN;
        int m[100001] = {0};
        int l = 0, r = 0;
        while (r < nums.size()) {
            if (m[nums[r]]) {
                while ( m[nums[r]]) {
                    sum -= nums[l];
                    m[nums[l]]--;
                    l++;
                }
            }
            m[nums[r]]++;
            sum += nums[r];
            max_sum = max(max_sum, sum);
            r++;
        }
        return max_sum;
    }
};
