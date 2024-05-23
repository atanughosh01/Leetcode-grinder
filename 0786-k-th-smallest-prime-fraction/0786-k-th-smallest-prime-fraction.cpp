class Solution {
public:
	vector<int> kthSmallestPrimeFraction(vector<int> &arr, int k) {
		priority_queue<pair<double, pair<int, int>>> pq;
		for (int i = 0; i < arr.size(); i++) {
			pq.push({ -1.0 * arr[i] / arr.back(), {i, arr.size() - 1}});
		}
		while (--k > 0) {
			pair<int, int> cur = pq.top().second;
			pq.pop();
			cur.second--;
			pq.push({ -1.0 * arr[cur.first] / arr[cur.second], {cur.first, cur.second}});
		}
		return {arr[pq.top().second.first], arr[pq.top().second.second]};
	}
};
