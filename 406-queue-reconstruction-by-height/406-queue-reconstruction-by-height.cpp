class Solution {
private:
    struct cmp {
        bool operator()(const vector<int> &a, const vector<int> &b) {
            if (a[0] == b[0]) {
                return a[1] < b[1];
            }
            return a[0] > b[0];
        }
    };
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>> &people) {
        int n = (int)(people.size());
        vector<vector<int>> queue(n);
        priority_queue<vector<int>, vector<vector<int>>, cmp> pq;
        for (vector<int> &person : people) {
            pq.push(person);
        }
        while (!pq.empty()) {
            int i = 0, count = 0;
            while (count < pq.top()[1] || queue[i].size() != 0) {
                if (queue[i++].size() == 0) {
                    count++;
                }
            }
            queue[i] = pq.top();
            pq.pop();
        }
        return queue;
    }
};



/*
    class Solution {
    private:
        static bool cmp(const vector<int> &a, const vector<int> &b) {
            if (a[0] == b[0]) {
                return a[1] < b[1];
            }
            return a[0] > b[0];
        }
    public:
        vector<vector<int>> reconstructQueue(vector<vector<int>> &people) {
            int n = (int)(people.size());
            sort(people.begin(), people.end(), cmp);
            vector<vector<int>> queue;
            for (int i = 0; i < n; i++) {
                auto pos = queue.begin() + people[i][1];
                queue.insert(pos, people[i]);
            }
            return queue;
        }
    };
*/
