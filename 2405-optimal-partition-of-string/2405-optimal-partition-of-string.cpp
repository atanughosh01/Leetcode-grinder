class Solution {
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
