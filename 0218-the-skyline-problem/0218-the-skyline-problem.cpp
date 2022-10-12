class Solution_1 {
public:
    vector<pair<int, int>> getSkyline(vector<vector<int>> &buildings) {
        vector<pair<int, int>> walls, ans;
        for (auto &b : buildings) {
            walls.push_back(make_pair(b[0], -b[2]));
            walls.push_back(make_pair(b[1], b[2]));
        }
        sort(walls.begin(), walls.end());
        multiset<int> leftWallHeights = {0};
        int top = 0;
        for (auto &w : walls) {
            if (w.second < 0) {
                leftWallHeights.insert(-w.second);
            } else {
                leftWallHeights.erase(leftWallHeights.find(w.second));
            }
            if (*leftWallHeights.rbegin() != top) {
                ans.push_back(make_pair(w.first, top = *leftWallHeights.rbegin()));
            }
        }
        return ans;
    }
};



class Solution_2 {
public:
	vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
		vector<pair<int, int>> res;
		int cur = 0, cur_X, cur_H = -1,  len = buildings.size();
		priority_queue< pair<int, int>> liveBlg;
		while (cur < len || !liveBlg.empty()) {
			cur_X = liveBlg.empty() ? buildings[cur][0] : liveBlg.top().second;
			if (cur >= len || buildings[cur][0] > cur_X) {
				while (!liveBlg.empty() && ( liveBlg.top().second <= cur_X)) {
					liveBlg.pop();
				}
			} else {
				cur_X = buildings[cur][0];
				while (cur < len && buildings[cur][0] == cur_X) {
					liveBlg.push(make_pair(buildings[cur][2], buildings[cur][1]));
					cur++;
				}
			}
			cur_H = liveBlg.empty() ? 0 : liveBlg.top().first;
			if (res.empty() || (res.back().second != cur_H) ) {
				res.push_back(make_pair(cur_X, cur_H));
			}
		}
		return res;
	}
};




class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>> &buildings) {
        int n = buildings.size();
        vector<vector<int>> ans;
        vector<pair<int, int>> a;
        int cur_ht = 0;
        multiset<int, greater<int>> pq;
        pq.insert(0);
        for (int i = 0; i < n; i++) {
            int st = buildings[i][0];
            int en = buildings[i][1];
            int ht = buildings[i][2];
            a.push_back({st, -ht});
            a.push_back({en, ht});
        }
        sort(a.begin(), a.end(), [](pair<int, int> &a, pair<int, int> &b) {
            if (a.first == b.first) return a.second < b.second;
            return a.first < b.first;
        });
        for (int i = 0; i < a.size(); i++) {
            int pt = a[i].first, ht = a[i].second;
            if (ht < 0) {
                pq.insert(-ht);
            } else {
                auto it = pq.find(ht);
                if (it != pq.end()) pq.erase(it);
            }
            int htt = *pq.begin();
            if (cur_ht != htt) {
                int pt = a[i].first;
                ans.push_back({pt, htt});
                cur_ht = htt;
            }
        }
        return ans;
    }
};
