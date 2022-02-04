class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        int n  =(int)nums.size(), x;
		int mi = nums[k], ans=nums[k];                   //Start with the given k
		for(int i=k,j=k;i>=0 || j<n ;) {    // Move in the array with the help of two pointer in both direction
            while(j<n && nums[j]>=mi) ++j;  //we move in right direction until our minimum, that is mi will not change
            while(i>=0 && nums[i]>=mi) --i; //we move in left until our minimum, that is mi will not change
            ans=max(ans,mi*(j-i-1));        // update answer everytime

            // Here, We have two potential minimum, which is nums[i] and nums[j] in any direction
            // So we move to that minimum which will be greater between the two minimum then again 
            // apply the above two step, that is find the longest array in with the given minimum
            // This we can understand with some testcases
            if(i>=0 and j<n)
                mi = ((nums[i] > nums[j])? nums[i] : nums[j]); 
            else if(j<n)                    // if i<0 we can move only in right direction
                mi = nums[j];
            else if(i>=0)                   // if j>=n we can move only in left direction
                mi = nums[i];
        }
        return ans;
    }
};
