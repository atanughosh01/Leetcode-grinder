// Bruteforce | O(n*n) time | O(1) space | n = prop.length
class Solution_1 {
public:
    int numberOfWeakCharacters(vector<vector<int>> &prop) {
        int cnt = 0, n = prop.size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (prop[i][0] < prop[j][0] && prop[i][1] < prop[j][1]) {
                    cnt++;
                    break;
                }
            }
        }
        return cnt;
    }
};



// Optimal | O(n * log(n)) time | O(1) space | n = prop.length
class Solution_2 {
public:
    int numberOfWeakCharacters(vector<vector<int>> &prop) {
        int cnt = 0, maxSoFar = INT_MIN;
        sort(prop.begin(), prop.end(), [](const vector<int> &a, const vector<int> &b) {
            return (a[0] == b[0]) ? (a[1] > b[1]) : (a[0] < b[0]);  // normal sorting
        });
        for (int i = prop.size() - 1; i >= 0; i--) {                // backward traversal
            if (prop[i][1] < maxSoFar) cnt++;
            maxSoFar = max(maxSoFar, prop[i][1]);
        }
        return cnt;
    }
};



// Optimal | O(n * log(n)) time | O(1) space | n = prop.length
class Solution_3 {
public:
    int numberOfWeakCharacters(vector<vector<int>> &prop) {
        int cnt = 0, maxSoFar = INT_MIN;
        sort(prop.begin(), prop.end(), [](const vector<int> &a, const vector<int> &b) {
            return (a[0] == b[0]) ? (a[1] < b[1]) : (a[0] > b[0]);  // reverse sorting
        });
        for (const vector<int> &p : prop) {                         // forward traversal
            if (p[1] < maxSoFar) cnt++;
            maxSoFar = max(maxSoFar, p[1]);
        }
        return cnt;
    }
};



// Most Optimal | O(n) time | Some will say O(1) space, but I say O(n) space | n = prop.length
class Solution {
public:
    int numberOfWeakCharacters(vector<vector<int>> &prop) {
        const int N = 1e5;
        int cnt = 0, maxArr[N+2]{0};
        for (const vector<int> &p : prop) {
            maxArr[p[0]] = max(maxArr[p[0]], p[1]);
        }
        for (int i = N; i > 0; i--) {
            maxArr[i - 1] = max(maxArr[i - 1], maxArr[i]);
        }
        for (const vector<int> &p : prop) {
            if (maxArr[p[0] + 1] > p[1]) {
                cnt++;
            }
        }
        return cnt;
    }
};
