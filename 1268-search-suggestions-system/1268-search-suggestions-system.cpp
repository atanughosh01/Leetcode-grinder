/*
    // Using 2-Pointer and Sliding-Window
    class Solution {
    public:
        vector<vector<string>> suggestedProducts(vector<string> &products, string &searchWord) {
            vector<vector<string>> res;
            sort(products.begin(), products.end());
            int l = 0, r = (int)products.size() - 1;
            for (int i = 0; i < (int)searchWord.size(); i++) {
                char ch = searchWord[i];
                while(l<=r && (products[l].size() <= i || products[l][i]!=ch)) l++;
                while(l<=r && (products[r].size() <= i || products[r][i]!=ch)) r--;
                res.push_back(vector<string>());
                int m = min(3, r - l + 1);
                for (int j = 0; j < m; j++) {
                    res.back().push_back(products[l + j]);
                }
            }
            return res;
        }
    };
*/


class Solution {
   public:
    vector<vector<string>> suggestedProducts(vector<string> &products, string &searchWord) {
        vector<vector<string>> res;
        sort(products.begin(), products.end());
        for (int i = 0; i < searchWord.size(); i++) {
            string str = searchWord.substr(0, i + 1);
            int low = 0, high = (int)products.size();
            while (low < high) {
                int mid = low + (high - low) / 2;
                if (products[mid] >= str) {
                    high = mid;
                } else {
                    low = mid + 1;
                }
            }
            vector<string> temp;
            for (int j = low; j < min(low + 3, (int)products.size()); j++) {
                if (products[j].find(str) == 0) {
                    temp.push_back(products[j]);
                } else {
                    break;
                }
            }
            res.push_back(temp);
        }
        return res;
    }
};
