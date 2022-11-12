class Solution_1 {
public:
    int distinctAverages(vector<int> &nums) {
        int l = 0, r = nums.size() - 1;
        unordered_set<double> st;
        sort(nums.begin(), nums.end());
        while (l < r) {
            double avg = (nums[l] + nums[r]) / 2.0;
            st.insert(avg);
            l++, r--;
        }
        return (int)(st.size());
    }
};


class Solution {
public:
    int distinctAverages(vector<int> &nums) {
        int l = 0, r = nums.size() - 1;
        unordered_set<int> st;
        sort(nums.begin(), nums.end());
        while (l < r) {
            int sum = nums[l++] + nums[r--];
            st.insert(sum);
        }
        return (int)(st.size());
    }
};
