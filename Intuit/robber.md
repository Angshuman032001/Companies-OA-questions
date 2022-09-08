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

    int ans = 0;
    for(int leaf : leafNodes){
        int points = 0;
        int curr = leaf;
        while(curr != 0){
            if(policeTime[curr] < robberTime[curr]){
                points += coins[curr];
            }
            else if(policeTime[curr] == robberTime[curr]){
                points += coins[curr] / 2;
            }
            curr = parent[curr];
        }
        if(points == 64) deb(leaf);
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
    vector<int> parent(n + 1, 0), robberTime(n + 1, inf), policeTime(n + 1, 0), dp(n + 1, 0), tin(n + 1, 0), tout(n + 1, 0);
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
        dp[node] = coins[node];
        tin[node] = timer++;
        for(auto child : adj[node]){
            if(child != par){
                dfs1(child, node, lvl + 1);
                dp[node] = max(dp[node], coins[node] + dp[child]);
            }
        }
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

    int ans = 0;
    for(auto child : adj[1]){
        if(!isInSubtree(child, r)) ans = max(ans, dp[child]);
    }

     function<void(int,int,int)>dfs2 = [&](int node, int par, int sum){
        int mx = 0;
        for(auto child : adj[node]){
            if(child != par && !isInSubtree(child, r)){
                mx = max(mx, dp[child]);
            }
        }
        int currScore = 0;
        if(policeTime[node] < robberTime[node]) currScore = coins[node];
        else if(policeTime[node] == robberTime[node]) currScore = coins[node] / 2;
        ans = max(ans, sum + mx + currScore);
        for(auto child : adj[node]){
            if(child != par) dfs2(child, node, sum + currScore);
        }
    };    
    
    dfs2(1, 0, 0);

    cout<<ans<<nl;
}

```
