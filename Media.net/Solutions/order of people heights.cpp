#include "bits/stdc++.h"
#define int long long

using namespace std;

struct BIT{
    int N;
    vector<int>bit;
    
    void init(int _n){
        N = _n;
        bit.resize(N + 1);
    }
    
    void update(int index, int value){
        while(index <= N){
            bit[index] += value;
            index += (index & -index);
        }
    }
    
    int pref(int index){
        int sum = 0;
        while(index > 0){
            sum += bit[index];
            index -= (index & -index);
        }
        return sum;
    }
};


int32_t main(){

    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

 	int n; cin>>n;
 	std::vector<int> heights(n), infronts(n);
 	std::vector<std::vector<int>> v(n);
 	
 	for(auto &x : heights) cin>>x;
 	for(auto &x : infronts) cin>>x;

 	for(int i = 0; i < n; i++){
 		v[i].push_back(heights[i]);
 		v[i].push_back(infronts[i]);
 	}

 	sort(v.begin(), v.end(), [&](auto &x, auto &y)->bool{
 	   	return x[0] < y[0];                              
 	});

 	BIT bit;
 	bit.init(n + 1);
 	
 	for(int i = 2; i <= n; i++) bit.update(i, 1);
 	
 	std::vector<std::vector<int>> ans(n);

 	for(int i = 0; i < n; i++){
 		int low = 1, high = n, index = -1;
 		while(low <= high){
 			int mid = (low + high) / 2;
 			int emptySlots = bit.pref(mid);
 			if(emptySlots < v[i][1]) low = mid + 1;
 			else{
 				index = mid;
 				high = mid - 1;
 			}
 		}
 		ans[index - 1] = v[i];
 		bit.update(index, -1);
 	}

 	for(auto x : ans) cout<<x[0]<<" ";

}
