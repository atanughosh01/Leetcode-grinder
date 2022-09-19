class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string> &paths) {
        unordered_map<string, vector<string>> files;
        vector<vector<string>> res;
        for (const string &path : paths) {
            int i = 0, j = 0;
            while (path[i] != ' ') i++;
            string dir = path.substr(0, i), file, content;
            while (i++ < path.size()) {
                j = i;
                while (path[i] != '(') i++;
                file = path.substr(j, i - j);
                j = i;
                // while (path[i] != ')') i++;
                while (path[i++] != ')');
                content = path.substr(j, i - j);
                files[content].push_back(dir + '/' + file);
            }
        }
        for (auto &[key, value] : files) {
            if (value.size() > 1) {
                res.push_back(move(value));
            }
        }
        return res;
    }
};
