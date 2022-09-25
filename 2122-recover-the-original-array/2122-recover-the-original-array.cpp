class Solution {
private:
    int search(vector<int> &nums, vector<bool> &visit, int l, int r, int target) {
        int idx = -1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] == target) {
                if (visit[mid]) l = mid + 1;
                else {
                    idx = mid;
                    r = mid - 1;
                }
            }
            else if (nums[mid] > target) r = mid - 1;
            else l = mid + 1;
        }
        return idx;
    }
public:
    vector<int> recoverArray(vector<int> &nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for (int i = 1; i < n; i++) {
            int k = (nums[i] - nums[0]) / 2;
            if (k <= 0 || nums[0] + 2 * k != nums[i]) continue;
            vector<bool> visited(n);
            vector<int> res;
            for (int j = 0; j < n; j++) {
                if (visited[j]) continue;
                int target = nums[j] + 2 * k;
                int index = search(nums, visited, j + 1, n - 1, target);
                if (index == -1) break;
                visited[index] = true;
                res.push_back(nums[j] + k);
            }
            if (res.size() == n / 2) return res;
        }
        return {};
    }
};
