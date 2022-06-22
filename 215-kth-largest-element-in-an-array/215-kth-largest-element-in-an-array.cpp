/*
    class Solution {
    public:
        int findKthLargest(vector<int> &nums, int k) {
            sort(nums.begin(), nums.end());
            return nums[nums.size()-k];
        }
    };
*/


/*
    class Solution {
    public:
        int findKthLargest(vector<int> &nums, int k) {
            sort(nums.begin(), nums.end(), greater<int>());
            return nums[k-1];
        }
    };
*/


class Solution {
public:
    int findKthLargest(vector<int> &nums, int k) {
        priority_queue<int> pq(nums.begin(), nums.end());
	    // while (k-- > 1) pq.pop();
        while (k---1) pq.pop();
	    return pq.top();
    }
};
