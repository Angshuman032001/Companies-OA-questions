![Uber OA](https://assets.leetcode.com/users/images/2a211a3b-6fdf-45b0-9516-0311bf944e43_1660460470.1669102.png)

https://codeforces.com/contest/1624/problem/G

```cpp
#include "bits/stdc++.h"
#define int long long

using namespace std;

struct UF {
    int N;
    std::vector<int> e;
    void init(int n){
        e.assign(n,-1);
    }
    bool sameSet(int a, int b) { return find(a) == find(b); }
    int size(int x) { return -e[find(x)]; }
    int find(int x) { return e[x] < 0 ? x : e[x] = find(e[x]); }
    bool join(int a, int b) {
        a = find(a), b = find(b);
        if (a == b) return false;
        if (e[a] > e[b]) swap(a, b);
        e[a] += e[b]; e[b] = a;
        return true;
    }
};

void solve(){
 
    int n, m; cin>>n>>m;
    std::vector<array<int, 3>> edges(m);
    for(int i = 0;i<m;i++){
        for(int j = 0;j<3;j++){
            cin>>edges[i][j];
        }
    }

    int mask = (1ll << 31) - 1;
    for(int bit = 30;bit>=0;bit--){
        int curr = mask ^ (1ll << bit);
        UF dsu;
        dsu.init(n + 1);
        int components = n;
        for(auto x : edges){
            if((curr & x[2]) == x[2]){
                components -= dsu.join(x[0], x[1]);
            }
        }

        if(components == 1) mask = curr;
    }

    cout<<mask<<"\n";

}

int32_t main(){

    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t; 
    cin>>t;
    while(t--){
        solve();
    }      

}
