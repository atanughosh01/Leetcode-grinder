class Solution {  
public:  
    int halveArray(vector<int>& a) {  
        priority_queue<double> q; 
        int n = a.size(), opr = 0;
        double sum = 0, temp;
        for(int i=0;i<n;i++){  
            sum+=a[i];
            temp = sum;
        }
        sum /= 2.0;
        for(int i=0;i<n;i++) {  
            q.push(a[i]);  
        }
        while(temp > sum) {  
            double h = q.top();  
            q.pop();  
            q.push(h/2.0);  
            temp -= (h/2.0);  
            opr++; 
        }
        return opr;
    }  
};
