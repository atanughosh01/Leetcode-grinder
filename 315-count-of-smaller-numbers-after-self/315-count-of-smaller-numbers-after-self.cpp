/*
    class Solution {
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
*/


class Solution {
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
