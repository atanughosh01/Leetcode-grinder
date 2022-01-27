/*

class Solution {
private:
    int helper(vector<int>& nums, int ls, int le, int rs, int re, int val, int bit) {
        if (bit == -1) return val;
        int mask = 1<<bit, j = ls, k = rs;
        for (int i = ls; i <= le; i++) 
            if (nums[i]&mask) swap(nums[i], nums[j++]);
        for (int i = rs; i <= re; i++) 
            if (nums[i]&mask) swap(nums[i], nums[k++]);
        if (j > ls && j <= le) {
            int ans = 0;
            if (k > rs) 
                ans = helper(nums, j, le, rs, k-1, val*2+1, bit-1);
            if (k <= re) 
                ans = max(ans, helper(nums, ls, j-1, k, re, val*2+1, bit-1));
            return ans;
        }
        else if (j <= ls) {
            if (k > rs) 
                return helper(nums, ls, le, rs, k-1, val*2+1, bit-1);
            else 
                return helper(nums, ls, le, rs, re, val*2, bit-1);
        }
        else {
            if (k <= re) 
                return helper(nums, ls, le, k, re, val*2+1, bit-1);
            else 
                return helper(nums, ls, le, rs, re, val*2, bit-1);
        }
    }

public:
    int findMaximumXOR(vector<int>& nums) {
        int n = (int)nums.size();
        return helper(nums, 0, n-1, 0, n-1, 0, 30);
    }
};

*/


struct trie{
    trie* next[2];
    trie()
    {
        next[0]=NULL;
        next[1]=NULL;
    }
};
class TrieNode{
    private:
        trie* root;
    public:
        TrieNode()
        {
            root=new trie();
        }
    
    void insert(int num)
    {
        trie* curr=root;
        
        for(int i=31;i>=0;i--)
        {
            int bit=(num>>i)&1;
            if(curr->next[bit]==NULL)
            {
                curr->next[bit]=new trie();
            }
            curr=curr->next[bit];
        }
    }
    
    int max_xor(int num)
    {
        trie* curr=root;
        int ans=0;
        for(int i=31;i>=0;i--)
        {
            int bit=(num>>i)&1;
            
            if(curr->next[!bit])
            {
                ans+=(1<<i);
                curr=curr->next[!bit];
            }
            else
            {
                curr=curr->next[bit];
            }
        }
        return ans;
    }   
};

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        int max_ans=0;
        int n=nums.size();
        
        TrieNode* t=new TrieNode();
        
        for(int i=0;i<n;i++)
        {
            t->insert(nums[i]);
            max_ans=max(max_ans,t->max_xor(nums[i]));
        }
        return max_ans;
    }
};
