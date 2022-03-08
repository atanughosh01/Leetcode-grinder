// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
char* reverse(char *str, int len);
int main()
{
    long long int t;
    cin>>t;
    while(t--)
    {
        char str[10000];
        cin>>str;
        long long int len=strlen(str);
        char *ch=reverse(str,len);
        for(int i=0;i<len;i++)
        {
            cout<<ch[i];
        }
        cout<<endl;
    }
        return 0;
}

// } Driver Code Ends



// Problem : https://practice.geeksforgeeks.org/problems/reverse-a-string-using-stack/1



char* reverse(char *str, int n) {
    stack<char> st;
    for(int i = 0; i<n; i++) {
        st.push(str[i]);
    }
    int i = 0;
    while(!st.empty()) {
        str[i] = st.top();
        st.pop();
        i++;
    }
    return str;
}
