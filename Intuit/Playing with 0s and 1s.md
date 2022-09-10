## PLAYING WITH 0's and 1's

```
Description
Alice is playing with numbers 0's and 1's. She decided to count the number of subarrays which satisfy the following condition:

Ratio of number of 0's to number of 1's is X:Y 
She starts struggling as soon the count of numbers increase, can you help her find the solution to this problem.

Constraints
1 <= N <= 10^5
1 <= X <= 10^5
1 <= Y <= 10^S

Input Format
The first line contains N, the count of numbers. The numbers contain only 0's and l's The second line contains N space seperated integers (0 or 1)

The third line contains 2 space seperated integers X and Y.

Output Format
Print the count of subarrays which have 0 and 1 in the ratio of X:Y. Output the answer modulo (10^9 + 7).

Sample Input
4
0 1 0 1 
1 1 
Sample Output
4 
Explanation
[0 1] 0 1 
0 [1 0] 1 
0 1 [0 1]
[0 1 0 1] 
```

## Solution :

```cpp
#include "bits/stdc++.h"
#define int long long

using namespace std;

int32_t main(){

    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n; cin>>n;
    vector<int>v(n);
    for(auto &x : v) cin>>x;
    int x, y; cin>>x>>y;

    for(auto &i : v){
        if(i == 0) i = -y;
        else i = x;
    }

    map<int, int>m;
    m[0] = 1;

    int currSum = 0;
    int ans = 0;
    for(auto x : v){
        currSum += x;
        ans += m[currSum];
        m[currSum]++;
    }

    cout<<ans<<"\n";

}
```
