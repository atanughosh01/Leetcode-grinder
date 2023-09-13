class Solution_1 {
public:
	int candy(vector<int> &ratings) {
		int n = ratings.size();
		vector<int> count(n, 1);
		for (int i = 1; i < n; i++) {
			if (ratings[i] > ratings[i - 1]) {
				count[i] = count[i - 1] + 1;
			}
		}
		for (int i = n - 2; i >= 0; i--) {
			if (ratings[i] > ratings[i + 1]) {
				count[i] = max(count[i], count[i + 1] + 1);
			}
		}
		int total = 0;
		for (int c : count) total += c;
		return total;
	}
};


class Solution {
public:
	int candy(vector<int> &ratings) {
		int n = ratings.size();
		int candy = n, i = 1;
		while (i < n) {
			if (ratings[i] == ratings[i - 1]) {
				i++;
				continue;
			}
			int peak = 0;
			while (ratings[i] > ratings [i - 1]) {
				peak++;
				candy += peak;
				i++;
				if (i == n) return candy;
			}
			int valley = 0;
			while (i < n && (ratings[i] < ratings[i - 1])) {
				valley++;
				candy += valley;
				i++;
			}
			candy -= min(peak, valley);
		}
		return candy;
	}
};
