// Bruteforce | O(n*n*m) Time | O(n) Space | n = words.length
class Solution_1 {
private:
    bool isPalindrome(string &s) {
        int l = 0, r = s.size()-1;
        while (l < r) {
            if (s[l++] != s[r--]) {
                return false;
            }
        }
        return true;
    }
public:
    vector<vector<int>> palindromePairs(vector<string> &words) {
        int n = words.size();
        vector<vector<int>> res;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                string concat = words[i] + words[j];
                if (j != i &&isPalindrome(concat)) {
                    res.push_back({i, j});
                }
            }
        }
        return res;
    }
};



// Optimal | O(n*m*m) Time | O(n) Space | n = words.length, m = words[i].length
class Solution_2 {
private:
    bool isPalindrome(string &s) {
        int l = 0, r = s.size()-1;
        while (l < r) {
            if (s[l++] != s[r--]) {
                return false;
            }
        }
        return true;
    }
public:
    vector<vector<int>> palindromePairs(vector<string> &words) {
        int n = words.size();

        vector<vector<int>> res;
        unordered_map<string, int> pos;

        // O(n*m) Time
        for (int i = 0; i < n; i++) {
            string rev = words[i];
            reverse(rev.begin(), rev.end());
            pos[rev] = i;
        }

        // O(n*m) Time
        if (pos.find("") != pos.end()) {
            for (int i = 0; i < n; i++) {
                if (pos[""] != i && isPalindrome(words[i])) {
                    res.push_back({pos[""], i});
                }
            }
        }

        // O(n*m*m) Time
        for (int i = 0; i < n; i++) {
            int m = words[i].size();
            for (int j = 0; j < m; j++) {
                string left = words[i].substr(0, j);
                string right = words[i].substr(j, m - j);

                // for "llsss", "sll"
                // when j=2 left = "lls"; right="ss"; m["lls"] is exists,
                // so if right is palindrome, the pair is palindrome
                if (pos.find(left) != pos.end() && isPalindrome(right) && pos[left] != i) {
                    res.push_back({i, pos[left]});
                }

                // for "lls", "sssll"
                // when j=2 left = "ss";right="sll"; m["lls"] is exists,
                // so if left is palindrome, the pair is palindrome
                if (pos.find(right) != pos.end() && isPalindrome(left) && pos[right] != i) {
                    res.push_back({pos[right], i});
                }
            }
        }

        return res;
    }
};




class TrieNode {
public:
    TrieNode() {}
    TrieNode *next[26]{};
    int index = -1;
    vector<int> palindromeIndices;
};

class Solution {
private:
    TrieNode root;
    void add(string &s, int i) {
        auto node = &root;
        for (int j = s.size() - 1; j >= 0; --j) {
            if (isPalindrome(s, 0, j)) node->palindromeIndices.push_back(i);
            int c = s[j] - 'a';
            if (!node->next[c]) node->next[c] = new TrieNode();
            node = node->next[c];
        }
        node->index = i;
        node->palindromeIndices.push_back(i);
    }
    bool isPalindrome(string &s, int i, int j) {
        while (i < j && s[i] == s[j]) ++i, --j;
        return i >= j;
    }
public:
    vector<vector<int>> palindromePairs(vector<string> &words) {
        int n = words.size();
        for (int i = 0; i < n; i++) add(words[i], i);
        vector<vector<int>> res;
        for (int i = 0; i < n; ++i) {
            int m = words[i].size();
            auto node = &root;
            for (int j = 0; j < m && node; ++j) {
                if (node->index != -1 && node->index != i && isPalindrome(words[i], j, m - 1)) {
                    res.push_back({i, node->index});
                }
                node = node->next[words[i][j] - 'a'];
            }
            if (!node) continue;
            for (int j : node->palindromeIndices) {
                if (i != j) res.push_back({i, j});
            }
        }
        return res;
    }
};
