/*
    class Solution {
    public:
        bool isValid(string s) {
            stack<char> st;
            for(auto i:s) {
                if(i=='(' or i=='{' or i=='[')
                    st.push(i);
                else {
                    if(st.empty() or (st.top()=='(' and i!=')') or (st.top()=='{' and i!='}') or (st.top()=='[' and i!=']'))
                        return false;
                    st.pop();
                }
            }
            return st.empty();
        }
    };
*/


class Solution {
public:
	bool isValid(string x) {
		int i = 0;
		stack<int> s;
		while (i < x.size()) {
			if (!s.empty()) {
				if ((s.top() == '(' && x[i] == ')') || (s.top() == '{' && x[i] == '}') || (s.top() == '[' && x[i] == ']')) {
					s.pop();
				}
				else {
					s.push(x[i]);
				}
			}
			else {
				s.push(x[i]);
			}
			i++;
		}
		return s.empty() ? true : false;
	}
};
