//https://discuss.codechef.com/t/xork-editorial/101866
#include "bits/stdc++.h"
#define int long long

using namespace std;

int getMinLengthSubarray(std::vector<int> &v, int k, int bit){
    int n = v.size();
    vector<int>prefixXor(n + 1);
    for(int i = 0;i<n;i++){
        prefixXor[i + 1] = ((v[i] >> bit) << bit);
    }
    int currXor = 0, ans = n + 1;
    map<int,int>prevIndex;
    for(int i = 1;i<=n;i++){
        currXor ^= prefixXor[i];
        if(currXor == k) ans = min(ans, i);
        if(prevIndex.find(currXor ^ k) != prevIndex.end()) ans = min(ans, i - prevIndex[currXor ^ k]);
        prevIndex[currXor] = i;
    }
    return ans;
}

void solve(){
 
    int n, k; cin>>n>>k;
    vector<int>v(n); 
    for(auto &x : v) cin>>x;

    int ans = getMinLengthSubarray(v, k, 0);
    for(int bit = 30; bit >= 0; bit--){
        if((k >> bit) & 1) continue;
        int curr_k = (((k >> bit) | 1) << bit);
        ans = min(ans, getMinLengthSubarray(v, curr_k, bit));
    }

    cout<<(ans == n + 1 ? -1 : ans)<<"\n";

}

int32_t main(){

    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t; 
    cin>>t;
    while(t--){
        solve();
    }      

}
