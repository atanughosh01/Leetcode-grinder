class Solution_1 {
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


class Solution {
public:
	vector<vector<string>> findDuplicate(vector<string> &paths) {
		vector<vector<string>> res;
		unordered_map<string, vector<string>> contMap;
		for (const string &path : paths) {
			int i = 0;
			while (path[i] != ' ') i++;
			string pStr = path.substr(0, i);
			for (int j = i + 1, k = 0; i < path.size(); i++)
				if (path[i] == '(') k = i + 1;
				else if (path[i] == ')') {
					string pathFile = pStr + '/' + path.substr(j, k - j - 1);
					string cont = path.substr(k, i - k);
					if (contMap.find(cont) == contMap.end()) {
						contMap[cont] = {};
					}
					contMap[cont].push_back(pathFile);
					j = i + 2;
				}
		}
		for (auto &[key, value] : contMap) {
			if (value.size() > 1) {
				res.push_back(value);
			}
		}
		return res;
	}
};
