class Solution {
public:
	long long totalCost(vector<int> &costs, int k, int candidates) {
		long long res = 0;
		int i = 0, count = 0, j = costs.size() - 1;
		priority_queue<int, vector<int>, greater<int>> pq1, pq2;
		while (i < candidates) {
			pq1.push(costs[i++]);
		}
		if (candidates > costs.size() - candidates) {
			candidates = costs.size() - candidates;
		}
		while (count < candidates) {
			pq2.push(costs[j--]);
			count++;
		}
		while (k--) {
			if (!pq1.empty() && (pq2.empty() || (pq1.top() <= pq2.top()))) {
				res += pq1.top();
				pq1.pop();
				if (i <= j) {
					pq1.push(costs[i++]);
				}
			} else {
				res += pq2.top();
				pq2.pop();
				if (i <= j) {
					pq2.push(costs[j--]);
				}
			}
		}
		return res;
	}
};
