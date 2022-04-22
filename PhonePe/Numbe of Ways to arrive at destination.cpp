//https://leetcode.com/problems/number-of-ways-to-arrive-at-destination/
const int mod = 1e9 + 7;

using ll = long long;

class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>>adj(n);
        for(auto x : roads){
            adj[x[0]].push_back(make_pair(x[1], x[2]));
            adj[x[1]].push_back(make_pair(x[0], x[2]));
        }
        
        //min cost to reach that node and ways to reach that node
        vector<pair<ll, ll>>dp(n, {1e15, 0});
        dp[0] = make_pair(0, 1);

        priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>>>pq;
        pq.push(make_pair(0, 0));
        while(!pq.empty()){
            auto f = pq.top();
            pq.pop();
            ll cost = f.first, node = f.second;
            for(auto child : adj[node]){
               ll nextNode = child.first, wt = child.second;
               if(dp[nextNode].first > cost + wt){
                   dp[nextNode] = make_pair(cost + wt, dp[node].second);
                   pq.push(make_pair(cost + wt, nextNode));
               }
               else if(dp[nextNode].first == cost + wt){
                   dp[nextNode].second += dp[node].second;
                   dp[nextNode].second %= mod;
               }
           }
        }
        
        return dp[n - 1].second;
        
    }
};
