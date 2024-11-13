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

const int N=3e5+5;
int dp[N][11];
int arr[N];
int n,k;

int solve(int idx,int ch) {
    if(idx==n){
        return 0;
    }
    if(dp[idx][ch]!=-1){
        return dp[idx][ch];
    }
    int ans=solve(idx+1,ch)+arr[idx];
    int mn=arr[idx];
    for (int i=1;i<=ch&&idx+i<n;i++) {
        mn=min(mn,arr[idx+i]);
        ans=min(ans,solve(idx+i+1,ch-i)+mn*(i+1));
    }
    return dp[idx][ch]=ans;
}

signed main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t=1;cin>>t;
    while (t--){
        cin>>n>>k;
        for (int i=0;i<n;i++) cin>>arr[i];
        for(int i=0;i<=n;i++){
            for(int j=0;j<=k;j++){
                dp[i][j]=-1;
            }
        }
        cout<<solve(0,k)<<endl;
    }
}