#include "bits/stdc++.h"
using namespace std;
#define int long long

#ifdef LOCAL
#include "prettyprint.h"
#else 
#define deb(...)
#endif

void solve() {
  int n; cin >> n;

  vector<vector<int>> g(n + 1);
  set<pair<int, int>> edges;
  for(int i = 0; i < n - 1; i++) {
    int x, y; cin >> x >> y;
    edges.insert(make_pair(x, y));
    g[x].push_back(y);
    g[y].push_back(x);
  }

  auto from_u_to_v = [&](int u, int v) -> bool {
    return (edges.find(make_pair(u, v)) != edges.end());
  };

  vector<int> sub(n + 1);
  function<void(int, int)> dfs = [&](int u, int par) -> void {
    for(int child : g[u]) {
      if(child == par) continue;
      dfs(child, u);
      sub[u] += sub[child] + !from_u_to_v(u, child);
    }
  };

  dfs(1, 0);

  vector<int> ans(n + 1);
  function<void(int, int, int)> re_root = [&](int u, int par, int par_ans) -> void {
    ans[u] = sub[u] + par_ans;
    for(int child : g[u]) {
      if(child == par) continue;
      int minus_subtree = sub[u] - (sub[child] + !from_u_to_v(u, child));
      re_root(child, u, par_ans + minus_subtree + from_u_to_v(u, child));
    }
  };

  re_root(1, 0, 0);
  for(int i = 1; i <= n; i++) {
    cout << ans[i] << " " ;
  }
  cout << "\n";

}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int t = 1;
  for (int tt = 1; tt <= t; tt++) {
    solve();
  }
}
