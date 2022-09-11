class Solution {
   public:
    int minGroups(vector<vector<int>> &intervals) {
        sort(intervals.begin(), intervals.end());
        priority_queue<int, vector<int>, greater<int>> pq; // Min Heap
        int res = 0;
        for (const vector<int> &interval : intervals) {
            int start = interval[0], end = interval[1];
            if (pq.empty() || pq.top() > start) res++;
            else pq.pop();
            pq.push(end + 1);
        }
        return res;
    }
};
