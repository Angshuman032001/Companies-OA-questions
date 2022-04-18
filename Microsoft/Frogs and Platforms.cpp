/*
https://leetcode.com/discuss/interview-question/1954161/Microsoft-Online-Assessment

There are some platforms and there are two frogs sharing the same platform. On their left and on their right, there might be other platforms, some are higher and others as lower. The two frogs had a fight with each other and then decided to go far apart from each other as much as possible. But they can only change platforms under certain conditions: they can only go to adjacent platforms, and they can only jump to platforms that have the same height or greater height than the platform they currently are.

Write a program that finds out the furthest they can be from each other, considering they start on the platform that will make it possible for them to go the furthest apart. The distance is the difference between the platforms positions + 1.

The input is an array of integers, describing the height of the platforms. Maximum length is 100,000.

For input '[5,4,3,2,1,2,3,3,5]'

The best would be for the frogs to start at the platform of height 1, and then one frogs goes as much to the left as possible, and the other one goes to right. They'll be able to reach the ends, since the platforms in those directions are higher or equal. Then the answer is 8 (position of the frog on the right) - 0 (position of the frog on the left) + 1 = 9.

For Input '[1,2,3,4,5,6,5,4,3,2,2,3,4,5,6,7,8]'

The best would be to start at either position 10 or 11. Then one of the frogs can go to the ending right, and the other other can go to the left as far as the position 6. Answer is 17 - 6 + 1 = 12.
*/

#include "bits/stdc++.h"

using namespace std;

int32_t main(){

    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    std::vector<int> v = {1,2,3,4,5,6,5,4,3,2,2,3,4,5,6,7,8};
    int n = v.size();
    std::vector<int> dp_pref(n), dp_suff(n);
    
    dp_pref[0] = 0, dp_suff[n - 1] = 0;
    int cnt_pref = 0, cnt_suff = 0;
    for(int i = 1, j = n - 2;i<n;i++, j--){
        if(v[i] <= v[i - 1]) cnt_pref++;
        else cnt_pref = 0;
        if(v[j] <= v[j + 1]) cnt_suff++;
        else cnt_suff = 0;
        dp_pref[i] = cnt_pref;
        dp_suff[j] = cnt_suff;
    }

    int ans = 0;
    for(int i = 0;i<n;i++){
        int left_pos = i - dp_pref[i], right_pos = i + dp_suff[i];
        ans = max(ans, right_pos - left_pos + 1);
    }

    cout<<ans;

}
