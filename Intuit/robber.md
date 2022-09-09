## Brute

```cpp
void solve(){

    int n; cin>>n;
    int r; cin>>r;
    vector<int>coins(n + 1);
    vector<vector<int>> adj(n + 1);
    vector<int> parent(n + 1, 0), robberTime(n + 1, inf), policeTime(n + 1, 0);
    rep(i, 1, n + 1) cin>>coins[i];

    rep(i, 0, n - 1){
        int a, b; cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    vector<int>leafNodes;
    rep(i, 1, n + 1){
        if(sz(adj[i]) == 1 && i != 1) leafNodes.pb(i);
    }

    function<void(int, int, int)>dfs1 = [&](int node, int par, int lvl){
        parent[node] = par;
        policeTime[node] = lvl;
        for(auto child : adj[node]){
            if(child != par) dfs1(child, node, lvl + 1);
        }
    };

    dfs1(1, 0, 0);

    int curr = r;
    int time = 0;
    while(curr != 0){
        robberTime[curr] = time++;
        curr = parent[curr];
    }

    int ans = -inf;
    for(int leaf : leafNodes){
        int points = 0;
        int curr = leaf;
        while(curr != 0){
            if(policeTime[curr] < robberTime[curr]){
                points += coins[curr];
            }
            else if(policeTime[curr] == robberTime[curr]){
                if(coins[curr] < 0){
                    points += (coins[curr] - 1) / 2;
                }
                else points += coins[curr] / 2;
            }
            curr = parent[curr];
        }
        ans = max(ans, points);
    }

    cout<<ans<<nl;
}

```


## Efficient

```cpp
void solve(){

    int n, r; cin>>n>>r;
    vector<int>coins(n + 1);
    vector<vector<int>> adj(n + 1);
    vector<int> parent(n + 1, 0), robberTime(n + 1, inf), policeTime(n + 1, 0), dp(n + 1, -inf), tin(n + 1, 0), tout(n + 1, 0);
    int timer = 0;
    rep(i, 1, n + 1) cin>>coins[i];

    rep(i, 0, n - 1){
        int a, b; cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }   

    function<void(int, int, int)>dfs1 = [&](int node, int par, int lvl){
        parent[node] = par;
        policeTime[node] = lvl;
        tin[node] = timer++;
        int cntChild = 0;
        int mx = -inf;
        for(auto child : adj[node]){
            if(child != par){
                dfs1(child, node, lvl + 1);
                cntChild++;
                mx = max(mx, dp[child]);
            }
        }
        if(cntChild == 0) dp[node] = coins[node];
        else dp[node] = mx + coins[node];
        tout[node] = timer++;
    };

    dfs1(1, 0, 0);

    int curr = r;
    int time = 0;
    while(curr != 0){
        robberTime[curr] = time++;
        curr = parent[curr];
    }

    auto isInSubtree = [&](int root, int node)->bool{
        return tin[root] <= tin[node] && tout[root] >= tout[node];
    };

    int ans = -inf;
    function<void(int,int,int)>dfs2 = [&](int node, int par, int sum){
        int mx = -inf;
        int cntChild = 0;
        for(auto child : adj[node]){
            if(child != par && !isInSubtree(child, r)){
                mx = max(mx, dp[child]);
                cntChild++;
            }
        }
        int currScore = 0;
        if(policeTime[node] < robberTime[node]) currScore = coins[node];
        else if(policeTime[node] == robberTime[node]){
            if(coins[node] > 0) currScore += coins[node] / 2;
            else currScore += (coins[node] - 1) / 2;
        }

        if(cntChild > 0){
            ans = max(ans, sum + mx + currScore);
        }
        else if(sz(adj[node]) == 1 && node != 1){ 
            ans = max(ans, sum + currScore);
        }
        for(auto child : adj[node]){
            if(child != par) dfs2(child, node, sum + currScore);
        }
    };

    dfs2(1, 0, 0);

    cout<<ans<<nl;
}
```
