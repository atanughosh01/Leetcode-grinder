class Solution_1 {
public:
    vector<int> countSmaller(vector<int> &nums) {
        int n = (int)(nums.size());
        vector<int> res(n, 0);
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (nums[j] < nums[i]) {
                    res[i]++;
                }
            }
        }
        return res;
    }
};



class Solution_2 {
private:
    void mergeSort(int start, int end, vector<pair<int, int>> &numPairs, vector<int> &indices, vector<pair<int, int>> &temp) {
        if (start >= end) return;
        int mid = start + (end - start) / 2;

        mergeSort(start, mid, numPairs, indices, temp);
        mergeSort(mid + 1, end, numPairs, indices, temp);

        int left = start, right = mid + 1;
        int idx = start, nRightLess = 0;

        while (left <= mid && right <= end) {
            if (numPairs[left] < numPairs[right]) {
                indices[numPairs[left].second] += nRightLess;
                temp[idx++] = numPairs[left++];
            } else if (numPairs[left] > numPairs[right]) {
                temp[idx++] = numPairs[right++];
                nRightLess++;
            } else {
                left++;
                right++;
            }
        }

        while (left <= mid) {
            indices[numPairs[left].second] += nRightLess;
            temp[idx++] = numPairs[left++];
        }

        while (right <= end) {
            temp[idx++] = numPairs[right++];
        }

        for (int i = start; i <= end; i++) {
            numPairs[i] = temp[i];
        }
    }

public:
    vector<int> countSmaller(vector<int> &nums) {
        int n = (int)(nums.size());
        vector<pair<int, int>> pairs, temp;
        vector<int> res(n, 0);

        for (int i = 0; i < n; i++) {
            pairs.push_back({nums[i], i});
            temp.push_back({nums[i], i});
        }

        mergeSort(0, n - 1, pairs, res, temp);
        return res;
    }
};



class Solution_3 {
public:
    // TIME COMPLEXITY:- O(N*LOGM),
    // N = NUMS.SIZE(), M = 2e4 + 5, BIT Update
    void update(int val, vector<int> &BIT) {
        while (val <= BIT.size()) {
            BIT[val]++;
            // next element (child) obtained by incrementing
            // the last set bit of the current index
            val += val & -val;
        }
    }

    // flip the last set bit of ind & -(ind),
    // BIT answer (get sum, parent to back)
    int answer(int val, vector<int> &BIT) {
        int ans = 0;
        while (val > 0) {
            // sum of frequency of elements smaller than 
            // already seen (loop is running back)
            ans += BIT[val];

            // previous element (parent) is obtained by
            // removing the last set bit from current index
            val -= (val & -val);
        }
        return ans;
    }

    vector<int> countSmaller(vector<int> &nums) {
        vector<int> ans(nums.size(), 0);
        
        // Binary Indexed Tree Array, 2*max_size+5 (safety)
        vector<int> BIT(20005, 0);

        // offset
        for (int i = 0; i < nums.size(); i++) {
            // Make all Numbers positive (for our problem
            // translation does not affect the smallest count)
            nums[i] += 10001;
        }

        // iterate from the end (in this way elements
        // to the right will be visited first)
        for (int i = nums.size() - 1; i >= 0; i--) {
            // get answer, nums[i]-1 (index here)
            // because we need strictly smaller
            ans[i] = answer(nums[i] - 1, BIT);
            update(nums[i], BIT);
        }
        return ans;
    }
};



class Solution {
private:
    int C[20002];
    int MAX = 20001, MIN = 10001;
    int sum(int x) {
        int ret = 0;
        while (x > 0) {
            ret += C[x];
            x -= x & (-x);
        }
        return ret;
    }
    void add(int x, int d) {
        while (x <= MAX) {
            C[x] += d;
            x += x & (-x);
        }
    }
public:
    vector<int> countSmaller(vector<int> &nums) {
        vector<int> ans;
        memset(C, 0, sizeof(C));
        int n = nums.size();
        for (int i = n - 1; i >= 0; i--) {
            nums[i] += MIN;
            int small = sum(nums[i] - 1);
            ans.push_back(small);
            add(nums[i], 1);
        }
        for (int i = 0; i < n / 2; i++) {
            swap(ans[i], ans[n - 1 - i]);
        }
        return ans;
    }
};
