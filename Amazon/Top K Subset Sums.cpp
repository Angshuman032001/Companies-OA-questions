#include "bits/stdc++.h"
#define int long long
#define sz(x) (int)x.size()

using namespace std;

std::vector<int> topKSubsetSum(std::vector<int> &v, int n, int k){
    int positiveSum = 0;
    std::vector<int> ans, out;
    for(auto x : v){
        if(x > 0) positiveSum += x;
    }

    vector<int>temp = v;
    for(auto &x : temp) x = abs(x);

    sort(temp.begin(), temp.end());

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq;
    pq.push(make_pair(temp[0], 0));

    while(!pq.empty() && sz(out) < k - 1){
        auto f = pq.top();
        int value = f.first, index = f.second;
        pq.pop();
        out.push_back(value);
        if(index + 1 < n){
            pq.push(make_pair(value + temp[index + 1], index + 1));
            pq.push(make_pair(value - temp[index] + temp[index + 1], index + 1));
        }
    }

    ans.push_back(positiveSum);
    for(auto x : out) ans.push_back(positiveSum - x);

    return ans;

}

int32_t main(){

    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n, k; cin>>n>>k;
    std::vector<int> v(n); 
    for(auto &x : v) cin>>x;

    auto ans = topKSubsetSum(v, n, k);
    for(auto x : ans) cout<<x<<" ";

}
