class Solution {
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
