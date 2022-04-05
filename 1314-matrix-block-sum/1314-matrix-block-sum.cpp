/*
    // Graph
    class Solution {
    public:
        vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int K) {
            vector<vector<int>> prefix_sum = prefixSum(mat);
            vector<vector<int>> answer = prefix_sum;
            for (int i = 0; i < mat.size(); i++) {
                for (int j = 0; j < mat[0].size(); j++) {
                    int upper_i = ((i+K) >= mat.size()) ? (mat.size()-1) : (i+K);
                    int upper_j = ((j+K) >= mat[0].size()) ? (mat[0].size()-1) : (j+K);
                    int lower_i = ((i-K) <= 0 ) ? 0 : (i-K);
                    int lower_j = ((j-K) <= 0 ) ? 0 : (j-K);
                    answer[i][j] = prefix_sum[upper_i][upper_j] - ((lower_i == 0) ? 0 : prefix_sum[lower_i-1][upper_j]) - ((lower_j == 0) ? 0 : prefix_sum[upper_i][lower_j-1]) + ((lower_i == 0) || (lower_j == 0)  ? 0 : prefix_sum[lower_i-1][lower_j-1]);
                }
            }
            return answer;
        }
    private:
        vector<vector<int>> prefixSum(vector<vector<int>>& mat) {
            vector<vector<int>> prefix_sum = mat;
            for (int i = 0; i < mat.size(); i++) {
                int sum = 0;
                for (int j = 0; j < mat[0].size(); j++) {
                    sum = sum + mat[i][j];
                    if (i > 0) {
                        prefix_sum[i][j] = sum + prefix_sum[i-1][j];
                    } else {
                        prefix_sum[i][j] = sum;   
                    }
                }
            }
            return prefix_sum;
        }
    };
*/



// DP
class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int> >& mat, int k) {
        int m=mat.size(),n=mat[0].size();
        vector<vector<int> > dp(m+1,vector<int>(n+1));
        dp[0][0]=mat[0][0];
        for(int i=1;i<n;i++){
            dp[0][i]=dp[0][i-1]+mat[0][i];
        }
        for(int i=1;i<m;i++){
            dp[i][0]=dp[i-1][0]+mat[i][0];
        }
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                dp[i][j]=dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1]+mat[i][j];
            }
        }
        vector<vector<int> > ans(m,vector<int>(n));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                ans[i][j]=dp[min(i+k,m-1)][min(j+k,n-1)]-((j-k-1)>=0 ? dp[min(i+k,m-1)][j-k-1] : 0)-((i-k-1)>=0 ? dp[i-k-1][min(n-1,j+k)] : 0)+(((j-k-1)>=0 && (i-k-1)>=0) ? dp[i-k-1][j-k-1] : 0);
            }
        }
        return ans;
    }
};
