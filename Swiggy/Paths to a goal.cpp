/*

Question: Paths to a goal

Statement: Given a number line from 0 to n and a string denoting a sequence of moves, determing the number of subsequences of those moves that lead from a given point x to end at another point y. Moves will be given as a sequence of l and r instructions. An instruction l = left movement, so from position j the new position is j - 1, an an instruction r = right movement, so from position j the new position would be j + 1.
Complete the function distinctMoves which must return an integer that represents the number of distinct subsequences. As this number may be large, return the value modulo 10^9 + 7.

distinctMoves has the following parameter(s):
s : a string that represents a sequence of moves
n : an integer that represents the upper bound of the number line
x : an integer that represents the starting point
y : an integer that represents the ending point

1 <= |s| <= 10^3
0<= x, y, n <= 2500

Sample Case:
INPUT:
rrlrlr
6
1
2
OUTPUT:
7

https://leetcode.com/discuss/interview-question/881527/Paths-to-a-Goal-%3A-Hackerrank/723011

*/

#include "bits/stdc++.h"

using namespace std;

const int mod = 1e9 + 7;

inline int add(int x, int y){
    x += y;
    if (x >= mod) return x - mod;
    return x;
}

inline int sub(int x, int y){
    x -= y;
    if (x < 0) return x + mod;
    return x;
}

int distinctMoves(string &s, int n, int from, int to){
    int m = s.length();
    vector<int>prevSame(m);
    int indexL = -1, indexR = -1;
    for(int i = 0;i<m;i++){
        if(s[i] == 'l'){
            prevSame[i] = indexL;
            indexL = i;
        }
        else{
            prevSame[i] = indexR;
            indexR = i;
        }
    }

    std::vector<std::vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    dp[0][from] = 1;
    for(int i = 1;i<=m;i++){
        for(int j = 0;j<=n;j++){
            dp[i][j] = dp[i - 1][j];
            if(s[i - 1] == 'l'){
                if(j + 1 <= n) dp[i][j] = add(dp[i][j], dp[i - 1][j + 1]);
                if(j + 1 <= n && prevSame[i - 1] >= 0) dp[i][j] = sub(dp[i][j], dp[prevSame[i - 1] + 1 - 1][j + 1]);
            }
            else{
                if(j - 1 >= 0) dp[i][j] = add(dp[i][j], dp[i - 1][j - 1]);
                if(j - 1 >= 0 && prevSame[i - 1] >= 0) dp[i][j] = sub(dp[i][j], dp[prevSame[i - 1] + 1 - 1][j - 1]);
            }
        }
    }

    return dp[m][to];

}

int32_t main(){

    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    string s; cin>>s;
    int n, x, y; cin>>n>>x>>y;
    int ans = distinctMoves(s, n, x, y);
    cout<<ans;
}
