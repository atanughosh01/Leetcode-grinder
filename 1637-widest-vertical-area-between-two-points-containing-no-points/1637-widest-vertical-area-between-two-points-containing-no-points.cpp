/*
    class Solution {
    public:
        int maxWidthOfVerticalArea(vector<vector<int>>& points) {
            int res = INT_MIN;
            set<int> st;
            for(auto &x : points) {
                st.insert(x[0]);
            }
            auto j = st.begin();
            for(auto itr=st.begin(); itr != st.end();) {
                j = itr;
                itr++;
                res = max(res, *itr - *j);
            }
            return res;
        }
    };
*/

class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        int res = 0;
        set<int> st;
        for(auto &x : points) {
            st.insert(x[0]);
        }
        for(auto itr=next(st.begin()); itr != st.end(); itr++) {
            res = max(res, *itr - *prev(itr));
        }
        return res;
    }
};
