class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int temp, maxProf = 0, l=0;
        int n = (int)prices.size();
        for(int r=0; r<n; r++) {
            temp = prices[r]-prices[l];
            if(temp<0){
                l++;
                r--;
            }
            else{
                maxProf = max(temp, maxProf);
            }
        }
        return maxProf;
    }
};
