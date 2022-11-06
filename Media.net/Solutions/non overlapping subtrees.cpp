#include "bits/stdc++.h"
#define int long long

using namespace std;

struct TrieNode{
    TrieNode* next[2];
    int cnt = 0;
};

void update(int value, int freq, TrieNode* root){
    TrieNode* curr = root;
    for(int i = 30; i >= 0; i--){
        int bit;
        if(value & (1ll << i)){
            if(curr->next[1] == NULL) curr->next[1] = new TrieNode();
            bit = 1;
        }
        else{
            if(curr->next[0] == NULL) curr->next[0] = new TrieNode();
            bit = 0;
        }
        curr = curr->next[bit];
        curr->cnt += freq;
    }
}

int32_t main(){

    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n; cin>>n;
    std::vector<int> nodeValues(n + 1), subtreeSum(n + 1);
    std::vector<std::vector<int>> adj(n + 1);
    
    for(int i = 1; i <= n; i++) cin>>nodeValues[i];
    for(int i = 1; i <= n - 1; i++){
        int a, b; cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    TrieNode* root = new TrieNode();
    
    function<void(int,int)>dfs = [&](int node, int par)->void{
        subtreeSum[node] = nodeValues[node];
        for(auto &child : adj[node]){
            if(child == par) continue;
            dfs(child, node);
            subtreeSum[node] += subtreeSum[child];
        }
        update(subtreeSum[node], 1, root);
    };

    dfs(1, 0);

    int ans = 0;
    function<void(int,int)>compute = [&](int node, int par)->void{
        update(subtreeSum[node], -1, root);
        for(auto &child : adj[node]){
            if(child == par) continue;
            compute(child, node);
        }

        TrieNode* curr = root;
        int value = subtreeSum[node];
        int sum = 0;
        for(int i = 30; i >= 0; i--){
            int bit = (value & (1ll << i)) > 0 ? 1 : 0;
            if(curr->next[bit ^ 1] != NULL && curr->next[bit ^ 1]->cnt > 0){
                sum |= (1ll << i);
                curr = curr->next[bit ^ 1];
            }
            else curr = curr->next[bit];
        }
        ans = max(ans, sum);
    };

    compute(1, 0);

    cout<<ans;


}
