#include<bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace  __gnu_pbds;
typedef long long ll;
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds;

class Solution {
public:
    long long numberOfPairs(vector<int> &num1, vector<int> &num2, int &diff) {
        pbds s_pl;
        ll res = 0, n = num1.size(), c = 100000;
        for (ll i = 0; i < n; i++) {
            res += s_pl.order_of_key((ll)(num1[i] - num2[i] + diff + 1) * c);
            s_pl.insert(((ll)(num1[i] - num2[i]) * c) + i);
        }
        return res;
    }
};
