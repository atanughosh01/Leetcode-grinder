class Solution {
public:
    vector<int> executeInstructions(int n, vector<int>& startPos, string s) {
        int len = (int)s.size(), count = 0;
        vector<int> ans(len);
          for(int i = 0; i < len; i++){
            int cx = startPos[0];
            int cy = startPos[1];
            int count = 0;
            for(int j = i; j < len; j++){
                char ch = s[j];
                if(ch == 'R' && cy+1 < n){
                    cy++;
                    count++;
                }
                else if(ch == 'D' && cx+1 < n){
                    cx++;
                    count++;
                }
                else if(ch == 'L' && cy-1 >= 0){
                    cy--;
                    count++;
                }
                else if(ch == 'U' && cx-1 >= 0){
                    cx--;
                    count++;
                }
                else {
                    break;
                }
            }
            ans[i] = count;
        }
        return ans;
    }
};
