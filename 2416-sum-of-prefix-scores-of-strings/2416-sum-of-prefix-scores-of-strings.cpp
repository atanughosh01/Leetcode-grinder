class TrieNode {
public:
    char ch;
    TrieNode *children[26] = {nullptr};
    int prefix_cnt;
};

class Solution {
private:
    TrieNode *root = new TrieNode();
    void insertWord(string &word) {
        TrieNode *ptr = root;
        for (char &ch : word) {
            if (ptr->children[ch - 'a'] == nullptr) {
                ptr->children[ch - 'a'] = new TrieNode();
            }
            ptr = ptr->children[ch - 'a'];
            ptr->prefix_cnt++;
        }
    }
    int prefixCount(string &prefix) {
        int cnt = 0;
        TrieNode *tmp = root;
        for (char &ch : prefix) {
            int index = ch - 'a';
            if (tmp->children[index] == nullptr) break;
            tmp = tmp->children[index];
            cnt += tmp->prefix_cnt;
        }
        return cnt;
    }
public:
    vector<int> sumPrefixScores(vector<string> &words) {
        vector<int> res;
        for (string &word : words) insertWord(word);
        for (string &word : words) {
            int r = prefixCount(word);
            res.push_back(r);
        }
        return res;
    }
};
