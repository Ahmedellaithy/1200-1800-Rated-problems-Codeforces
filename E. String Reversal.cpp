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

int freq[30];

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;cin>>n;
    string s;cin>>s;
    string cmp=s;
    reverse(cmp.begin(),cmp.end());
    map<pair<char,int>,int>mp;
    for(int i=0;i<n;i++){
        freq[cmp[i]]++;
        mp[{cmp[i],freq[cmp[i]]}]=i+1;
    }
    vector<int>v(n);
    for(char i='a';i<='z';i++) freq[i]=0;
    for(int i=0;i<n;i++){
        freq[s[i]]++;
        v[i]=(mp[{s[i],freq[s[i]]}]);
    }
    ordered_set os;
    int ans=0;
    for(int i=0;i<n;i++){
        ans+=os.order_of_key(v[i]);
        os.insert(v[i]);
    }
    cout<<ans;
}