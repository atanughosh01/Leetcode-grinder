class Solution {
public:
    vector<long long> maximumEvenSplit(long long num) {
        vector<long long> arr = {};
        if(num%2)
            return arr;
        int con = 0;
        while(true) {
           con += 2;
           num -= con;
            if(num >= con+2)
                arr.push_back(con);
            else{
                arr.push_back(num + con);
                break;
            }
       }
        return arr;
    }
};
