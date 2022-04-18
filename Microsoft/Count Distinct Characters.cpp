//https://leetcode.com/discuss/interview-question/1481915/amazon-oa-count-distinct-characters-in-all-substrings

/*Count Distinct Characters in all substrings*/

/*

"t" -> 1
"e" -> 1
"s" -> 1
"t" -> 1
"te" -> 2
"es" -> 2
"st" -> 2
"tes" -> 3
"est" -> 3
"test" -> 3

*/

#include "bits/stdc++.h"

using namespace std;

int countOfSubstringsWhereCIsPresent(string &s, char c){
    int cnt_of_non_c = 0, total = 0, n = s.length();
    for(char &ch : s){
        if(ch == c){
            total += (cnt_of_non_c * (cnt_of_non_c + 1)) / 2;
            cnt_of_non_c = 0;
        }
        else cnt_of_non_c++;
    }
    total += (cnt_of_non_c * (cnt_of_non_c + 1)) / 2;
    return (n * (n + 1)) / 2 - total;
}

int32_t main(){

    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    string s = "test";

    int ans = 0;

    for(char c = 'a'; c <= 'z'; c++) ans += countOfSubstringsWhereCIsPresent(s, c);
    cout<<ans;

}
