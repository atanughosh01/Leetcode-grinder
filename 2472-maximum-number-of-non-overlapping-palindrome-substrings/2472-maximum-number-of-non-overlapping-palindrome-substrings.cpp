class Solution {
private:
	bool isValidChar(char &c) {
		return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
    }
public:
	int maxPalindromes(string &s, int k) {
		int res = 0, n = s.size();
		for (int i = 0; i < n; i++) {
			int l = i, r = i;
			while (l >= 0 && r < n && s[l] == s[r] && isValidChar(s[l]) && isValidChar(s[r])) {
				if (r - l + 1 >= k) {
					res++;
					s[l] = s[r] = '#';
					break;
				}
				l--, r++;
			}
			l = i, r = i + 1;
			while (l >= 0 && r < n && s[l] == s[r] && isValidChar(s[l]) && isValidChar(s[r])) {
				if (r - l + 1 >= k) {
					res++;
					s[l] = s[r] = '#';
					break;
				}
				l--, r++;
			}
		}
        return res;
	}
};
