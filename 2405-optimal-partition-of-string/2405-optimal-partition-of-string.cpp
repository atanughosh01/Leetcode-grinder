// O(n) Time | O(n) Space | n = s.length
class Solution_1 {
public:
	int partitionString(string &s) {
		int cnt = 1;
		unordered_set<char> st;
		for (char &c : s) {
			if (st.find(c) == st.end()) {
				st.insert(c);
			} else {
				st.clear();
				cnt++;
				st.insert(c);
			}
		}
		return cnt;
	}
};



// O(n) Time | O(1) Space | n = s.length
class Solution {
public:
	int partitionString(string &s) {
		int pos[26]{0}, cnt = 0, lastIdx = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (pos[s[i] - 'a'] >= lastIdx) {
                cnt++;
                lastIdx = i + 1;
            }
            pos[s[i] - 'a'] = i + 1;
        }
        return cnt;
	}
};
