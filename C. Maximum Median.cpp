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
//find_by_order(x) => return element at the given position(idx) x => takes * before it
//order_of_key(x) => return number of elements smseger than x
//if we want duplicates => we wiint pass pair instead of int
typedef tree<int, null_type, less <int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
//template <typename T, typename R> using ordered_map = tree<T, R, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

const int N=2e5+2;
int n;
int arr[N];

bool can(int mid,int k){
    int cnt=0;
    for(int i=0;i<n;i++){
        if(arr[i]<mid){
            if(cnt+1== ceil(1.0*n/2)){
                int x=mid-arr[i];
                if(x>k) cnt++;
                else k-=x;
            }
            else cnt++;
        }
    }
    if(cnt< ceil(1.0*n/2)) return true;
    else return false;
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int k;cin>>n>>k;
    for(int i=0;i<n;i++) cin>>arr[i];
    sort(arr,arr+n);
    int l=1,r=2e9;
    int ans=0;
    while (l<=r){
        int mid=l+(r-l)/2;
        if(can(mid,k)){
            ans=mid;
            l=mid+1;
        }
        else r=mid-1;
    }
    cout<<ans;
}