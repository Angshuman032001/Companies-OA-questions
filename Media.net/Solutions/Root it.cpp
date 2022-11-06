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
  vector<int> a(n + 1);
  for(int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  vector<vector<int>> g(n + 1);
  for(int i = 0; i < n - 1; i++) {
    int x, y; cin >> x >> y;
    g[x].push_back(y);
    g[y].push_back(x);
  }

  vector<int> sub(n + 1);
  function<void(int, int)> dfs = [&](int u, int par) -> void {
    for(int child : g[u]) {
      if(child == par) continue;
      dfs(child, u);
      sub[u] = max(sub[u], sub[child]);
    }
    sub[u] += a[u];
  };
  dfs(1, 0);

  vector<int> ans(n + 1);
  function<void(int, int, int)> re_root = [&](int u, int par, int par_ans) -> void {
    ans[u] = max(par_ans + a[u], sub[u]) - a[u];

    vector<int> pref, suff;
    for(int child : g[u]) {
      if(child == par) continue;
      pref.push_back(sub[child]);
      suff.push_back(sub[child]);
    }
    for(int i = 1; i < (int)pref.size(); i++) {
      pref[i] = max(pref[i - 1], pref[i]);
    }
    for(int i = (int)suff.size() - 2; i >= 0; i--) {
      suff[i] = max(suff[i + 1], suff[i]);
    }

    int c_id = 0;
    for(int child : g[u]) {
      if(child == par) continue;
      int nxt = (c_id + 1 < (int)suff.size() ? suff[c_id + 1] : 0);
      int prv = (c_id - 1 >= 0 ? pref[c_id - 1] : 0);
      re_root(child, u, max(par_ans, max(nxt, prv)) + a[u]);
      c_id++;
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
