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
    while(t--){
        int n;cin>>n;
        int arr[n];
        for(int i=0;i<n;i++) cin>>arr[i];
        map<int,vector<int>>mp;
        vector<int>res(n);
        for(int i=0;i<n;i++){
            mp[arr[i]>>2].push_back(i);
        }
        for(auto &[it,v]: mp){
            vector<int>ans;
            for(auto it2:v){
                ans.push_back(arr[it2]);
            }
            sort(v.begin(),v.end());
            sort(ans.begin(),ans.end());
            for(int i=0;i<v.size();i++){
                res[v[i]]=ans[i];
            }
        }
        for(int i=0;i<res.size();i++) cout<<res[i]<<" ";
        cout<<endl;
    }
}