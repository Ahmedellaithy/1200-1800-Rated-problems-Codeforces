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
int bin_exp(int a,int pow){
    int res=1;
    while(pow){
        if(pow&1){
            res=(res*a)%mod;
            pow--;
        }
        else{
            a=(a*a)%mod;
            pow/=2;
        }
    }
    return res;
}

signed main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while (t--){
        int l,r,k;cin>>l>>r>>k;
        if(k>=10){
            cout<<0<<endl;
            continue;
        }
        int cnt=0;
        cnt=10/k;
        if(10%k){
            cnt++;
        }
        int mx= bin_exp(cnt,r);
        int mn= bin_exp(cnt,l);
        int ans=(mx-mn)%mod;
        if(ans<0) ans+=mod;
        cout<<ans<<endl;
    }
}