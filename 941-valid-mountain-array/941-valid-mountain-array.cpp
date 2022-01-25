/*

// Correct but TLE Solution

class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        int n = (int)arr.size();
        if(n<3) return false;
        int idx=-1;
        for(int i=0; i<n; i++) {
            if (arr[i] == *max_element(arr.begin(), arr.end()))
                idx = i;
        }
        if (idx == 0 || idx == n-1) return false;
        for(int i=0; i<idx; i++) {
            if(arr[i+1]<=arr[i])
                return false;
            // break;
        }
        for(int i=idx; i<n-1; i++){
            if(arr[i+1]>=arr[i])
                return false;
            // break;
        }
        return true;
    }
};

*/

class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        int n = (int)arr.size();
        if(n<3) return false;
        // if (n==3) {
        //     if (arr[1] > arr[0] and arr[1] > arr[2])
        //         return true;
        //     return false;
        // }
        // if(arr[n-1] > arr[n-2])
        //     return false;
        if (arr[n-1]>arr[n-2] || arr[0]>arr[1])
            return false;
        int idx = -1;
        for(int i=0; i<n-2; i++) {
            if (arr[i+1] > arr[i])
                idx = i+1;
            else if (arr[i+1] == arr[i])
                return false;
            else {
                idx = i;
                break;
            }
        }
        for(int i=idx; i<n-1; i++) {            
            if(arr[i+1] >= arr[i])
                return false;
        }
        return true;
    }
};
