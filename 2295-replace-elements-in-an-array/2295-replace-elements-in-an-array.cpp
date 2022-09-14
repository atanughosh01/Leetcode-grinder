class Solution_1 {
public:
    vector<int> arrayChange(vector<int> &nums, vector<vector<int>> &oprs) {
        unordered_map<int, int> mp;
        for (int i = 0; i < nums.size(); i++) {
            mp[nums[i]] = i;
        }
        for (vector<int> &opr : oprs) {
            nums[mp[opr[0]]] = opr[1];
            mp[opr[1]] = mp[opr[0]];
        }
        return nums;
    }
};



const int N = 1e6 + 2;
int arr[N]{0};

class Solution {
public:
    vector<int> arrayChange(vector<int> &nums, vector<vector<int>> &oprs) {
        for (int i = 0; i < nums.size(); i++) {
            arr[nums[i]] = i;
        }
        for (vector<int> &opr : oprs) {
            nums[arr[opr[0]]] = opr[1];
            arr[opr[1]] = arr[opr[0]];
        }
        return nums;
    }
};
