class Solution {
public:
    int maxEqualFreq(vector<int> &nums) {
        int n = nums.size(), res = 0;
        unordered_map<int, int> countMap, freqMap;
        for (int i = 0; i < n; i++) {
            countMap[nums[i]]++;
            int freq = countMap[nums[i]];
            freqMap[freq]++;
            int count = freqMap[freq] * freq;
            if (i < n - 1 && count == i + 1) {
                res = i + 2;
            } else if (count == i) {
                res = i + 1;
            }
        }
        return res;
    }
};
