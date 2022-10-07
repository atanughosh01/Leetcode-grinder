class Solution {
public:
	int maxSatisfaction(vector<int> &s) {
		sort(s.begin(), s.end());
		int n = s.size(), sum = 0;
		for (int i = n - 1; i > 0; i--) {
			s[i - 1] += s[i];
		}
		for (int &x : s) {
			sum += x * (x >= 0);
		}
		return sum;
	}
};
