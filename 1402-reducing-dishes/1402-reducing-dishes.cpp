class Solution {
public:
	int maxSatisfaction(vector<int> &s) {
		sort(s.begin(), s.end());
		int n = s.size(), sum = 0;
		for (int i = n - 1; i > 0; i--) {
			s[i - 1] += s[i];
		}
		for (int i = 0; i < n; i++) {
			if (s[i] >= 0)
				sum += s[i];
		}
		return sum;
	}
};
