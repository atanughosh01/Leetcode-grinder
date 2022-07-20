// T.L.E.
class Solution_1 {
private:
    bool isSubSequence(string s1, string s2) {
        int m = s1.size(), n = s2.size();
        int j = 0;
        for (int i = 0; i < n && j < m; i++) {
            if (s1[j] == s2[i]) {
                j++;
            }
        }
        return (j == m);
    }
public:
    int numMatchingSubseq(string str, vector<string> &words) {
        int res = 0;
        for (string &word : words) {
            if (isSubSequence(word, str)) {
                res++;
            }
        }
        return res;
    }
};



class Solution_2 {
public:
    int numMatchingSubseq(string str, vector<string> &words) {
        int res = 0;
        unordered_map<char, vector<int>> mp;
        for (int i = 0; i < str.size(); i++) {
            mp[str[i]].push_back(i);
        }
        for (int i = 0; i < words.size(); i++) {
            string curr = words[i];
            int latest = -1;
            for (int j = 0; j < curr.size(); j++) {
                auto it = upper_bound(mp[curr[j]].begin(), mp[curr[j]].end(), latest);
                if (it == mp[curr[j]].end()) break;
                latest = *it;
                if (j == curr.size() - 1) res++;
            }
        }
        return res;
    }
};



class Solution_3 {
public:
    int numMatchingSubseq(string str, vector<string> &words) {
        int res = 0;
        unordered_map<char, vector<int>> mp;
        for (int i = 0; i < str.size(); i++) {
            mp[str[i]].push_back(i);
        }
        for (string &word : words) {
            int latest = -1;
            bool found = true;
            for (char &c : word) {
                auto it = upper_bound(mp[c].begin(), mp[c].end(), latest);
                if (it == mp[c].end()) {
                    found = false;
                    break;
                }
                latest = *it;
            }
            if (found) res++;
        }
        return res;
    }
};



// COPIED faster solution, but couldn't properly understand
struct Node {
    const string &word;
    int index;
    Node(const string &word, int index) : word(word), index(index) {}
};

class Solution {
public:
    int numMatchingSubseq(string &s, vector<string>& words) {
        vector<Node> buckets[26];
        for (string &word : words) {
            char startingChar = word[0];
            buckets[startingChar-'a'].push_back(Node(word, 0));
        }
        int res = 0;
        for (char &c : s) {
            auto currBucket = buckets[c-'a'];
            buckets[c-'a'].clear();
            for (auto &node : currBucket) {
                node.index++;
                if (node.index == node.word.size()) {
                    res++;
                } else {
                    buckets[node.word[node.index]-'a'].push_back(move(node));
                }
            }
        }
        return res;
    }
};
