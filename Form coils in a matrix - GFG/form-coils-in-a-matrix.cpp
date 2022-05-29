// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends



// Problem : https://practice.geeksforgeeks.org/problems/form-coils-in-a-matrix4726/1



/*
    class Solution {
    public:
        vector<vector<int>> formCoils(int n) {
            vector<int> first, second;
            int m = 2;
            vector<vector<int>> mat(4*n, vector<int>(4*n));
            int cnt = 1;
            for (int i = 0; i < 4*n; i++) {
                for (int j = 0; j < 4 * n; j++) {
                    mat[i][j] = cnt++;
                }
            }
            int i = (4 * n) / 2;
            int j = i - 1;
            first.push_back(mat[i][j]);
            char indicate = 'u';
    
            // for first coil
            while (true) {
                // up
                bool flag = false;
                if (indicate == 'u') {
                    for (int k = 1; k <= m; k++) {
                        i--;
                        first.push_back(mat[i][j]);
                    }
                    indicate = 'r';
                }
                // right
                if (indicate == 'r') {
                    for (int k = 1; k <= m; k++) {
                        j++;
                        first.push_back(mat[i][j]);
                    }
                    indicate = 'd';
                    m += 2;
                }
                // down
                if (indicate = 'd') {
                    for (int k = 1; k <= m; k++) {
                        i++;
                        first.push_back(mat[i][j]);
                        if (mat[i][j] == (4 * n * 4 * n)) {
                            flag = true;
                            break;
                        }
                    }
                    indicate = 'l';
                }
                if (flag) break;
                // left
                if (indicate == 'l') {
                    for (int k = 1; k <= m; k++) {
                        j--;
                        first.push_back(mat[i][j]);
                    }
                    indicate = 'u';
                    m += 2;
                }
            }
            vector<vector<int>> ans;
            ans.push_back(first);
    
            // for second coil
            i = ((n * 4) / 2) - 1;
            j = (n * 4) / 2;
            second.push_back(mat[i][j]);
            m = 2;
            indicate = 'd';
            while (true) {
                bool flag = false;
                if (indicate == 'd') {
                    for (int k = 1; k <= m; k++) {
                        i++;
                        second.push_back(mat[i][j]);
                    }
                    indicate = 'l';
                }
                if (indicate == 'l') {
                    for (int k = 1; k <= m; k++) {
                        j--;
                        second.push_back(mat[i][j]);
                    }
                    indicate = 'u';
                    m += 2;
                }
                if (indicate == 'u') {
                    for (int k = 1; k <= m; k++) {
                        i--;
                        second.push_back(mat[i][j]);
                        if (mat[i][j] == 1) {
                            flag = true;
                            break;
                        }
                    }
                    indicate = 'r';
                }
                if (flag) break;
                if (indicate == 'r') {
                    for (int k = 1; k <= m; k++) {
                        j++;
                        second.push_back(mat[i][j]);
                    }
                    indicate = 'd';
                    m += 2;
                }
            }
            ans.push_back(second);
            return ans;
        }
    };
*/


class Solution {
private:
    int n = 0;
    void takeFirstRow(int &x, int &y, int &ex, int &ey, vector<int> &v) {
        for (int i = y; i < ey; i++) {
            v.push_back(4 * n * i + x + 1);
        }
        x++;
    }
    void takeLastRow(int &x, int &y, int &ex, int &ey, vector<int> &v) {
        for (int i = ey; i > y; i--) {
            v.push_back(n * 4 * (i - 1) + ex);
        }
        ex--;
    }
    void takeFirstColumn(int &x, int &y, int &ex, int &ey, vector<int> &v) {
        for (int i = ex; i > x; i--) {
            v.push_back(4 * n * (y) + i);
        }
        y++;
    }
    void takeLastColumn(int &x, int &y, int &ex, int &ey, vector<int> &v) {
        for (int i = x; i < ex; i++) {
            v.push_back((ey - 1) * 4 * n + i + 1);
        }

        ey--;
    }
public:
    vector<vector<int>> formCoils(int m) {
        n = m;
        vector<int> v1, v2;
        int x = 0, y = 0;
        int ex = 4 * n, ey = 4 * n;
        int k = 8 * n * n;

        while (x <= ex && y <= ey) {
            takeLastRow(x, y, ex, ey, v2);
            takeFirstRow(x, y, ex, ey, v1);

            takeFirstColumn(x, y, ex, ey, v2);
            takeLastColumn(x, y, ex, ey, v1);

            takeFirstRow(x, y, ex, ey, v2);
            takeLastRow(x, y, ex, ey, v1);

            takeLastColumn(x, y, ex, ey, v2);
            takeFirstColumn(x, y, ex, ey, v1);
        }
        v1.resize(8 * n * n);
        v2.resize(8 * n * n);
        reverse(v1.begin(), v1.end());
        reverse(v2.begin(), v2.end());
        return {v2, v1};
    }
};



// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        
        cin>>n;

        Solution ob;
        vector<vector<int>> ptr = ob.formCoils(n);
        
        for(auto it: ptr)
        {
            for(int i: it)
                cout<<i<<" ";
            cout<<endl;
        }
    }
    return 0;
}  // } Driver Code Ends