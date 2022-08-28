class Solution_1 {
public:
    string removeStars(string &s) {
        multiset<int> star, nonStar;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '*') star.insert(i);
            else nonStar.insert(i);
        }
        for (int i : star) {
            auto it = --(nonStar.lower_bound(i));
            nonStar.erase(it);
        }
        string ans = "";
        for (int i : nonStar) ans += s[i];
        return ans;
    }
};


class Solution_2 {
public:
    string removeStars(string &s) {
        int j = 0;
        for (char c : s) {
            if (c == '*') j--;
            else s[j++] = c;
        }
        return s.substr(0, j);
    }
};


class Solution {
public:
    string removeStars(string &s) {
        string ans = "";
        for (char c : s) {
            if (c == '*') ans.pop_back();
            else ans += c;
        }
        return ans;
    }
};
