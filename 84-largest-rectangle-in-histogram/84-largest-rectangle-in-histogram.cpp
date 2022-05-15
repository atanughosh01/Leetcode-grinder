/*
    class Solution {
    public:
        int largestRectangleArea(vector<int>& heights) {
            stack<int> st;
            int ans=0;
            heights.push_back(0);
            for(int i=0;i<heights.size();i++){
                while(!st.empty() && heights[st.top()]>heights[i]){
                    int top=heights[st.top()];
                    st.pop();
                    int ran=st.empty()?-1:st.top();
                    ans=max(ans,top*(i-ran-1));
                }
                st.push(i);
            }
            return ans;
        }
    };
*/


/*
    // Brute Force O(n^2)(too slow TLE)
    class Solution {
    public:
        int largestRectangleArea(vector<int>& heights) {
            int n = heights.size() ; 
            int max_area = 0 ; 
            for(int i = 0 ; i < n ; i++) {
                int curr_max = 0 ; 
                int min_height = INT_MAX ; 
                for(int j = i ; j < n ; j++) {
                    min_height = min(min_height , heights[j]) ; 
                    curr_max = max(curr_max , min_height * (j - i + 1)) ; 
                }
                max_area = max(max_area , curr_max) ; 
            }
            return max_area ; 
        }
    };
*/


/*
    // Divide n Conquer Approach O(NlogN)(using segment tree) O(N^2)(if we calculate range minimum naively)
    class SegmentTree {
    public: 
        int start , end , min ; 
        SegmentTree *left ;
        SegmentTree *right ;

        SegmentTree (int start, int end) {
            this->start = start ;
            this->end = end ;
            left = right = NULL ;
        }  
    };
    class Solution {
    public:
        int largestRectangleArea(vector<int>& heights) {
            SegmentTree* root = build(heights , 0 , heights.size() - 1) ;
            return maxAreaInThisSegment(heights , 0 , heights.size() - 1 , root) ;
        }
    private:
        SegmentTree* build(vector<int>& heights, int start, int end) {
            if (start > end) return NULL ;
            SegmentTree *root = new SegmentTree(start, end) ;
            if (start == end) {
                root->min = start ;
            return root ;
            } else {
              int middle = (start + end) / 2 ;
              root->left = build(heights, start, middle) ;
              root->right = build(heights, middle + 1, end) ;
              root->min = heights[root->left->min] < heights[root->right->min] ? root->left->min : root->right->min ;
              return root ;
            }
        }
        int query(vector<int> &heights , int start , int end , SegmentTree* root) {
            if(!root || end < root->start || start > root->end) return -1 ;
            if (start <= root->start && end >= root->end) {
                return root->min ;
            }
            int leftMin = query(heights , start , end , root->left) ;
            int rightMin = query(heights , start , end , root->right) ; 
            if(leftMin == -1)   return rightMin ;
            if(rightMin == -1)  return leftMin ; 
            return heights[leftMin] < heights[rightMin] ? leftMin : rightMin ; 
        }
        //calculates the maximum possible area in the histogram between indexes start and end
        int maxAreaInThisSegment(vector<int> &heights , int start , int end , SegmentTree *root) {
            if(start > end) {
                return -1 ;
            } 
            if(start == end) {
                return heights[start] ;
            }
            int wholeMin = query(heights , start , end , root) ; 
            return max({heights[wholeMin] * (end - start + 1) , maxAreaInThisSegment(heights , start , wholeMin - 1 , root) , maxAreaInThisSegment(heights , wholeMin + 1 , end , root)}) ;
        }
    };
*/


/*
    // Using left_smaller and right_smaller O(N)(2 pass)
    class Solution {
    public:
        int largestRectangleArea(vector<int>& heights) {
            int n = heights.size() ; 
            vector<int> left(n , 0) , right(n , n) ; 
            stack<int> s ; 
            for(int i = 0 ; i < n ; i++) {
                while(!s.empty() && heights[i] <= heights[s.top()]) s.pop() ;
                if(s.empty())   left[i] = 0 ; //minimum element
                else    left[i] = s.top() + 1 ;
                s.push(i) ; 
            }
            while(!s.empty())   s.pop() ; 
            for(int i = n - 1 ; i >= 0 ; i--) {
                while(!s.empty() && heights[i] <= heights[s.top()]) s.pop() ;
                if(s.empty())   right[i] = n - 1 ; //minimum element
                else    right[i] = s.top() - 1 ;
                s.push(i) ; 
            }
            int max_area = 0 ; 
            for(int i = 0 ; i < n ; i++) {
                max_area = max(max_area , heights[i] * (right[i] - left[i] + 1)) ;
            }
            return max_area ;
        }
    };
*/


// using only one stack O(N) (1 pass)
class Solution {
public:
    int largestRectangleArea(vector<int> &heights) {
        int n = heights.size(), max_area = INT_MIN, i = 0; 
        stack<int> s;
        while (i < n) {
            if (s.empty() || heights[s.top()] <= heights[i]) {
                s.push(i); 
                i++; 
            } else {
                int prev_top = s.top(); 
                s.pop(); 
                max_area = max(max_area , heights[prev_top] * (s.empty() ? i : i - s.top() - 1));
            }
        }
        while (!s.empty()) {
            int prev_top = s.top(); 
            s.pop(); 
            max_area = max(max_area, heights[prev_top]*(s.empty() ? i : i-s.top()-1));
        }  
        return max_area;
    }
};
