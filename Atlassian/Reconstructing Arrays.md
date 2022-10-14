![](https://assets.leetcode.com/users/deepakps22/image_1582275537.png)
![](https://assets.leetcode.com/users/deepakps22/image_1582275546.png)
![](https://assets.leetcode.com/users/deepakps22/image_1582275555.png)
![](https://assets.leetcode.com/users/deepakps22/image_1582275564.png)
![](https://assets.leetcode.com/users/deepakps22/image_1582275611.png)
![](https://assets.leetcode.com/users/deepakps22/image_1582275627.png)



## 
```cpp
DP with prefix sums. O(n * m * cost) per query. Space is O(n * m * cost). 
Space can be further optimized to O(m * cost) as only [i-1] matters. Can also be further optimized to use only one prefix dp array. 
dp[i][j][k] represents the number of arrays of size i whose max value is j and total cost is k. cum[i][j][k] = dp[i][1][k] + dp[i][2][k] + ... + dp[i][j][k].

#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

const int MAXN = 55;
const int MAXM = 105;
const int MAXCOST = 55;
const int MOD = 1e9 + 7;

long dp[MAXN][MAXM][MAXCOST];
int cum[MAXN][MAXM][MAXCOST];

int solve(int n, int m, int cost) {
    memset(dp, 0, sizeof(dp));
    memset(cum, 0, sizeof(cum));

    for(int j = 1; j <= m; j++) {
        dp[1][j][0] = 1;
        cum[1][j][0] = j;
    }

    for(int i = 2; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            for(int k = 0; k <= cost; k++) {
                // for arrays ending in 1, 2, 3, ..., j
                dp[i][j][k] = (j * dp[i-1][j][k]);
                dp[i][j][k] %= MOD;
                // for arrays ending in j
                dp[i][j][k] += cum[i-1][j-1][k-1];
                dp[i][j][k] %= MOD;
                cum[i][j][k] = (cum[i][j-1][k] + dp[i][j][k]) % MOD;
            }
        }
    }

    return cum[n][m][cost];
}

int main() {
    int q;
    cin >> q;
    vector<int> m(q), n(q), cost(q);
    for(int i = 0; i < q; i++) {
        cin >> n[i];
    }
    cin >> q;
    for(int i = 0; i < q; i++) {
        cin >> m[i];
    }
    cin >> q;
    for(int i = 0; i < q; i++) {
        cin >> cost[i];
    }
    for(int i = 0; i < q; i++) {
        cout << solve(n[i], m[i], cost[i]) << '\n';
    }

    return 0;
}
```
