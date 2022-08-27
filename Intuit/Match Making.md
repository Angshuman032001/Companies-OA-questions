## MATCHMAKING - 1

```
Description
Intuit receives calls from it's customers regarding various topics and in various languages. Intuit wants to match these customers to experts who have knowledge on exactly the same topic and can speak in that language. Based on the predictions, Intuit had N experts ready to take the calls, each expert knows exactly one topic and can speak exactly one language proficiently. On a particular day, M customers end up calling for their problems. A customer is unhappy if it is not matched to the expert who know about the topic they wish to enquire about and know the language they talk in. Can you help the team at Intuit assign the customers to experts, such that the minimum number of customers return unhappy


Constraints
1<= N <= 10^5
1<= M <= 10^5

Input Format
The first line contains N, the count of experts at Intuit.

Next N line contains 2 space seperated strings, the first denoting the topic the expert knows, and the second denoting the language they know The next line contains M. the count of customers calling Intuit.

Next M line contains 2 space seperated strings, the first denoting the topic the customer wants to enquire about, and the second denoting the language they speak in

Output Format
Return an integer representing the number of
customer which went unhappy with Intuit

Sample Input
4 
Tax English 
Crypto Hindi 
Tax Spanish 
SF English 
4 Crypto Hindi 
Tax Spanish 
Crypto Spanish 
Tax Spanish 
Sample Output
2 
Explanation
Crypto Spanish - Intuit does not have a crypt o expert who can work in Spanish. Tax Spanish - Intuit only has a single expert who can do tax and work in Spanish 
```

## Solution :

```cpp
#include <bits/stdc++.h>
using namespace std;


int main()
{

    Solution s = Solution();
    int n;
    cin>>n;
    unordered_map<string,vector<pair<string,int>>> mp;

    for(int i=0;i<n;i++){
        string a,b;
        cin>>a>>b;
		//map of pair pushing a new pair with same key and default flag value 0
        mp[a].push_back({b,0});
    }

    int m;
    cin>>m;

    vector<pair<string,string>> v;
    for(int i=0;i<m;i++){
        string a,b;
        cin>>a>>b;
		//taking all the testcase inputs 
        v.push_back({a,b});
    }

    int ans=0;

//iterating over all the testcases
    for(auto &c:v){
        auto it =mp.find(c.first);
		//if entry is found in map then we will search that language in pair vector by iteration
        if(it!=mp.end()){
            int j=0;
            for(;j<it->second.size();j++){
				//if the desired lang is present 
                if(it->second[j].first==c.second and it->second[j]==0)
                {
					//mark it as visited and cannot traverse it again
					//since given in question one expert can be occupied with only one customer
                    it->second[j].second=1;
                    break;
                }
            }
			//if we traversed the whole map and cannot find the matching language from testcase
			//then also customer unsatisfied
            if(j==it->second.size())ans++;
        }
		else
		ans++;
		//in this case if the lang is not present in the map then the customer is unsatisfied 
		// add the ans
			
    }

   cout<<ans<<"/n";
    
   return 0;
}
```
