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
const int N=1002;
int dp[N+1];

int ncr(int n, int r) {
    if (r>n) return 0;
    if (r==0 || n==r) return 1;
    double res=0;
    for (int i=0;i<r;i++) {
        res+=log(n-i)-log(i+1);
    }
    return (int)round(exp(res));
}

//Derangement
void pre(){
    dp[0]=1;
    dp[1]=0;
    for(int i=2;i<N;i++){
        dp[i]=((dp[i-1]+dp[i-2]) * (i-1));
    }
}

signed main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    pre();
    int n,k;cin>>n>>k;
    int ans=0;
    int len=n-k;
    for(int i=len;i<=n;i++){
        if(k==-1) break;
        ans+= (ncr(n,i)*dp[k]);
        k--;
    }
    cout<<ans;
}