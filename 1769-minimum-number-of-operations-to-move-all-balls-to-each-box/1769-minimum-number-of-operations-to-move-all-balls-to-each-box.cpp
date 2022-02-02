// O(N^2) Solution

class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = (int)boxes.size();
        vector<int> arr;
        for(int i=0; i<n; i++){
            int res = 0;
            for(int j = 0; j < n; j++) {
                if(boxes[j] == '1') {
                    res += abs(i-j);
                }
            }
            arr.emplace_back(res);
        }
        return arr;
    }
};
