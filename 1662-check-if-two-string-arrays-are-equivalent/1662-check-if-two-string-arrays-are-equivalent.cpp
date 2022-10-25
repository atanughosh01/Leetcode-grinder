class Solution {
public:
    bool arrayStringsAreEqual(vector<string> &word1, vector<string> &word2) {
        int i = 0, j = 0; // word pointers
        int m = 0, n = 0; // char pointers
        int l1 = word1.size(), l2 = word2.size();
        while (i < l1 && j < l2) {            
            if (word1[i][m++] != word2[j][n++]) return false;
            if (m >= word1[i].size()) i++, m = 0;
            if (n >= word2[j].size()) j++, n = 0;
        }
        return (i == l1 && j == l2);
    }
};
