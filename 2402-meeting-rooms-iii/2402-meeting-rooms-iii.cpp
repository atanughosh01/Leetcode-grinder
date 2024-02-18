typedef pair<long long, int> pli;

class Solution_1 {
public:
    int mostBooked(int n, vector<vector<int>> &meetings) {
        int cnt[101]{0};
        sort(begin(meetings), end(meetings));
        priority_queue<int, vector<int>, greater<int>> available;
        priority_queue<pli, vector<pli>, greater<pli>> busy;
        for (int i = 0; i < n; i++) available.push(i);
        for (auto &meeting : meetings) {
            while (!busy.empty() && busy.top().first <= meeting[0]) {
                available.push(busy.top().second);
                busy.pop();
            }
            long long start = -1, room = -1;
            long long duration = meeting[1] - meeting[0];
            if (available.empty()) {
                start = busy.top().first;
                room = busy.top().second;
                busy.pop();
            } else {
                start = meeting[0];
                room = available.top();
                available.pop();
            }
            cnt[room]++;
            busy.push({start + duration, room});
        }
        return max_element(begin(cnt), end(cnt)) - begin(cnt);
    }
};


class Solution {
public:
    int mostBooked(int n, vector<vector<int>> &meetings) {
        int cnt[101]{0};
        sort(meetings.begin(), meetings.end());
        priority_queue<pli, vector<pli>, greater<pli>> busy;
        for (int i = 0; i < n; i++) {
            busy.push({meetings[0][0], i});
        }
        for (auto &meeting : meetings) {
            while (busy.top().first < meeting[0]) {
                busy.push({meeting[0], busy.top().second});
                busy.pop();
            }
            auto [start, room] = busy.top();
            long long duration = meeting[1] - meeting[0];
            busy.pop();
            busy.push({start + duration, room});
            cnt[room]++;
        }
        return max_element(begin(cnt), end(cnt)) - begin(cnt);
    }
};
