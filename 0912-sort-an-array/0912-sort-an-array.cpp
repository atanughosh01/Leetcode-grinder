class Solution {
private:
    void merge(vector<int> &a, int start, int mid, int end) {
        int p = start, q = mid + 1, k = 0;
        vector<int> arr(end - start + 1);
        for (int i = start; i <= end; i++) {
            if (p > mid) arr[k++] = a[q++];
            else if (q > end) arr[k++] = a[p++];
            else if (a[p] < a[q]) arr[k++] = a[p++];
            else arr[k++] = a[q++];
        }
        for (int p = 0; p < k; p++) {
            a[start++] = arr[p];
        }
    }

    void mergeSort(vector<int> &a, int start, int end) {
        if (start < end) {
            int mid = start + (end - start) / 2;
            mergeSort(a, start, mid);
            mergeSort(a, mid + 1, end);
            merge(a, start, mid, end);
        }
    }
public:
    vector<int> sortArray(vector<int> &nums) {
        mergeSort(nums, 0, nums.size() - 1);
        return nums;
    }
};
