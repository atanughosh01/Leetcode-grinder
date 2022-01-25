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



// Optimized but really messy solution

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

*/

/*

// Clean and optimized solution

class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        int f = false;
        int c = 0, u = 0;

        for(int i = 1; i < (int)arr.size()-1; i++){
            if(arr[i] == arr[i-1] || arr[i] == arr[i+1])
                return false;
            if(arr[i] > arr[i-1] && arr[i] > arr[i+1])
                c++, f = true;
            if(arr[i] < arr[i-1] && arr[i] < arr[i+1])
                u++;
        }
        return (f && c == 1 && u == 0);
    }
};

*/

class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        bool up=1, a=0, b=0;
        int sz= (int)arr.size();

        if(sz < 3) return false;

        for(int i=1;i<sz;++i){
            if (arr[i-1] < arr[i]){
                a=1;
                if(up==0) return false;
            } else if (arr[i-1] > arr[i]){
                b=1;
                if(up==1) up=0;
            } else
                return false;
        }
        return a and b ;
    }
};
