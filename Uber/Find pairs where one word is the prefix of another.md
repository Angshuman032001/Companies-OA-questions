## Statement

```
Q1 : Given an array of strings` words` find the number of, pairs where either the strings are equal or one string starts with another.
In other words, find the number of such pairs i, j (0 <= i < j < words.length ) 'that words[i] is a prefix Of' words [j] ,
or words [j] is a prefix of words[i].

Examples : 
words = { "back", "backdoor", "gammon", "backgammon", "comeback", "come", "door" }
Output : 3

words = {"abc", "a", "a", "b", "ab", "ac"}
Output : 8


Constraints: 1 <= words.length <= 1e5
```


## Solution

```cpp
#include "bits/stdc++.h"

using namespace std;

struct Trie{
    Trie* child[26];
    int occurence = 0;
    Trie(){
        memset(child, NULL, sizeof(child));
    }
};

int32_t main(){

    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    vector<string> v = {"abc", "a", "a", "b", "ab", "ac"};
    sort(v.begin(), v.end(), [&](auto &x, auto &y)->bool{
        return x.length() < y.length();
    });

    Trie* root = new Trie();

    auto insert = [&](string &word)->int{
        Trie* curr = root;
        int ans = 0;
        for(char ch : word){
            if(curr->child[ch - 'a'] == NULL) curr->child[ch - 'a'] = new Trie();
            curr = curr->child[ch - 'a'];
            ans += curr->occurence;
        }
        curr->occurence++;
        return ans;
    };      

    int ans = 0;
    for(auto word : v){
        ans += insert(word);
    }

    cout<<ans;

}
```
