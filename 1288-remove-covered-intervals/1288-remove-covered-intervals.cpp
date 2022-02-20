class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int res = 0,left = -1, right=-1;
        sort(intervals.begin(), intervals.end());
        //after sorting both start and end will be sorted in increasing order
        //e.g. (1,5), (1,8), (2,9), (3,5), (4,7), (4,9)
        
        //If we see carefully see, there are 3 possibilities after sorting
        //case 1->(start0 < start1 & end0 < end1) e.g. (1,5), (3,6)-> this is clearly not overlapping
        //case 2->(start0 < start1 & end1 < end0)  e.g. (1, 5) (2,4)-> This is clearly overlapping. 
        //case 3->(start0 = start1 & end0 < end1) e.g. (2,4),(2,6)-> This is also overlapping.
        //Case 3 is tricky. Ideally (2,4) is covered by (2,6) but in this code (2,4) will be counted and (2,6) will be skipped.
        
        for (auto v:intervals) {
            if(v[0]>left && v[1]>right) {   //Update the result only if (start0 < start1 & end0, end1)
                res++;
                left = v[0];                //no need to update the left in other 2 cases
            }
            right = max(right, v[1]);       //e.g. (1,3) (1,6)-> this will make sure 6 is chosen as the end of the previous interval
        }
        return res;
    }
};
