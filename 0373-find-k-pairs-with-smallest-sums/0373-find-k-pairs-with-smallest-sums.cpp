class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int> &nums1, vector<int> &nums2, int k) {
        priority_queue<pair<int, pair<int, int>>> pq;
        int i, j, n1 = nums1.size(), n2 = nums2.size();
        for (i = 0; i < n1; i++) {
            for (j = 0; j < n2; j++) {
                if (pq.size() < k) {
                    pq.push(make_pair(nums1[i] + nums2[j],
                                      make_pair(nums1[i], nums2[j])));

                } else {
                    if ((nums1[i] + nums2[j]) < pq.top().first) {
                        pq.pop();
                        pq.push(make_pair(nums1[i] + nums2[j],
                                          make_pair(nums1[i], nums2[j])));
                    } else
                        break;
                }
            }
        }
        vector<vector<int>> v;
        while (!pq.empty()) {
            v.push_back({pq.top().second.first, pq.top().second.second});
            pq.pop();
        }
        reverse(v.begin(), v.end());
        return v;
    }
};
