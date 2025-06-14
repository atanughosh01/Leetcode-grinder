class Solution {
public:
	string longestCommonPrefix(vector<string> &str) {
		int n = str.size();
		if (n == 0) return "";
		string ans  = "";
		sort(begin(str), end(str));
		string a = str[0], b = str[n - 1];
		for (int i = 0; i < a.size(); i++) {
			if (a[i] == b[i]) ans += a[i];
			else break;
		}
		return ans;
	}
};
