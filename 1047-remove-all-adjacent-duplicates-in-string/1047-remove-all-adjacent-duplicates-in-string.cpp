class Solution {
public:
    string removeDuplicates(string &s) {
        string res = "";
        for (char &c : s) {
            if (!res.empty() && c == res.back()) {
                res.pop_back();
            } else {
                res.push_back(c);
            }
        }
        return res;
    }
};
