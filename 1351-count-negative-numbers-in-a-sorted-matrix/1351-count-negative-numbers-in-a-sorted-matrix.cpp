// TC : O(m*n), SC : O(1)
class Solution_1 {
public:
    int countNegatives(vector<vector<int>> &grid) {
        int count = 0, n = grid[0].size();
        for (vector<int> &arr : grid) {
            for (int i = n - 1; i >= 0; i--) {
                if (arr[i] < 0)  count++;
                else break;
            }
        }
        return count;
    }
};



// TC : O(m*log(n)), SC : O(1)
class Solution {
private:
    int binarySearch(vector<int> &arr, int l, int r) {
        if (arr.size() == 1 && arr[0] < 0) {
            return -1;
        }
        if (arr.back() >= 0) {
            return arr.size() - 1;
        }
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (arr[mid] >= 0 && arr[mid + 1] < 0) {
                return mid;
            } else if (arr[mid] < 0 && arr[mid + 1] < 0) {
                r = mid - 1;    // binarySearch(arr, 0, mid - 1);
            } else {
                l = mid + 1;    // binarySearch(arr, mid + 1, r);
            }
        }
        return -1;
    }
public:
    int countNegatives(vector<vector<int>> &grid) {
        int count = 0, n = grid[0].size();
        for (vector<int> &vec : grid) {
            int nonNeg = binarySearch(vec, 0, vec.size()-1);
            count += (n - nonNeg - 1);
        }
        return count;
    }
};
