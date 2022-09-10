```cpp
#include "bits/stdc++.h"
#define int long long

using namespace std;

const int mod = 1003;
const int N = 101;

int dp[N][N][2];
int n; 
string s;

inline int add(int x, int y){
    x += y;
    if (x >= mod) return x - mod;
    return x;
}

inline int mul(int x, int y){
    return (x%mod * 1ll * y%mod) % mod;
}

bool isOperator(char c){
	return (c == '&' || c == '|' || c == '^');
}

int solve(int start, int end, int flag){
	if(start > end) return 0;
	if(start == end){
		if(flag) return (s[start] == 'T');
		else return (s[start] == 'F');
	}

	int &ans = dp[start][end][flag];
	if(ans != -1) return ans;

	ans = 0;
	for(int i = start + 1; i <= end - 1; i++){
		if(isOperator(s[i])){
			
			vector<int> left(2), right(2);
			
			left[1] = solve(start, i - 1, 1);
			left[0] = solve(start, i - 1, 0);
			right[1] = solve(i + 1, end, 1);
			right[0] = solve(i + 1, end, 0);

			for(int k = 0; k <= 1; k++){
				for(int l = 0; l <= 1; l++){
					if(s[i] == '&'){
						if((k & l) == flag) ans = add(ans, mul(left[k], right[l]));
					}
					else if(s[i] == '|'){
						if((k | l) == flag) ans = add(ans, mul(left[k], right[l]));
					}
					else if(s[i] == '^'){
						if((k ^ l) == flag) ans = add(ans, mul(left[k], right[l]));
					}
				}
			}

		}

	}

	return ans;

}

int32_t main(){

    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);


    memset(dp, -1, sizeof(dp));
    
    cin>>n;
    cin>>s;
    int ans = solve(0, n - 1, 1);
    cout<<ans<<"\n";

}
```
