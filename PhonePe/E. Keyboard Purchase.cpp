//https://codeforces.com/contest/1238/problem/E
//submission reference - https://codeforces.com/contest/1238/submission/128483131

#include "bits/stdc++.h"
#define int long long

using namespace std;

const int inf = 1e18;

int32_t main(){

    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n, m; cin>>n>>m;
    string s; cin>>s;
    int mask_size = (1ll << m);

    vector<vector<int>> adj(m + 1, vector<int>(m + 1, 0));
    for(int i = 0; i + 1 < n; i++){
        char a = s[i] - 'a', b = s[i + 1] - 'a';
        if(a == b) continue;
        adj[a][b]++, adj[b][a]++;
    }

    vector<int> dp(mask_size, inf);
    dp[0] = 0;

    for(int mask = 0; mask < mask_size; mask++){
        int position = __builtin_popcountll(mask) + 1;
        for(int nextChar = 0; nextChar < m; nextChar++){
            if(mask & (1ll << nextChar)) continue;
            int newMask = mask | (1 << nextChar);
            int candidate = dp[mask];
            for(int pairChar = 0; pairChar < m; pairChar++){
                int contribution = adj[nextChar][pairChar] * position;
                if((newMask >> pairChar) & 1) candidate += contribution;
                else candidate -= contribution;
            }
            dp[newMask] = min(dp[newMask], candidate);
        }
    }

    int ans = dp[mask_size - 1];
    cout<<ans;

}
