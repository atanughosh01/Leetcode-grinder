// O(h*n) time
class Solution_1 {
public:
    int strStr(string &haystack, string &needle) {
        int h = haystack.size(), n = needle.size();
        for (int i = 0; i < h; i++) {
            if (haystack[i] == needle[0]) {
                for (int j = i; j < i + n; j++) {
                    if (haystack[j] != needle[j - i]) break;
                    if (j == i + n - 1) return i;
                }
            }
        }
        return -1;
    }
};


class Solution {
public:
    int strStr(string &haystack, string &needle) {
        int h = haystack.size(), n = needle.size();
        for (int i = 0; i < h; i++) {
            if (haystack.substr(i, n) == needle) {
                return i;
            }
        }
        return -1;
    }
};
