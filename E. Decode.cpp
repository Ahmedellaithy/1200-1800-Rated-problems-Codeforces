#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#include<iostream>
#define int long long
//using ull=uint64_t;
//const ull mod=999999910724017129;
using namespace std;
using namespace __gnu_pbds;
//find_by_order(x) => return element at the given `position(idx) x => takes * before it
//order_of_key(x) => return number of elements smaller than x
//if we want duplicates => we will pass pair instead of int
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
//template <typename T, typename R> using ordered_map = tree<T, R, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
//double pi = 2*acos(0.0);

const int mod=1e9+7;

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while (t--){
        string s;cin>>s;
        int n=s.size();
        int pref[n+1];
        pref[0]=0;
        for(int i=1;i<=n;i++){
            if(s[i-1]=='1') pref[i]=pref[i-1]-1;
            else pref[i]=pref[i-1]+1;
        }
        int ans=0;
        map<int,int>mp;
        mp[0]++;
        for(int i=1;i<=n;i++){
            int len=(n-i+1);
            ans=(ans+1LL*len *mp[pref[i]]%mod)%mod;
            mp[pref[i]]+=(i+1);
        }
        cout<<ans<<endl;
    }
}