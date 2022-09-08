## Statement

```
LAZY CHEF II

Description
Chef enters the kitchen which consists of N linear blocks where each block contains only 1 ingredient from a list of ingredients.

Chef has to prepare the dish consisting of 2 ingredients 11 and 12. To prepare the dish D, the first task for chef is to group blocks of all 11 ingredients and 12 ingredients together and also, group of 11 and 12 ingredients should be adjacent to each other. Chef needs to achieve this task by only swapping adjacent blocks with one another. One swap is equivalent to one valid move. Since the chef is lazy, can you help him determine the minimum number of moves in which he can complete this task.

Constraints
1<=N<=100,000

There is at-least one occurrence of both 11 and 12 on the shelf.

One swap is equivalent to one valid move.

Output Format Print the minimum number of moves in which chef can complete this task.

Input Format
The first line contains N, denoting the number of blocks in the kitchen.
The second line contains N space-separated characters, where the ith character represents ingredient on ith block.
The third line contains 2 space-separated characters 11 and 12, denoting ingredients required to prepare dish D.

Output Format
Print the minimum number of moves in which chef can complete this task.

Sample Input
7 
H D H S A H S 
H S  
Sample Output
4 
Explanation
Here are the set of moves required: -
Move 1 -
Swapping element at index 0 and 1 DHHSAHS - 
Move 2 - 
Swapping element at index 4 and 5 DHHSHAS - 
Move 3 -
Swapping element at index 5 and 6 DHHSHSA - 
Move 4 - 
Swapping element at index 3 and 4 DHHHSSA 
```


## Probable Solution

```
For any non-target character, we must either move it to the right end or the left end.
If we move it to the right end, we need at least the number of L1 and L2 to its right to do so.
likewise, we will need that much to its left if we decide it to move it to the left end.

Then, we can consider arranging L1 and L2.
We either move L1 to the left or L2 to the left.
Compute it with the same logic as the above.
```

```cpp
//https://leetcode.com/discuss/interview-question/2492460/Intuit-India-or-OA-or-LAZY-CHEF-II
#include "bits/stdc++.h"

using namespace std;

int32_t main(){

    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    string s; cin>>s;
    char a, b; cin>>a>>b;

    int index = 0;
    int a_cnt = 0, b_cnt = 0, take = 0, first_option = 0, second_option = 0, remaining = 0;
    while(index < size(s)){
        a_cnt += (s[index] == a);
        b_cnt += (s[index] == b);
        index++;
    }

    int ans = 0;

    index = 0;
    while(index < size(s)){
        char currChar = s[index];
        if(currChar != a && currChar != b){
            take += min(a_cnt + b_cnt, remaining);
        }
        else{
            if(currChar == a){
                a_cnt--;
                first_option += b_cnt;
                remaining++;
            }
            else{
                b_cnt--;
                second_option += a_cnt;
                remaining++;
            }
        }
        index++;
    }

    ans = take;
    ans += min(first_option, second_option);

    cout<<ans;


}
```
