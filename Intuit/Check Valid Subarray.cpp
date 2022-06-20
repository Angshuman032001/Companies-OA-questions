/*

Question: Given an array arr[] containing N integers and there are Q queries where each query consists of a range [L, R]. The task is to find whether all the elements from the given index range have even frequency or not.
Constraints: Q <= 10^5

Solution: Create prefix xor array and also keep a count of zeroes in a particular subarray
for eg: subarray is {1, 0, 1}, prefix xor is zero but the subarray is not valid

*/


#include "bits/stdc++.h"

using namespace std;

int32_t main(){

    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n; cin>>n;
    vector<int>v(n), prefixXor(n + 1), zeroCount(n + 1);
    for(auto &x : v) cin>>x;
    
    for(int i = 0;i<n;i++){
        prefixXor[i + 1] = v[i] ^ prefixXor[i];
        zeroCount[i + 1] = (v[i] == 0) + zeroCount[i];
    }

    int q; cin>>q;
    while(q--){
        int l, r; cin>>l>>r;
        int subarray_xor = prefixXor[r] ^ prefixXor[l - 1];
        int subarray_zero_count = zeroCount[r] - zeroCount[l - 1];
        if(subarray_xor == 0 && subarray_zero_count%2 == 0) cout<<"VALID\n";
        else cout<<"INVALID\n";
    }

}
