/*
    // B R U T E
    class Solution {
    public:
        vector<int> canSeePersonsCount(vector<int>& heights) {
            int n = (int)heights.size();
            vector<int> ans(n, 1);
            int currMax = 0;
            for(int i=0; i<n-1; ++i) {
                currMax = heights[i+1];
                for(int j=i+2; j<n; ++j) {
                    if(heights[j] > currMax and heights[i] > currMax) {
                        currMax = heights[j];
                        ans[i]++;
                    }
                }
            }
            ans[n-1] = 0;
            return ans;
        }
    };
*/

// Optimised
class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
        int n = (int)heights.size();
        vector<int> ans(n), stack;
        for (int i = 0; i < n; ++i) {
            while (!stack.empty() and heights[stack.back()] <= heights[i]) {
                ans[stack.back()]++;
                stack.pop_back();
            }
            if (!stack.empty()) {
                ans[stack.back()]++;
            }
            stack.push_back(i);
        }
        return ans;
    }
};
