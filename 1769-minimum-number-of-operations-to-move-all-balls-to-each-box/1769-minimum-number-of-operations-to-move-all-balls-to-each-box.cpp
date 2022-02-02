/*

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

*/


// O(N) Solution

class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = (int)boxes.size();
        vector<int> arr(n);

        int last_cost=0, sum=boxes[0]-'0';
        for(int i=1; i<n; i++){
            arr[i] += sum+last_cost;
            last_cost = arr[i];
            sum += (boxes[i]-'0');
        }

        last_cost=0, sum=boxes[n-1]-'0';
        for(int i=n-2; i>=0; i--){
            arr[i] += sum + last_cost;
            last_cost = (sum+last_cost);
            sum += (boxes[i]-'0');
        }

        return arr;
    }
};
