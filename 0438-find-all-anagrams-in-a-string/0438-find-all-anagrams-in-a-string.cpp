// BruteForce TLE SOLUTION
class Solution_1 {
public:
	vector<int> findAnagrams(string &s, string &p) {
		int pn = p.size();
		int sn = s.size();
		sort(p.begin(), p.end());
		vector<int> idx;
		for (int i = 0; i + pn <= sn; i++) {
            string str = s.substr(i, pn);
			sort(str.begin(), str.end());
			if (str == p) {
				idx.emplace_back(i);
			}
		}
		return idx;
	}
};


// Optimal Solution
class Solution {
public:
	vector<int> findAnagrams(string &s, string &p) {
		int n = s.size(), m = p.size();
		vector<int> pv(26, 0), sv(26, 0), res;
		for (int l = 0; l < m; l++) {
			pv[p[l] - 'a']++;
        }
		int i = 0, j = 0;
		while (j < n) {
			sv[s[j] - 'a']++;
			if ((j - i + 1) < m) {
				j++;
			}
			else if (j - i + 1 == m) {
				if (pv == sv) {
					res.emplace_back(i);
                }
				sv[s[i] - 'a']--;
				i++, j++;
			}
		}
		return res;
	}
};
