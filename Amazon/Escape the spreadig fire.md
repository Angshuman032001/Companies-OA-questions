https://leetcode.com/problems/escape-the-spreading-fire/

You are given a 0-indexed 2D integer array grid of size m x n which represents a field. Each cell has one of three values:

0 represents grass,
1 represents fire,
2 represents a wall that you and fire cannot pass through.
You are situated in the top-left cell, (0, 0), and you want to travel to the safehouse at the bottom-right cell, (m - 1, n - 1). Every minute, you may move to an adjacent grass cell. After your move, every fire cell will spread to all adjacent cells that are not walls.

Return the maximum number of minutes that you can stay in your initial position before moving while still safely reaching the safehouse. If this is impossible, return -1. If you can always reach the safehouse regardless of the minutes stayed, return 109.

Note that even if the fire spreads to the safehouse immediately after you have reached it, it will be counted as safely reaching the safehouse.

A cell is adjacent to another cell if the former is directly north, east, south, or west of the latter (i.e., their sides are touching).

```c++
class Solution {
private:
    int dx[4] = {-1,0,1,0};
    int dy[4] = {0,1,0,-1};    
public:
    
    bool isValid(int row, int col, int n, int m){
        return (row >= 0 && row < n && col >= 0 && col < m);
    }
    
    vector<vector<int>> getMinTime(vector<vector<int>> &grid, int n, int m){
        
        vector<vector<int>>minTime(n, vector<int>(m, -1));
        
        queue<pair<int,int>>q;
        
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(grid[i][j] == 2) minTime[i][j] = INT_MAX;
                else if(grid[i][j] == 1){
                    q.push(make_pair(i, j));
                    minTime[i][j] = 0;
                }
            }
        }
        
        while(!q.empty()){
            auto[row, col] = q.front();
            q.pop();
            for(int dir = 0;dir<4;dir++){
                int newRow = row + dx[dir], newCol = col + dy[dir];
                if(isValid(newRow, newCol, n, m) && minTime[newRow][newCol] == -1){
                    minTime[newRow][newCol] = minTime[row][col] + 1;
                    q.push(make_pair(newRow, newCol));
                }
            }
        }
        
        return minTime;
    }
    
    bool check(vector<vector<int>> &minTime, int n, int m, int time){
        bool canReach = false;
        queue<pair<int,int>>q;
        q.push(make_pair(0, 0));
        vector<vector<bool>>visited(n, vector<bool>(m, false));
        visited[0][0] = true;
        while(!q.empty() && !canReach){
            int sz = q.size();
            while(sz--){
                auto[row, col] = q.front();
                q.pop();
                if(row == n - 1 && col == m - 1 && (minTime[row][col] == -1 || minTime[row][col] >= time)){
                    canReach = true;
                    break;
                }
                if((minTime[row][col] <= time && minTime[row][col] != -1) || minTime[row][col] == INT_MAX) continue;
                for(int dir = 0;dir<4;dir++){
                    int newRow = row + dx[dir], newCol = col + dy[dir];
                    if(isValid(newRow, newCol, n, m) && minTime[newRow][newCol] != INT_MAX && !visited[newRow][newCol]){
                        visited[newRow][newCol] = true;
                        q.push(make_pair(newRow, newCol));
                    }
                }
            }
            time++;
        }
        return canReach;
    }
    
    int getMaxMinutes(vector<vector<int>> &minTime, int n, int m){
        int low = 0, high = n * m, maxTime = -1;
        while(low <= high){
            int mid = (low + high) / 2;
            if(check(minTime, n, m, mid)){
                maxTime = mid;
                low = mid + 1;
            }
            else high = mid - 1;
        }
        return maxTime >= n * m ? 1e9 : maxTime;
    }
    
    int maximumMinutes(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>>minTime = getMinTime(grid, n, m);
        int maxMinutes = getMaxMinutes(minTime, n, m);
        return maxMinutes;
    }
};
```
