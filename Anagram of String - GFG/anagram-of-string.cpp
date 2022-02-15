// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
const int CHARS = 26;

// function to calculate minimum numbers of characters
// to be removed to make two strings anagram
int remAnagram(string str1, string str2);

// Driver program to run the case
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string str1,str2;
        cin>>str1>>str2;
        cout << remAnagram(str1, str2);
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends


// Problem : https://practice.geeksforgeeks.org/problems/anagram-of-string/1


int remAnagram(string str1, string str2) {
    unordered_map<char,int> d;
    char a = 'a';
    for(int i=0; i<str1.length(); i++) {
       d[str1[i]]++;
    }
    for(int i=0; i<str2.length(); i++) {
       d[str2[i]]--;
    }
    int ans = 0;
    for(int i=1; i<=26; i++) {
       ans += abs(d[a]);
       a++;
    }
    return ans;
}
