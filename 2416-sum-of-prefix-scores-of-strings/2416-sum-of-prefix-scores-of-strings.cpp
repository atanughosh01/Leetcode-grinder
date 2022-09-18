class Node {
public:
    char ch;
    Node* children[26] = {nullptr};
    int prefix_cnt;
};

class Solution {
private:
    Node* root = new Node;
    int prefixCount(string &prefix) {
        Node* tmp = root;
        int cnt = 0;
        for (char &ch : prefix) {
            int index = ch - 'a';
            if (tmp->children[index] == nullptr) break;
            tmp = tmp->children[index];
            cnt += tmp->prefix_cnt;
        }
        return cnt;
    }
    void insertWord(string &word) {
        Node* ptr = root;
        for (char &ch : word) {
            if (ptr->children[ch - 'a'] == nullptr)
                ptr->children[ch - 'a'] = new Node();
            ptr = ptr->children[ch - 'a'];
            ptr->prefix_cnt++;
        }
    }
public:
    vector<int> sumPrefixScores(vector<string>& words) {
        vector<int> res;
        for (string &word : words) insertWord(word);
        for (string &word : words) {
            int r = prefixCount(word);
            res.push_back(r);
        }
        return res;
    }
};
