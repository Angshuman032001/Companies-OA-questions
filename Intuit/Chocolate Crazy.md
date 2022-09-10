## Recursive (My version)

```cpp
#include "bits/stdc++.h"
#define int long long
#define sz(x) (int)x.size()

using namespace std;

const int N = 1e5 + 100, inf = 1e17;

std::vector<bool> isPrime;
std::vector<int> distSkip(N), mines;
vector<bool> isMine(N);
vector<vector<int>>dp(N, vector<int>(70, -1));
int n, l, m;

void sieve(int n) {
    isPrime.assign(n + 1,true);
    isPrime[0] = isPrime[1] = false;
    for(int i = 2; i <= n; i++) {
        if(isPrime[i]) {
            for(int j = i * i; j <= n;j += i){
                if(isPrime[j]) {
                    isPrime[j] = false;
                }
            }
        }
    }
}

void precompute(){

    for(auto &x : mines) isMine[x] = true;
    int lastPrime = 2, cnt = 1;
    for(int currPrime = 3; currPrime < N; currPrime++){
        if(isPrime[currPrime]){
            distSkip[lastPrime] = (cnt - 1 + currPrime - lastPrime)%9;
            distSkip[lastPrime] = (distSkip[lastPrime] == 0 ? 9 : distSkip[lastPrime]);
            cnt++;
            lastPrime = currPrime;
        }
    }

}

int solve(int index, int minNormalMoves){
    if(index == n){
        return 0;
    }
    if(isMine[index]) return inf;
    if(index > n) return inf;
    int &ans = dp[index][minNormalMoves];
    if(ans != -1) return ans;
    ans = inf;
    int rem = max(minNormalMoves - 1, 0ll);
    ans = 1 + solve(index + 1, rem);
    ans = min(ans, 1 + solve(index + 2, rem));
    if(isPrime[index] && minNormalMoves == 0){
        ans = min(ans, 1 + solve(index + distSkip[index], l));
    }
    return ans;
}

int32_t main(){

    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);


    cin>>n>>l>>m;
    for(int i = 0; i < m; i++){
        int x; cin>>x;
        mines.push_back(x);
    }

    sieve(N);
    precompute();

    if(isMine[1] || isMine[n]){
        cout<<-1;
        return 0;
    }

    int ans = solve(1, 0);
    cout<<(ans > n ? -1 : ans);
}
```


## Iterative (Abhinab version)

```cpp
#include<bits/stdc++.h>
using namespace std;

int f(int n, int l, vector<int> v) {
    int mxN = n + 1000;
    vector<vector<int>> dp(n + 100, vector<int>(l + 1, n + 1));
    vector<int> primes(mxN, 1), cnt(mxN, -1), mines(n + 1);
    for(auto i : v) mines[i] = 1;
    if(mines[1] || mines[n]) return -1;
    primes[0] = primes[1] = 0;
    for(int i = 2; i < mxN; ++i) {
        if(primes[i]) {
            for(int j = 2 * i; j < mxN; j += i) {
                primes[j] = 0;
            }
        }
    }
    int last = 2, c = 1;
    for(int i = 3; i < mxN; ++i) {
        if(primes[i]) {
            cnt[last] = c - 1 + i - last;
            ++ c;
            cnt[last] %= 9;
            if(cnt[last] == 0) cnt[last] = 9;
            last = i;
        }
    }
    for(int i = 0; i <= l; ++i) dp[n][i] = 0;
    for(int i = n - 1; i; --i) {
        if(mines[i]) continue;
        for(int j = 0; j <= l; ++j) {
            int x = max(j - 1, 0);
            dp[i][j] = 1 + min(dp[i + 1][x], dp[i + 2][x]);
        }
        if(primes[i]) {
            if(i + cnt[i] > n) continue;
            dp[i][0] = min(dp[i][0], 1 + dp[i + cnt[i]][l]);
        }
    }
    int ans = n + 1;
    for(int i = 0; i <= l; ++i) ans = min(ans, dp[1][i]);
    if(ans > n) ans = - 1;
    return ans;
}

int main () {
    
    int n, l, m;
    cin >> n >> l >> m;
    vector<int> v(m);
    for(auto &i : v) cin >> i;
    cout << f(n, l, v);

    return 0;
}
```
