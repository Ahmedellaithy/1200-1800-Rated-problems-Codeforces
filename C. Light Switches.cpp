#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#include<iostream>
#define int long long
using namespace std;
using namespace __gnu_pbds;
//find_by_order(x) => return element at the given position(idx) x => takes * before it
//order_of_key(x) => return number of elements smaller than x
//if we want duplicates => we will pass pair instead of int
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
//template <typename T, typename R> using ordered_map = tree<T, R, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while (t--){
        int n,k;cin>>n>>k;
        int arr[n];
        for(int i=0;i<n;i++) cin>>arr[i];
        sort(arr,arr+n);
        int ans=0;
        if(arr[0]+k>arr[n-1]){
            cout<<arr[n-1]<<endl;
        }
            //int pref[n+1];
        else{
            bool flag=false;
            for(int i=arr[n-1];i<=arr[n-1]+k;i++){
                bool x=true;
                for(int j=0;j<n;j++){
                    int ch=(i-arr[j])/k;
                    if(k<=(i-arr[j])%(2*k)){
                        x=false;
                        break;
                    }
                    if(i<=arr[j]+(ch+1)*k && i>=arr[j]+ch) continue;
                    else x=false;
                }
                if(x){
                    ans=i;
                    flag=true;
                    goto z;
                }
            }
            z:;
            if(flag) cout<<ans<<endl;
            else cout<<-1<<endl;
        }
    }
}