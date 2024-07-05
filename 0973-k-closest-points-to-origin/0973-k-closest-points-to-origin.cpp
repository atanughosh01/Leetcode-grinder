class Solution_1 {
private:
	static inline int getsum(const vector<int> &v) {
		return v[0] * v[0] + v[1] * v[1];
	}
	static inline bool comp(const vector<int> &l, const vector<int> &r) {
		return getsum(l) <= getsum(r);
	}
	int partition(vector<vector<int>> &arr, int left, int right) {
		vector<int> pivot = arr[right];
		int partitionIndex = left;
		for (int i = left; i < right; i++) {
			if (comp(arr[i], pivot)) {
				swap(arr[i], arr[partitionIndex]);
				partitionIndex++;
			}
		}
		swap(arr[partitionIndex], arr[right]);
		return partitionIndex;
	}
	void quickselect(vector<vector<int>> &v, int l, int r, int K) {
		while (l <= r) {
			int mid = partition(v, l, r);
			if (mid == K) return;
			if (mid < K) l = mid + 1;
			else r = mid - 1;
		}
	}
public:
	vector<vector<int>> kClosest(vector<vector<int>> &points, int k) {
		quickselect(points, 0, points.size() - 1, k);
		return vector<vector<int>>(points.begin(), points.begin() + k);
	}
};


// O(n * log(n)) + O(k) Time | O(n) + O(k) Space
class Solution {
private:
    double dist(const vector<int> &arr) {
        int sq = arr[0]*arr[0] + arr[1]*arr[1];
        return sqrt(sq);
    }
public:
    vector<vector<int>> kClosest(vector<vector<int>> &points, int k) {
        int n = points.size();
        if (k == n) return points;
        vector<vector<int>> res;
        map<double, vector<int>> mp;
        // O(n * log(n)) time
        for (int i = 0; i < n; i++) {
            double d = dist(points[i]);
            mp[d].push_back(i);
        }
        // O(k) time
        for (auto it = mp.begin(); it != mp.end(); it++) {
            vector<int> vec = it->second;
            for (int &x : vec) {
                res.push_back(points[x]);
                if (k == res.size()) return res;
            }
        }
        return {};
    }
};
