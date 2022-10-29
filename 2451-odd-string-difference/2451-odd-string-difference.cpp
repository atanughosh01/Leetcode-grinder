class Solution {
public:
	string oddString(vector<string> &words) {
		int m = words.size(), n = words[0].size();
		map<vector<int>, int> mp;
		vector<int> c;
		for (string &word : words) {
			vector<int> b;
			for (int j = 1; j < n; j++) {
				int d = word[j] - word[j - 1];
				b.push_back(d);
			}
			mp[b]++;
		}
		for (auto &[k, v] : mp) {
			if (v == 1) {
				c = k;
			}
		}
		for (string &word : words) {
			vector<int> b;
			for (int j = 1; j < n; j++) {
				int d = word[j] - word[j - 1];
				b.push_back(d);
			}
			if (b == c) return word;
		}
		return words[0];
	}
};
