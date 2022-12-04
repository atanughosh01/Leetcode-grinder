class Solution_1 {
public:
	long long dividePlayers(vector<int> &skill) {
		sort(skill.begin(), skill.end());
		long long res = 0, sum = 0;
		int n = skill.size();
        sum = skill[0] + skill[n - 1];
		for (int i = 0; i < n / 2; i++) {
			if (sum != (skill[i] + skill[n - i - 1])) {
				return -1;
			}
			res += (skill[i] * 1ll * skill[n - i - 1]);
		}
		return res;
	}
};


class Solution {
public:
	long long dividePlayers(vector<int> &skill) {
		sort(skill.begin(), skill.end());
		long long res = 0, sum = 0;
		int n = skill.size(), l = 0, r = n - 1;
        sum = skill[0] + skill[n - 1];
		while (l <= r) {
			if (sum != skill[l] + skill[r]) {
				return -1;
			}
			res += (skill[l++] * 1ll * skill[r--]);
		}
		return res;
	}
};
