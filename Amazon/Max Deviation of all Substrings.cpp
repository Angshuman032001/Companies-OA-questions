/*

Given a string find max deviation among all substrings
Deviation means the difference between
Max occuring char - min occuring char.

Ex - bbacccababa
Ans - ccca with max dev as 2
n <=10^4
*/

#include "bits/stdc++.h"

using namespace std;

int kadaneOfMinSizeTwo(std::vector<int> &arr, int k){
    if(arr.size() < k) return 0;
    int n = arr.size();

    /*max possible sum ending at ith index*/
    vector<int>maxSum(n);
    maxSum[0] = arr[0];
    for(int i = 1;i<n;i++){
        maxSum[i] = max(arr[i], maxSum[i - 1] + arr[i]);
    }

    int ans = 0, sum_of_k_length = 0;
    for(int i = 0;i<k;i++) sum_of_k_length += arr[i];

    ans = sum_of_k_length;

    for(int i = k;i<n;i++){
        sum_of_k_length += arr[i] - arr[i - k];
        ans = max(ans, sum_of_k_length);
        ans = max(ans, sum_of_k_length + maxSum[i - k]);
    }
    return ans;
}

int maxDeviation(string &s){
    /*first we fix the max occuring char and min occuring char*/       
    int ans = 0;
    for(char max_char = 'a'; max_char <= 'z'; max_char++){
        for(char min_char = 'a'; min_char <= 'z'; min_char++){
            if(min_char == max_char) continue;
            vector<int>arr;
            for(char c : s){
                if(c == max_char) {
                    if(arr.size() && arr.back() != -1){
                        arr.back() += 1;
                    }
                    else arr.push_back(1);
                }
                else if(c == min_char) arr.push_back(-1);
            }
            ans = max(ans, kadaneOfMinSizeTwo(arr, 2));
        }
    }
    return ans;
}

int32_t main(){

    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    string s; cin>>s;
    cout<<maxDeviation(s);

}
