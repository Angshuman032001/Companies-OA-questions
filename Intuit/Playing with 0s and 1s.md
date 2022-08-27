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
#include<bits/stdc++.h>
using namespace std;


int n,x,y;
vector<int> a;
vector<long long> prefix;
map<long long,int> mp;


int main(){

   cin>>n;
   a.resize(n);
   for(int i=0;i<n;i++){
      cin>>a[i];
   }
   cin>>x>>y;
   for(int i=0;i<n;i++)
   if(a[i]==0)a[i]=y;
   else a[i]=x;

    prefix.resize(n+1);
    prefix[0]=0;
    for(int i=0;i<n;i++)
    prefix[i+1]=prefix[i]+a[i];

    for(int i=0;i<n;i++){
        mp[prefix[i]]++;
    }

    long long ans=0;

    for(auto &c:mp){
        ans+=(long long)c.second*(c.second-1)/2;
    }

    cout<<ans<<endl;

    return 0;
}
```
