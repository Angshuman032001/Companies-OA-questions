/*

Q: Largest Subgrid

Statement: You are given an integer square grid which can be divided into subgrids. The sub-grid sum is obtained by adding all the elements of the subgrid. Determine the maximum size of the square subgrid such that all subgrids of this size must have subgrid-sum less than or equal to maxSum.

Input : 

4 39
1 1 1 1
2 2 2 2
3 3 3 3
4 4 4 4 

Output: 4

*/

#include "bits/stdc++.h"

using namespace std;

int largestSubgrid(vector<vector<int>> &grid, int maxSum){
    int n = grid.size();
    
    std::vector<std::vector<int>> prefSum(n, std::vector<int>(n, 0));

    auto getSum = [&](int row, int col)->int{
        if(row < 0 || col < 0) return 0;
        return prefSum[row][col];
    };  

    auto sumRegion = [&](int row1, int col1, int row2, int col2)->int{
        return getSum(row2, col2) - getSum(row2, col1 - 1) - getSum(row1, col2 - 1) + getSum(row1 - 1, col1 - 1);
    };

    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            prefSum[i][j] = getSum(i - 1, j) + getSum(i, j - 1) + grid[i][j] - getSum(i - 1, j - 1);
        }
    }

    int low = 0, high = n, ans = 0;
    while(low <= high){
        int mid = (low + high) / 2;
        if(mid == 0) return 0;
        bool allSubgridSmall = true;
        for(int i = mid - 1; i < n && allSubgridSmall; i++){
            for(int j = mid - 1; j < n && allSubgridSmall; j++){
                int subgridSum = sumRegion(i - mid + 1, j - mid + 1, i, j);
                if(subgridSum > maxSum){
                    allSubgridSmall = false;
                    break;
                }
            }
        }
        if(allSubgridSmall){
            ans = mid;
            low = mid + 1;
        }
        else high = mid - 1;
    }
    
    return ans;
}

int32_t main(){

    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n; cin>>n;
    int maxSum; cin>>maxSum;
    std::vector<std::vector<int>> grid(n, vector<int>(n, 0));
    
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            cin>>grid[i][j];
        }
    }

    int ans = largestSubgrid(grid, maxSum);
    cout<<ans;

}
