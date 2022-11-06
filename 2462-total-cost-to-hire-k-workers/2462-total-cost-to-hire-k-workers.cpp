class Solution_1 {
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



class Solution {
public:
	long long totalCost(vector<int> &costs, int k, int candidates) {
		long long ans = 0;
		int count = 0, i = 0, j = costs.size() - 1;
		priority_queue<int, vector<int>, greater<int>> pq1, pq2;
		while (count < k) {
			while (pq1.size() < candidates && i <= j) pq1.push(costs[i++]);
			while (pq2.size() < candidates && i <= j) pq2.push(costs[j--]);
			int a = pq1.empty() ? INT_MAX : pq1.top();
			int b = pq2.empty() ? INT_MAX : pq2.top();
			if (a <= b) {
				ans += a;
				pq1.pop();
			} else {
				ans += b;
				pq2.pop();
			}
			count++;
		}
		return ans;
	}
};
