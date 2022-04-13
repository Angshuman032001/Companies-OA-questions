//https://leetcode.com/problems/paint-house-iii/

const int inf = 1e7;

class Solution {
public:
    int dp[101][101][21];
    int solve(int index, int target, int prevCol, vector<int> &houses, vector<vector<int>> &cost){
        if(index >= houses.size() || target < 0){
            return (target == 0 ? 0 : inf);
        }
        if(houses[index] != 0) return solve(index + 1, target - (houses[index] != prevCol), houses[index], houses, cost);
        int &ans = dp[index][target][prevCol];
        if(ans != -1) return ans;
        ans = inf;
        for(int currCol = 1;currCol<=cost[index].size(); currCol++){
            ans = min(ans, cost[index][currCol - 1] + solve(index + 1, target - (prevCol != currCol), currCol, houses, cost));
        }
        return ans;
    }
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        memset(dp, -1, sizeof(dp));
        int ans = solve(0, target, 0, houses, cost);
        return (ans >= inf ? -1 : ans);
    }
};
