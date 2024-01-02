class Solution {
private:
	bool isPalindrome(string &str) {
		int l = 0, r = str.size() - 1;
		while (l < r) {
			if (str[l] != str[r]) {
				return false;
			}
			l++, r--;
		}
		return true;
	}
	void backTrack(vector<vector<string>> &ans, vector<string> &v, string s) {
		int n = s.size();
		if (n == 0) {
			ans.push_back(v);
			return;
		}
		for (int i = 0; i < n; i++) {
			string sub = s.substr(0, i + 1);
			string left = s.substr(i + 1);
			if (isPalindrome(sub)) {
				v.push_back(sub);
				backTrack(ans, v, left);
				v.pop_back();
			}
		}
	}
public:
	vector<vector<string>> partition(string &s) {
		vector<vector<string>> res;
		vector<string> list;
		backTrack(res, list, s);
		return res;
	}
};
