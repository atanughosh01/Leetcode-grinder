class Solution {
private:
	int dfs(vector<string> &ws, vector<int> &cnt, vector<int> &score, int i) {
		if (i >= ws.size()) {
			return 0;
		}
		int skipGain = dfs(ws, cnt, score, i + 1);
		int gain = 0, formed = 1;
		vector<int> cnt1(cnt.begin(), cnt.end());
		for (char &c : ws[i]) {
			if (--cnt1[c - 'a'] < 0) {
				formed = 0;
			}
			gain += score[c - 'a'];
		}
		return max(skipGain, formed ? gain + dfs(ws, cnt1, score, i + 1) : 0);
	}
public:
	int maxScoreWords(vector<string> &words, vector<char> &letters, vector<int> &score) {
		vector<int> cnt(26);
		for (char &ch : letters) {
			++cnt[ch - 'a'];
		}
		return dfs(words, cnt, score, 0);
	}
};
