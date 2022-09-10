## Statement

![](https://assets.leetcode.com/users/images/993cb79a-7871-42cc-9971-daac95f8bc3e_1662785305.9158816.jpeg)
![](https://assets.leetcode.com/users/images/09476c64-c9ce-4325-969f-db6706aa8d10_1662785279.5332432.jpeg)
![](https://assets.leetcode.com/users/images/3c44acee-fdc8-4e91-bb1d-1a38c3fa63dd_1662785191.0316675.jpeg)


## Solution
```cpp
#include "bits/stdc++.h"
#define int long long
#define sz(x) (int)x.size()

using namespace std;

const int inf = 1e9;

bool isSubset(int requiredMask, int currMask){
	int andValue = (requiredMask & currMask);
	return (andValue == requiredMask);
}

int solve(int index, int currMask, int requiredMask, vector<int> &bookCost, vector<int> &bookMaskValue, std::vector<std::vector<int>> &dp){
	if(isSubset(requiredMask, currMask)) return 0;
	if(index == sz(bookCost)){
		return inf;
	}

	int &ans = dp[index][currMask];
	if(ans != -1) return ans;
	ans = inf;

	ans = solve(index + 1, currMask, requiredMask, bookCost, bookMaskValue, dp);
	ans = min(ans, bookCost[index] + solve(index + 1, (currMask | bookMaskValue[index]), requiredMask, bookCost, bookMaskValue, dp));

	return ans;

}

int32_t main(){

    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n, m; cin>>n>>m;
    int k; cin>>k;
    vector<int> requiredSkills, haveSkills;
    vector<int>bookMaskValue(m);
    int requiredMask = 0, haveMask = 0;
    for(int i = 0; i < k; i++){
    	int skill; cin>>skill;
    	requiredSkills.push_back(skill);
    	requiredMask |= (1ll << skill);
    }

    int skillsOwned; 
    cin>>skillsOwned; 

    for(int i = 0; i < skillsOwned; i++){
    	int skill; cin>>skill;
    	haveSkills.push_back(skill);
    	haveMask |= (1ll << skill);
    }

    vector<int>bookCost(m);
    for(auto &x : bookCost) cin>>x;
    
    for(int i = 0; i < m; i++){
    	int cnt; cin>>cnt;
    	int maskValue = 0;
    	for(int j = 0; j < cnt; j++){
    		int skill; cin>>skill;
    		maskValue |= (1ll << skill);
    	}
    	bookMaskValue[i] = maskValue;
    }

    vector<vector<int>>dp(m, vector<int>((1ll << (n + 1)), -1));

    int ans = solve(0, haveMask, requiredMask, bookCost, bookMaskValue, dp);
    if(ans > 1e5) ans = -1;
    cout<<ans;

}
```
