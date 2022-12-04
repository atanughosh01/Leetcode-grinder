class Solution {
public:
	long long dividePlayers(vector<int> &skill) {
		sort(skill.begin(), skill.end());
		long long res = 0, pdt = 1;
		int n = skill.size(), s = skill[0] + skill[n - 1];
		for (int i = 0; i < n / 2; i++) {
			if (s != (skill[i] + skill[n - i - 1])) {
				return -1;
			}
			pdt = skill[i] * 1ll * skill[n - i - 1];
			res += pdt;
		}
		return res;
	}
};
