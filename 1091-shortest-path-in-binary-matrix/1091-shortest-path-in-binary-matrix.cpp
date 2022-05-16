class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int row = grid.size(), col = grid[0].size();
        queue<pair<int, int>> q;
        if (grid[0][0] == 0) q.push({0, 0});
        grid[0][0] = 1;
        int shortestDist = 0;
        while (!q.empty()) {
            shortestDist++;
            int n = q.size();
            while (n--) {
                pair<int, int> p = q.front();
                int x = p.first, y = p.second;
                q.pop();
                if (x == row-1 && y == col-1) return shortestDist;
                int dx[] = {-1, 0, 1, 0, 1, 1, -1, -1};
                int dy[] = {0, -1, 0, 1, 1, -1, 1, -1};
                for (int i = 0; i < 8; i++) {
                    int a = x + dx[i];
                    int b = y + dy[i];
                    if (a >= 0 && a < row && b >= 0 && b < col && grid[a][b] == 0) {
                        q.push({a, b});
                        grid[a][b] = 1;
                    }
                }
            }
        }
        return -1;
    }
};
