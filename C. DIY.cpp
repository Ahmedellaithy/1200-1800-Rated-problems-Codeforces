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
typedef tree<int, null_type, greater <int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
//template <typename T, typename R> using ordered_map = tree<T, R, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
//double pi = 2*acos(0.0);

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;cin>>n;
    for(int i=0;i<n;i++){
        int x;cin>>x;
        vector<int>v;
        v.push_back(x);
        int cnt=0;
        for(int j=0;j<v.size();j++){
            if(v[j]==0){
                cout<<cnt<<" ";
                break;
            }
            cnt++;
            v.push_back((2*v[j])%32768);
            v.push_back((v[j]+1)%32768);
        }
    }
}