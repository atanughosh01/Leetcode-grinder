class Solution {
public:
    bool find132pattern(vector<int> &nums) {
        stack<int> st;
        int second = INT_MIN, n = nums.size();
        for (int i = n - 1; i >= 0; i--) {
            if (nums[i] < second) return true;
            while (st.size() > 0 && nums[i] > st.top()) {
                second = st.top();
                st.pop();
            }
            st.push(nums[i]);
        }
        return false;
    }
};
