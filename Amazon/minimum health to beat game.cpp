/*minimum health to beat game*/
/*https://walkccc.me/LeetCode/problems/2214/*/

/*

1. player needs to play the rounds sequentially
2. player loses damage[i] playing ith round
3. player's health must be greater than 0 at all times
4. player can choose to use armour in any one round. The armour will prevent damage of min(armour, damage[i])


Find min starting health to finish the game

*/

#include "bits/stdc++.h"

using namespace std;

int32_t main(){

    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n, armour; cin>>n>>armour;
    vector<int>damage(n);
    for(auto &x : damage) cin>>x;

    long long sum = accumulate(damage.begin(), damage.end(), 0ll);
    int maxDamage = *max_element(damage.begin(), damage.end());

    long long ans = 1ll + sum - min(armour, maxDamage);
    cout<<ans;

}
