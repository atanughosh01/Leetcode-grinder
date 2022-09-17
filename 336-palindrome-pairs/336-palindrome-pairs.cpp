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



// Optimal | O(n * m^2) Time | O(n) Space | n = words.length, m = avg value of words[i].length
class Solution {
private:
    bool isPalindrome(string &s) {
        int l = 0, r = s.size() - 1;
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

        // O(n*m) Time operation
        for (int i = 0; i < n; i++) {
            string rev = words[i];
            reverse(rev.begin(), rev.end());    // O(m) Time operation
            pos[rev] = i;
        }

        // O(n*m) Time operation
        if (pos.find("") != pos.end()) {
            for (int i = 0; i < n; i++) {
                if (pos[""] != i && isPalindrome(words[i])) {   // O(m) Time operation
                    res.push_back({i, pos[""]});
                }
            }
        }

        // O(n * m^2) Time operation
        for (int i = 0; i < n; i++) {
            int m = words[i].size();
            string left = "";
            string right = words[i];
            for (int j = 0; j < m; j++) {
                left.push_back(words[i][j]);
                right.erase(0, 1);              // constant time operation

                // for "llsss", "sll"
                // when j=2 left = "lls"; right="ss"; pos["lls"] does exist,
                // so if right is palindrome, the pair is palindrome
                // O(m) Time operation
                if (pos.find(left) != pos.end() && pos[left] != i && isPalindrome(right)) {
                    res.push_back({i, pos[left]});
                }

                // for "lls", "sssll"
                // when j=2 left = "ss"; right="sll"; pos["sll"] does exist,
                // so if left is palindrome, the pair is palindrome
                // O(m) Time operation
                if (pos.find(right) != pos.end() && pos[right] != i && isPalindrome(left)) {
                    res.push_back({pos[right], i});
                }
            }
        }
        return res;
    }
};
