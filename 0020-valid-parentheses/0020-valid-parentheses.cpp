class Solution {
public:
	bool isValid(string x) {
		stack<int> s;
		for (char c : x) {
			if (!s.empty()) {
				if ((s.top() == '(' && c == ')') || (s.top() == '{' && c == '}') || (s.top() == '[' && c == ']')) {
					s.pop();
				} else {
					s.push(c);
				}
			} else {
				s.push(c);
			}
		}
		return s.empty();
	}
};
