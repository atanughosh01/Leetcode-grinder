class Solution_1 {
public:
    int missingNumber(vector<int> &nums) {
        int sum = 0, n = nums.size();
        int total = n*(n + 1)/2;
        for (auto num : nums) {
            sum += num;
        }
        return total - sum;
    }
};


class Solution_2 {
public:
    int missingNumber(vector<int> &nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for(int i=0; i<n; i++) {
            if(nums[i] != i) {
                return nums[i]-1;
            }
        }
        return nums[n-1]+1;
    }
};


class Solution_3 {
public:
    int missingNumber(vector<int> &nums) {
        int sum = 0, n = nums.size();
        for (auto num : nums) {
            sum += num;
        }
        return (n*(n+1)/2) - sum;
    }
};


class Solution {
public:
    int missingNumber(vector<int> &nums) {
        int i = 0, res = nums.size();
        for (int num : nums) {
            res ^= num;
            res ^= i;
            i++;
        }
        return res;
    }
};
