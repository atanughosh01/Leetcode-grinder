typedef long long ll;


// Bruteforce | O(n^4) time | O(n) space
class Solution_1 {
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target) {
        int n = nums.size();
        set<vector<int>> st;
        sort(nums.begin(), nums.end());
        for (int i =0; i < n - 3; i++) {
            for (int j = i + 1; j < n - 2; j++) {
                for (int k = j + 1; k < n - 1; k++) {
                    for (int t = k + 1; t < n; t++) {
                        if ((ll)nums[i] + nums[j] + nums[k] + nums[t] == (ll)target) {
                            vector<int> quad = {nums[i], nums[j], nums[k], nums[t]};
                            st.insert(quad);
                        }
                    }
                }
            }
        }
        vector<vector<int>> res(st.begin(), st.end());
        return res;
    }
};


// Bruteforce | O(n^4) time | O(1) space
class Solution_2 {
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target) {
        int n = nums.size();
        set<vector<int>> st;
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        for (int i =0; i < n - 3; i++) {
            for (int j = i + 1; j < n - 2; j++) {
                for (int k = j + 1; k < n - 1; k++) {
                    for (int t = k + 1; t < n; t++) {
                        if ((ll)nums[i] + nums[j] + nums[k] + nums[t] == (ll)target) {
                            vector<int> quad = {nums[i], nums[j], nums[k], nums[t]};
                            res.push_back(quad);
                        }
                        while (t < n - 1 && nums[t] == nums[t + 1]) t++;
                    }
                    while (k < n - 1 && nums[k] == nums[k + 1]) k++;
                }
                while (j < n - 1 && nums[j] == nums[j + 1]) j++;
            }
            while (i < n - 1 && nums[i] == nums[i + 1]) i++;
        }
        return res;
    }
};



// Optimal | O(n^3 * log(n)) time | O(1) space
class Solution_3 {
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target) {
        int n = nums.size();
        set<vector<int>> st;
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n - 3; i++) {
            for (int j = i + 1; j < n - 2; j++) {
                for (int k = j + 1; k < n - 1; k++) {
                    ll sumOfThree = (ll)nums[i] + (ll)nums[j] + (ll)nums[k];
                    int fourthNum = target - sumOfThree;
                    if (binary_search(nums.begin() + k + 1, nums.end(), fourthNum)) {
                        vector<int> quad = {nums[i], nums[j], nums[k], fourthNum};
                        res.push_back(quad);
                    }
                    while (k < n - 1 && nums[k] == nums[k + 1]) k++;
                }
                while (j < n - 1 && nums[j] == nums[j + 1]) j++;
            }
            while (i < n - 1 && nums[i] == nums[i + 1]) i++;
        }
        return res;
    }
};



// Most Optimal | O(n^3) time | O(1) space
class Solution_4 {
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target) {
        int n = nums.size();
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n - 3; i++) {
            for (int j = i + 1; j < n - 2; j++) {
                int l = j + 1, r = n - 1;
                ll remSum = (ll)target - (ll)nums[i] - (ll)nums[j];
                while (l < r) {
                    ll sumOfLastTwo = nums[l] + nums[r];
                    if (sumOfLastTwo < remSum) l++;
                    else if (sumOfLastTwo > remSum) r--;
                    else {
                        vector<int> quad = {nums[i], nums[j], nums[l], nums[r]};
                        res.push_back(quad);
                        while (l < r && nums[l] == quad[2]) l++;
                        while (l < r && nums[r] == quad[3]) r--;
                    }
                }
                while (j < n - 1 && nums[j] == nums[j + 1]) j++;
            }
            while (i < n - 1 && nums[i] == nums[i + 1]) i++;
        }
        return res;
    }
};




// Magic Solution | Using KSum Concept
class Solution {
private:
    const int K = 4;
    void search(const vector<int> &arr, int idx, const int k, int tar, vector<int> &q, vector<vector<int>> &ans) {
        int sz = arr.size();
        if (k == 2) {
            int l = idx, r = sz - 1;
            while (l < r) {
                ll sum = arr[l] + arr[r];
                if (sum > tar) r--;
                else if (sum < tar) l++;
                else {
                    q.push_back(arr[l++]);
                    q.push_back(arr[r--]);
                    ans.push_back(q);
                    q.pop_back();
                    q.pop_back();
                    while (l < r && arr[l] == arr[l - 1]) l++;
                    while (l < r && arr[r] == arr[r + 1]) r--;
                }
            }
        } else {
            for (int j = idx; j <= sz - k; j++) {
                ll sum = 0;
                for (int i = j; i < k + j; i++) {
                    sum += arr[i];
                }
                if (sum > tar) break;
                sum = arr[j];
                for (int i = 0; i < k - 1; i++) {
                    sum += arr[sz - i - 1];
                }
                if (sum < tar) continue;
                q.push_back(arr[j]);
                search(arr, j + 1, k - 1, tar - arr[j], q, ans);
                q.pop_back();
                while (j <= sz - k && arr[j] == arr[j + 1]) j++;
            }
        }
    }
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target) {
        sort(nums.begin(), nums.end());
        vector<int> quad;
        vector<vector<int>> res;
        search(nums, 0, K, target, quad, res);
        return res;
    }
};
