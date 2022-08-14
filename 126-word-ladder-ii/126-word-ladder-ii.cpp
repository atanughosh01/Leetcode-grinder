class Solution {
private:
    bool isAdj(string &a, string &b) {
        int diff = 0;
        for (int i = 0; i < a.size(); i++) {
            if (a[i] != b[i]) {
                if (++diff == 2) {
                    return false;
                }
            }
        }
        return diff == 1;
    }
    void collectPaths(vector<string> &words, vector<vector<int>> &prevs, vector<vector<string>> &res, int curr, vector<int> &currPath, int stop, int idx) {
        if (stop == curr) {
            vector<string> temp;
            for (int i = currPath.size() - 1; i >= 0; i--) {
                temp.push_back(words[currPath[i]]);
            }
            temp.push_back(words[idx]);
            res.push_back(temp);
            return;
        }
        for (int i = 0; i < prevs[curr].size(); i++) {
            currPath.push_back(prevs[curr][i]);
            collectPaths(words, prevs, res, prevs[curr][i], currPath, stop, idx);
            currPath.pop_back();
        }
    }
public:
    vector<vector<string>> findLadders(string &beginWord, string &endWord, vector<string> &wordList) {
        int idx = -1, root = -1;
        for (int i = 0; i < wordList.size(); i++) {
            if (wordList[i] == beginWord) {
                root = i;
            } else if (wordList[i] == endWord) {
                idx = i;
                break;
            }
        }
        if (idx == -1) {
            return {};
        }
        if (root == -1) {
            wordList.push_back(beginWord);
            root = wordList.size() - 1;
        }
        int n = wordList.size();
        vector<vector<int>> graph(n + 1);
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (isAdj(wordList[i], wordList[j])) {
                    graph[i].push_back(j);
                    graph[j].push_back(i);
                }
            }
        }
        vector<vector<int>> prevs(n);
        vector<int> steps(n, 0);
        queue<int> q;
        q.push(root);
        int level = 0;
        while (!q.empty()) {
            int sz = q.size();
            for (int i = 0; i < sz; i++) {
                int curr = q.front();
                q.pop();
                for (int adj : graph[curr]) {
                    if (steps[adj]) {
                        if (steps[adj] == level + 1) {
                            prevs[adj].push_back(curr);
                        }
                        continue;
                    }
                    steps[adj] = level + 1;
                    prevs[adj].push_back(curr);
                    q.push(adj);
                }
            }
            level++;
        }
        vector<vector<string>> res;
        vector<int> currPath;
        collectPaths(wordList, prevs, res, idx, currPath, root, idx);
        return res;
    }
};
