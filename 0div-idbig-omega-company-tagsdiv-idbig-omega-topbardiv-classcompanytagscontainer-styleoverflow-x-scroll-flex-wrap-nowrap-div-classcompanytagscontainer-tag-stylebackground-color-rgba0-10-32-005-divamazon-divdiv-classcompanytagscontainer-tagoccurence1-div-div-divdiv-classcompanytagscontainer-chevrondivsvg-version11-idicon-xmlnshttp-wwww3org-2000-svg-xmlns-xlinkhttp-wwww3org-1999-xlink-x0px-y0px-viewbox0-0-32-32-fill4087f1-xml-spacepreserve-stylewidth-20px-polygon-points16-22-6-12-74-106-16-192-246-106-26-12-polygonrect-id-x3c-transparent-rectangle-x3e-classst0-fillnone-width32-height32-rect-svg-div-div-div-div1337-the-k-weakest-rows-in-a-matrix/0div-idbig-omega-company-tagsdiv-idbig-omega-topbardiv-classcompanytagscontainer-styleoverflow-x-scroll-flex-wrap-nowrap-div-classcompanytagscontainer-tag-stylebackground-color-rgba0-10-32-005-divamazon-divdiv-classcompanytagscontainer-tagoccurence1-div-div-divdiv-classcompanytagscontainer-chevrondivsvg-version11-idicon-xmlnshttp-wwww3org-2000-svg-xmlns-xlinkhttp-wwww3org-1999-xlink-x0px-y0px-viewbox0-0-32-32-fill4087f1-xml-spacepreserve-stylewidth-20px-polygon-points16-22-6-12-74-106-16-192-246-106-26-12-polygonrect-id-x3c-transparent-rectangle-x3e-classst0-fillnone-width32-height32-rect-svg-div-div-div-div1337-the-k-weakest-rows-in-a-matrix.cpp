/*
    // CompareHeapElements is used for modifying the comparator of priority queue, as per question
    struct CompareHeapElements {
        bool operator()(pair<int,int> const& p1, pair<int,int> const& p2)
        {
            if(p1.first<p2.first){
                return true;
            }
            else if(p1.first==p2.first && p1.second<p2.second){
                return true;
            }
            return false;
        }
    };

    class Solution {
    private:
        // calculate the soldier count using binary search
        int calculateSoldierCount(vector<int>& v) {
            int l=0; int h=v.size()-1;
            while(l<=h) {
                int mid=l+(h-l)/2;
                if(v[mid]==0) {
                    h=mid-1;
                } else {
                    l=mid+1;
                }
            }
            return l;
        }

    public:
        vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {

            // We will use max_heap of pairs because we need the top k minimum strength row index(s)
            // each element of max_heap will contain {each row soldier count, that row index}.
            priority_queue<pair<int,int>, vector<pair<int,int>>,CompareHeapElements> max_heap;

            // Iterating the matrix and find the total number of soldiers in each row,
            // then push {soldier_count,row_index} to the min_heap
            for(int i=0;i<mat.size();++i){
                max_heap.push({calculateSoldierCount(mat[i]),i});
                if(max_heap.size()>k){
                    max_heap.pop();
                }
            }

            vector<int>ans;
            while(max_heap.size()){ // pushing the top k smallest elements of min_heap to "ans"
                ans.push_back(max_heap.top().second);
                max_heap.pop();
            }

            reverse(ans.begin(), ans.end());
            return ans;
        }
    };
*/


class Solution {
private:
	int lastOcc(vector<int>&a) {
		int l = 0, h = a.size() - 1;
		int ans = -1;
		while (l <= h) {
			int mid = l + (h - l) / 2;
			if (a[mid] == 1) {
				ans = mid;
				l = mid + 1;
			} else if (a[mid] < 1) {
				h = mid - 1;
			}
		}
		return ans;
	}
public:
	vector<int> kWeakestRows(vector<vector<int>> &a, int k) {
		int n = a.size();
		vector<pair<int, int>> v;
		for (int i = 0; i < n; i++) {
			int cnt = lastOcc(a[i]) + 1;
			v.push_back({cnt, i});
		}
		sort(v.begin(), v.end());
		vector<int>ans;
		for (int i = 0; i < k; i++) {
			ans.push_back(v[i].second);
		}
		return ans;
	}
};
