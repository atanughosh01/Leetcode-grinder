// O(n * log(n)) Time | O(1) Time | n = s.length
class Solution_1 {
public:
    string frequencySort(string &s) {
        int freq[128]{0};
        for (const char &c : s) freq[c]++;
        sort(s.begin(), s.end(), [&](const char &a, const char &b) {
            return freq[a] == freq[b] ? a < b : freq[a] > freq[b];
        });
        return s;
    }
};


// O(2 * n) => O(n) Time | O(n*n + n) Space => O(n^2) | n = s.length
class Solution {
public:
	string frequencySort(string &s) {
		int n = s.size();
		unordered_map<char, int> freq;
		vector<string> bucket(n + 1, "");
		string res;
		for (char &c : s) freq[c]++;        // max size = 128 | O(128) Space => Constant Space && O(n) Time
		for (auto &it : freq) {             // O(128) Time => Constant Time
			char c = it.first;
			int cnt = it.second;
			bucket[cnt] += string(cnt, c);  // O(n * n) Space => O(n^2) Space
		}
		for (int i = n; i >= 0; i--) {      // O(n) Time
			res += bucket[i];               // Total O(n) Space
		}
		return res;
	}
};