class Solution {
public:
    int shortestSequence(vector<int> &rolls, int k) {
        int res = 1;
        unordered_set<int> st;
        for (int &roll : rolls) {
            st.insert(roll);
            if (st.size() == k) {
                res++;
                st.clear();
            }
        }
        return res;
    }
};

/*
    1. For a sequence of size 1, all k dice must appear in rolls.
    2. For a sequence of size 2, all k dice must appear after all k dice appear in rolls.
        ... and so on.
*/
