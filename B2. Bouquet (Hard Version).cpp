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
typedef tree<int, null_type, less <int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
//template <typename T, typename R> using ordered_map = tree<T, R, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
//double pi = 2*acos(0.0);

signed main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while (t--){
        int n,m;cin>>n>>m;
        vector<pair<int,int>>pr(n);
        for(int i=0;i<n;i++) cin>>pr[i].first;
        for(int i=0;i<n;i++) cin>>pr[i].second;
        sort(pr.begin(),pr.end());
        int ans=0;
        for(int i=0;i<n;i++){
            int x=m/pr[i].first;
            if(x>=pr[i].second) ans=max(ans,pr[i].first*pr[i].second);
            else ans=max(ans,pr[i].first*x);
        }
        for(int i=1;i<n;i++){
            if(pr[i].first-pr[i-1].first==1){
                int am=m;
                int x=am/pr[i-1].first;
                if(x>=pr[i-1].second) {
                    am-=(pr[i-1].first*pr[i-1].second);
                    x=pr[i-1].second;
                }
                else am-=(pr[i-1].first*x);

                int y=am/pr[i].first;
                if(y>=pr[i].second){
                    am-=(pr[i].first*pr[i].second);
                    y=pr[i].second;
                }
                else am-=(pr[i].first*y);

                int mn=min({x,pr[i].second-y,am});
                ans=max(ans,m-am+mn);
            }
        }
        cout<<ans<<endl;
    }
}