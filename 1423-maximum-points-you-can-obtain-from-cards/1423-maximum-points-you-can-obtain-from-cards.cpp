/*
    class Solution {
    private:
        int sumOfWindow(vector<int> &arr, int startIdx, int windowSize) {
            int ans = 0;
            for (int i = startIdx; i < startIdx + windowSize; i++) {
                ans += arr[i];
            }
            return ans;
        }
    public:
        int maxScore(vector<int> &cardPoints, int k) {
            int n = (int)(cardPoints.size()), ans = INT_MIN;
            int total_pts = accumulate(cardPoints.begin(), cardPoints.end(), 0);
            for (int i = 0; i <= k; i++) {
                int sumOfRest = total_pts - sumOfWindow(cardPoints, i, n - k);
                ans = max(ans, sumOfRest);
            }
            return ans;
        }
    };
*/


/*
    class Solution {
    public:
        int maxScore(vector<int> &cardPoints, int k) {
            int n = (int)(cardPoints.size()), ans = INT_MIN;
            vector<int> preSumFromStart(n+1, 0), preSumFromBack(n+1, 0);
            for (int i = 0; i < n; i++) {
                preSumFromStart[i + 1] = preSumFromStart[i] + cardPoints[i];
            }
            for (int i = n - 1; i >= 0; i--) {
                preSumFromBack[i] = preSumFromBack[i + 1] + cardPoints[i];
            }
            reverse(preSumFromBack.begin(), preSumFromBack.end());
            for (int i = 0; i <= k; i++) {
                ans = max(ans, (preSumFromStart[i] + preSumFromBack[k - i]));
            }
            return ans;
        }
    };
*/


class Solution {
public:
    int maxScore(vector<int> &cardPoints, int k) {
        int n = (int)(cardPoints.size());
        int l = 0, r  = n - k;
        int total_pts = accumulate(cardPoints.begin() + r, cardPoints.end(), 0);
        int ans = total_pts;
        while (r < n) {
            total_pts += (cardPoints[l] - cardPoints[r]);
            ans = max(ans, total_pts);
            l++, r++;
        }
        return ans;
    }
};
