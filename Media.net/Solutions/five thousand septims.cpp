#include "bits/stdc++.h"
#define int long long
#define sz(x) (int)x.size()

using namespace std;

int32_t main(){

    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n; cin>>n;
	std::vector<int> a(n), b(n);
	std::vector<std::vector<int>> costs(10), groupCosts(10);
	std::vector<std::vector<int>> dp(11, vector<int>(5002, 0));

	for(auto &x : a) cin>>x;
	for(auto &x : b) cin>>x;

	for(int i = 0; i < n; i++){
		int digitSum = 0;
		int val = a[i];
		while(val){
			digitSum += val%10;
			val /= 10;
		}
		costs[digitSum%10].push_back(b[i]);
	}

	for(int i = 0; i < 10; i++){
		for(int j = 0; j < sz(costs[i]); j++){
			for(int k = j + 1; k < sz(costs[i]); k++){
				groupCosts[i].push_back(costs[j] + costs[k]);
			}
		}
	}

	int ans = INT_MAX;

	for(int budget = 1; budget <= 5000; budget++){
		for(int i = 0; i < 10; i++){
			if(i >= 1) dp[i][budget] = dp[i - 1][budget];
			for(int j = 0; j < sz(groupCosts[i]); j++){
				if(budget >= groupCosts[i][j]){
					dp[i][budget] = max(dp[i][budget], dp[i - 1][budget - groupCosts[i][j]]);
				}
			}
			if(budget == 5000) ans = min(ans, 5000 - dp[i][budget]);
		}
	}

	cout<<ans;

}
