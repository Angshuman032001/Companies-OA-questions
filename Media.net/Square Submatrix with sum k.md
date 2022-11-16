```cpp
#include "bits/stdc++.h"

using namespace std;

int32_t main(){

    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n, m; cin>>n>>m;
    int k; cin>>k;
    
    std::vector<std::vector<int>> v(n, vector<int> (m, 0)), prefSum(n, std::vector<int> (m, 0));
    vector<pair<int, int>> startCells;
    
    for(int j = 0; j < m; j++) startCells.push_back(make_pair(0, j));
    for(int i = 1; i < n; i++) startCells.push_back(make_pair(i, 0));

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin>>v[i][j];
            prefSum[i][j] = v[i][j];
            if(i - 1 >= 0) prefSum[i][j] += prefSum[i - 1][j];
            if(j - 1 >= 0) prefSum[i][j] += prefSum[i][j - 1];
            if(i - 1 >= 0 && j - 1 >= 0) prefSum[i][j] -= prefSum[i - 1][j - 1];
        }
    }

    auto get2DSum = [&](pair<int, int> start, pair<int, int> end)->int{
        int sum = prefSum[end.first][end.second];
        if(start.second - 1 >= 0) sum -= prefSum[end.first][start.second - 1];
        if(start.first - 1 >= 0) sum -= prefSum[start.first - 1][end.second];
        if(start.first - 1 >= 0 && start.second - 1 >= 0) sum += prefSum[start.first - 1][start.second - 1];
        return sum;
    };

    auto canGo = [&](pair<int, int> cell){
        return (cell.first + 1 < n && cell.second + 1 < m);
    };

    auto check = [&](pair<int, int> &startCell, pair<int, int> &endCell)->bool{
        int sum = get2DSum(startCell, endCell);
        while(canGo(endCell)){
            endCell.first++, endCell.second++;
            sum = get2DSum(startCell, endCell);
            while(sum > k){
                startCell.first++, startCell.second++;
                sum = get2DSum(startCell, endCell);
            }
            if(sum == k) return true;
        }
        return sum == k;
    };

    for(auto &startCell : startCells){
        pair<int, int> endCell = startCell;
        if(check(startCell, endCell)){
            cout<<startCell.first<<" "<<startCell.second<<endl;
            cout<<endCell.first<<" "<<endCell.second<<endl;
        }
    }

    return 0;

}
```
