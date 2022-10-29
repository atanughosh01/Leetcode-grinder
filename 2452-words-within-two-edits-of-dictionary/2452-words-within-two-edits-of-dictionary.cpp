class Solution {
public:
	vector<string> twoEditWords(vector<string> &queries, vector<string> &dictionary) {
		vector<string> res;
		for (string &q : queries) {
			for (string &d : dictionary) {
				int cnt = 0, n = d.size();
				for (int i = 0; i < n; i++) {
					cnt += (d[i] != q[i]);
				}
				if (cnt <= 2) {
					res.push_back(q);
					break;
				}
			}
		}
		return res;
	}
};
