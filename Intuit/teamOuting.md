```cpp
#include "bits/stdc++.h"
#define int long long
#define setbits(x) __builtin_popcountll(x)

using namespace std;

const int inf = 1e18;

int dist[100][100];

int isOddMask(int mask){
    return (mask%2 == 1);
}

bool isBitSet(int mask, int bit){
    int value = (mask & (1ll << bit));
    return value > 0;
}

int solve(int n, int x, int y){
    
    int newSize = n + 2;
    vector<vector<int>>distMask((1ll << newSize), vector<int>(newSize, inf));

    auto getCost = [&](int row, int col)->int{
        return distMask[row][col];
    };

    auto getDistValue = [&](int row, int col)->int{
        return dist[row][col];
    };

    int mask = 0;
    while(mask < (1ll << newSize)){
        if(isOddMask(mask)){
            if(setbits(mask) == 2) {
                if(!isBitSet(mask, newSize - 1)){
                    int j = 1;
                    while(j < (newSize - 1)) {
                        if(isBitSet(mask, j)) {
                            // distMask[mask][j] = v[0][j] + v[j][0]; // correct
                            int distValue = 2 * 1ll * getDistValue(0, j);
                            distMask[mask][j] = distValue; // wrong but according to sample
                        }
                        j++;
                    }
                }
            }
            else{
                int i = 1;
                while(i < newSize - 1) {
                    if(isBitSet(mask, i)){
                        int j = 1;
                        while(j < newSize) {
                            if(i != j && isBitSet(mask, j)){
                                // distMask[mask][j] = min(distMask[mask][j], distMask[mask ^ (1 << j)][i] + v[i][j] + v[j][i]); // correct
                                int distValue = getCost((mask ^ (1ll << j)), i);
                                distValue += 2ll * getDistValue(i, j);
                                distMask[mask][j] = min(getCost(mask, j), distValue); // wrong but according to sample
                            }
                            j++;
                        }
                    }
                    i++;
                }
            }
        }
        mask++;
    }

    vector<long long> dp(newSize, inf);
    dp[0] = 0;
    int i = 1;
    while(i < (newSize - 1)) {
        int mask = 1;
        mask += (1ll << (newSize - 1));
        int j = i;
        while(j) {
            mask ^= (1ll << j);
            int cost = x;
            cost += y * 1ll * getCost(mask, newSize - 1);
            cost += dp[j - 1];
            dp[i] = min(cost, dp[i]);
            j--;
        }
        i++;
    }
    return dp[newSize - 2];

}

int32_t main(){

    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n, x, y; 
    cin>>n>>x>>y;
    for(int i = 0; i <= n + 1; i++){
        for(int j = 0; j <= n + 1; j++){
            cin>>dist[i][j];
        }
    }

    int ans = solve(n, x, y);
    cout<<ans<<"\n";

}
```
