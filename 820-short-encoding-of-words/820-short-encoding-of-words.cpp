/*
    class Solution {
    public:
        int minimumLengthEncoding(vector<string> &words) {
            int sum = 0, n = words.size(), c = n;
            sum = 0;
            unordered_map<string, int> mp;
            for (int i = 0; i < n; i++) sum += words[i].length();
            for (int i = 0; i < n; i++) {
                mp[words[i]]++;
                for (int j = 0; j < n; j++) {
                    if (i != j && words[j].length() >= words[i].length()) {
                        int x = words[i].length(), y = words[j].length();
                        if (words[j].substr(y - x, x) == words[i]) {
                            c--;
                            sum -= x;
                            break;
                        }
                    }
                }
            }
            for (auto t : mp) {
                if (t.second > 1) {
                    sum += t.first.length();
                    c++;
                }
            }
            return sum + c;
        }
    };
*/



class Solution {
private:
    static bool comparator(string &first, string &second) {
        return first.size() > second.size();
    }
public:
    int minimumLengthEncoding(vector<string> &words) {
        unordered_map<string, int> mp;
        int ans = 0;
        sort(words.begin(), words.end(), comparator);
        for (int i = 0; i < words.size(); i++) {
            mp[words[i]]++;
        }
        for (int i = 0; i < words.size(); i++) {
            int k = words[i].size();
            if (mp[words[i]] > 0) {
                ans += (k + 1);
            }
            for (int j = k - 1; j >= 0; j--) {
                string s = words[i].substr(j, k - j);
                mp[s] = 0;
            }
        }
        return ans;
    }
};
