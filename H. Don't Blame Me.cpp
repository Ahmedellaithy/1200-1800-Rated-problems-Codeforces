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

const int mod=1e9+7;
int arr[200002];
int dp[200002][65][2];
int n,k;

int add(int a,int b,int mod){
    int res=(a+b)%mod;
    if(res<0) res+=mod;
    return res;
}

int solve(int idx,int AND,int take){
    if(idx==n){
        if(__builtin_popcount(AND)==k && take==1) return 1;
        else return 0;
    }
    if(dp[idx][AND][take]!=-1){
        return dp[idx][AND][take];
    }
    int ans= add(solve(idx+1,AND,take) , solve(idx+1,AND&arr[idx],1) , mod);
    return dp[idx][AND][take]=ans;
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while (t--){
        cin>>n>>k;
        for(int i=0;i<n;i++) cin>>arr[i];
        for(int i=0;i<n;i++){
            for(int j=0;j<=63;j++){
                for(int k=0;k<2;k++){
                    dp[i][j][k]=-1;
                }
            }
        }
        cout<<solve(0,63,0)<<endl;
    }

}