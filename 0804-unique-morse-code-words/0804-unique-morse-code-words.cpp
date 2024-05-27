class Solution {
public:
    int uniqueMorseRepresentations(vector<string> &words) {
        vector<string> d = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."};
        unordered_set<string> s;
        for (string &w : words) {
            string code = "";
            for (char &c : w) {
                code += d[c - 'a'];
            }
            s.insert(code);
        }
        return s.size();
    }
};
