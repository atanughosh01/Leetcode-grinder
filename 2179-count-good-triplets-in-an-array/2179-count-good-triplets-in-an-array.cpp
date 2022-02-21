/*
    #include <ext/pb_ds/assoc_container.hpp> 
    #include <ext/pb_ds/tree_policy.hpp>
    using namespace __gnu_pbds;
    typedef long long ll;
    typedef long double ld;
    #define mod 1000000007
    #define all(x) begin(x),end(x)
    #define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>


    class Solution {
    public:
        long long goodTriplets(vector<int>& nums1, vector<int>& nums2) {
            unordered_map<int, int> mapping;
            int no = 1;
            for (int x : nums1){
                mapping[x] = no;
                no++;
            }
            for (int i = 0; i < nums2.size(); ++i)
                nums2[i] = mapping[nums2[i]];
            int n = nums2.size();
            ordered_set st1, st2;
            for (int x : nums2)
                st2.insert(x);
            ll ans = 0;
            st1.insert(nums2[0]);
            st2.erase(st2.find(nums2[0]));
            for (int i = 1; i < n - 1; ++i) {
                st2.erase(st2.find(nums2[i]));
                ll less = (ll)st1.order_of_key(nums2[i]);
                ll great = (ll) (((int)st2.size()) - st2.order_of_key(nums2[i]));
                ans += (less * 1ll * great);
                st1.insert(nums2[i]);
            }
            return ans;
        }
    };
*/

#define ll long long

class Solution {
private:
    vector<ll> seg, v;
    int n = 0;

    void build(ll l,ll r,ll c=1) {
        if(l==r) {
            seg[c]=v[l];
            return;
        }
        ll mid=(l+r)/2;
        build(l,mid,2*c); build(mid+1,r,2*c+1);
        seg[c]=seg[2*c]+seg[2*c+1];
        return;
    }

    ll query(ll l,ll r,ll a,ll b,ll c=1) {
        if(l>b||r<a)
            return 0;
        if(l>=a&&r<=b)
            return seg[c];
        ll mid=(l+r)/2;
        return query(l,mid,a,b,2*c)+query(mid+1,r,a,b,2*c+1);
    }

    void update(ll l,ll r,ll ind,ll c=1) {   
        if(ind<l||ind>r)
            return;
        if(l==r&&l==ind) {
            seg[c]=1;
            return;
        }
        ll mid=(l+r)/2;
        update(l,mid,ind,2*c);  update(mid+1,r,ind,2*c+1);
        seg[c]=seg[2*c]+seg[2*c+1];
    }
    
public:
    long long goodTriplets(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        v.resize(n+1,0);
        ll ans=0;
        map<ll,ll> m;
        for(ll i=1;i<=n;i++) {
            m[nums2[i-1]+1]=i;
        }
        seg.clear();
        seg.resize(4*n+10,0);
        build(1,n);
        update(1,n,m[nums1[0]+1]);
        for(ll i=2;i<=n;i++) {
            ll r=m[nums1[i-1]+1];
            ll q=query(1,n,1,r);
            ll d=i-q-1;
            ll loc=(n-r)-d;
            ans+=loc*q;
            update(1,n,r);
        }
        return ans;
    }
};
