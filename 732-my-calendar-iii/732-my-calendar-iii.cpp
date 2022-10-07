// Time Complexity:O(NlogC) | Space Complexity: O(NlogC)
// N be the number of events booked, C be the largest time (i.e. 10^9 in this problem)

class MyCalendarThree_SEG_TREE {
private:
    unordered_map<int, int> vals;
    unordered_map<int, int> lazy;

public:
    MyCalendarThree_SEG_TREE() {}

    void update(int start, int end, int left, int right, int idx) {
        if (start > right || end < left) return;
        if (left >= start && right <= end) {
            lazy[idx]++;
            vals[idx]++;
        } else {
            int mid = left + (right - left) / 2;
            update(start, end, left, mid, idx * 2);
            update(start, end, mid + 1, right, idx * 2 + 1);
            vals[idx] = lazy[idx] + max(vals[idx * 2], vals[idx * 2 + 1]);
        }
    }

    int book(int start, int end) {
        update(start, end - 1, 1, 1000000000, 1);
        return vals[1];
    }
};



// Time Complexity: O(N^2) |Space Complexity: O(N) | N be the number of events booked
class MyCalendarThree {
    map<int, int> timeline;
public:
    MyCalendarThree() {}
    
    int book(int start, int end) {
        timeline[start]++;
        timeline[end]--;
        int curr = 0, k = 0;
        for (auto &[time, freq] : timeline) {
            curr += freq;
            k = max(k, curr);
        }
        return k;
    }
};



/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(start,end);
 */
