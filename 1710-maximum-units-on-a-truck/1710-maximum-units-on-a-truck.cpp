class Solution {
public:
    int maximumUnits(vector<vector<int>> &boxes, int truckSize) {
        int res = 0, sizeBucket[1001] = {};
        int maxBucket = INT_MIN, minBucket = INT_MAX;
        for (auto &boxType: boxes) {
            maxBucket = max(maxBucket, boxType[1]);
            minBucket = min(minBucket, boxType[1]);
            sizeBucket[boxType[1]] += boxType[0];
        }
        for (int i = maxBucket; i >= minBucket; i--) {
            int size = sizeBucket[i];
            if (!size) continue;
            int currBatch = min(size, truckSize);
            truckSize -= currBatch;
            res += currBatch * i;
            if (!truckSize) break;
        }
        return res;
    }
};
