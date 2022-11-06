#include "bits/stdc++.h"
using namespace std;
typedef long long int ll;

vector<ll>p={2,3,5,7,11,13,17,19,23,29};
ll getMask(ll n){
    ll mask = 0;
    for(int idx=0;idx<(int)p.size();idx++){
        ll cnt = 0;
        while(n%p[idx]==0){
            n/=p[idx];
            cnt++;
        }
        if(cnt>1)return -1;
        if(cnt)mask|=(1LL<<idx);
    }
    return mask;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll n;
    cin>>n;
    vector<ll>a(n+1);
    for (int i =1; i <=n ; ++i){
        cin>>a[i];
    }
    vector<vector<ll>>dp(n+1,vector<ll>(1LL<<10));
    dp[0][0] = 1;
    ll ans = 0;
    for (int i = 1; i <=n ; ++i){
        ll currentMask = getMask(a[i]);
        for (int mask = 0; mask < (1LL<<10); ++mask){
            dp[i][mask] = dp[i-1][mask];
            if(currentMask!=-1){
                if((mask&currentMask)==currentMask){
                    dp[i][mask]+=dp[i-1][mask^currentMask];
                }
            }
        }
    }
    for (int mask = 0; mask < (1LL<<10); ++mask){
        ans+=dp[n][mask];
    }

    cout<<ans - 1;
    return 0;
}
