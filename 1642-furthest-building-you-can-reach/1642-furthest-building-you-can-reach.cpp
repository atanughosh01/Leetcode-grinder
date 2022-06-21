/*
    class Solution {
    public:
        int furthestBuilding(vector<int> &heights, int bricks, int ladders) {
            int n = (int)(heights.size()), i = 0;
            priority_queue<int, vector<int>, greater<int>> pq;
            for (i=0; i<n-1; i++) {
                if (heights[i] < heights[i+1]) {
                    pq.push(heights[i+1] - heights[i]);
                }
                if (pq.size() > ladders) {
                    int temp = pq.top();
                    pq.pop();
                    bricks -= temp;
                    if (bricks < 0) break;
                }
            }
            return i;
        }
    };
*/


class Solution {
public:
    int furthestBuilding(vector<int> &H, int B, int L) {
        int len = H.size() - 1;
        priority_queue<int> pq;
        for (int i = 0; i < len; i++) {
            int diff = H[i+1] - H[i];
            if (diff > 0) {
                if (L) pq.push(-diff), L--;
                else if (!pq.empty() && diff > -pq.top())
                    pq.push(-diff), B += pq.top(), pq.pop();
                else B -= diff;
                if (B < 0) return i;
            }
        }
        return len;
    }
};
