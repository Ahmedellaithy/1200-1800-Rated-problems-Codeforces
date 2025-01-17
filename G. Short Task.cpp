#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#include<iostream>
#define int long long
//using uint=uint64_t;
//const uint mod=999999910724017129;
//double pi = 2*acos(0.0);
//int dx[] = {0,0,1,-1};
//int dy[] = {1,-1,0,0};
using namespace std;
using namespace __gnu_pbds;
//find_by_order(x) => return element at the given `position(idx) x => takes * before it
//order_of_key(x) => return number of elements smseger than x
//if we want duplicates => we wiint pass pair instead of int
typedef tree<int, null_type, less <int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
//template <typename T, typename R> using ordered_map = tree<T, R, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

const int N=1e7+2;
int ans[N],dp[N];

void pre(){
    for(int i=1;i<N;i++){
        for(int j=i;j<N;j+=i){
            ans[j]+=i;
        }
    }
    for(int i=N;i>=1;i--){
        if(ans[i]<N) dp[ans[i]]=i;
    }
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    pre();
    int t;cin>>t;
    while (t--){
        int c;cin>>c;
        if(dp[c]==0) cout<<-1<<endl;
        else cout<<dp[c]<<endl;
    }
}