## Q4 - Query In A Binary String
```
Given a binary string s that contains only "0" and "1". You are also given an array query with the following operations:

"Count" - The answer to this query is the number of 1s in the binary string.
"Flip" - Flip the substring [0, idx] so that "0" -> "1" and "1" -> "0" and idx is the first "0" in the binary string. 
You are guaranteed that flip operation will only be called when there is at least one "0". The answer to the query is idx.
```

#### Constraints:
```
1 <= s.length() <= 100000 (1e5)
1 <= query.length <= 100000 (1e5)
```

##### Samples
```cpp
s = "01110"
q = ["count", "count", "flip", "count", "count"]
Ans = [3, 3, 0, 4, 4]

s = "000"
q = ["flip", "count", "count"]
Ans = [0, 1, 1]
```


###### BruteForce (BitSet - Accepted)

```
Do what it says with BitSet.
Time O(N * Q / (64 or 32))
Space O(? - less than N)
```


```java
 private static int[] brute(String s, String[] query){ // Java
      int[] ans = new int[query.length];
      BitSet bit = new BitSet();
      for (int i = 0; i < s.length(); i++){
          if (s.charAt(i) == '1'){
              bit.set(i);
          }
      }
      for (int i = 0; i < query.length; i++){
          if (query[i].equals("count")){
              ans[i] = bit.cardinality();
          }else{
              int idx = bit.nextClearBit(0);
              bit.flip(0, idx+1);
              ans[i] = idx;
          }
      }
      return ans;
  }
```

###### Simulation (Queue & HashMap - Accepted)
```
Adjusts for the next zero index on the fly.
The below solution is based on the fact that the first zero indexes follow a pattern:
[0, 1, 0, 2, 0, 1, 0, 3, 0, 1, ...]

0 -> 2 steps increment
1 -> 4 steps increment
2 -> 8 steps increment
.
.
.
This can be simulated with a HashMap on the fly.

Time O(N+Q)
Space O(N+Q)
```


```java
private static int[] solve(String s, String[] query){ // Java
      int[] ans = new int[query.length];
      int one = 0;
      Queue<Integer> queue = new ArrayDeque<>();
      for (int i = 0; i < s.length(); i++){
          one += s.charAt(i) - '0';
          if (s.charAt(i) == '0'){
              queue.offer(i);
          }
      }
      Map<Integer, Integer> zero = new HashMap<>(); // can also use an array of size query.length
      for (int i = 0, top = 0, count = 0, d = 0; i < query.length; i++){ // run simulation
          if (query[i].equals("count")){
              ans[i] = one;
          }else{
              if (top == 0){ // all the zeros cushion have been used up, so we pop the next zero
                  ans[i] = top = queue.poll();
              }else{
                  ans[i] = zero.getOrDefault(count, d);
                  zero.putIfAbsent(count + (1<<ans[i]+1), ans[i]);
                  if (ans[i] == d){ // base case
                      zero.put(count, d++);
                  }
                  count++;
                  if (ans[i] == top-1){ // the highest 0 just became 1, so we decrease top and reset counter
                      top--;
                      count = 0;
                  }
              }
              one += 1 - ans[i]; // every flip we gain this much 1s
          }
      }
      return ans;
  }
```


###### A Better Solution (Convert to Integer - Accepted) [Credit to @leetcode_dafu]
```
It may look like the time compleixty is worse but it is actually a bit faster than the previous solution.
It is due to the fact that numberOfTrailingZeros() itself is quick and that there are less lines in the for-loop.
This solution is beautiful. Really clean. This performs the best among all 4 solutions.

Time O(30Q + N)
Space O(1)
```


```java
private static int[] solve2(String s, String[] query){ // Java
        int lo = 0, one = 0;
        for (int i = s.length() - 1; i >= 0; i--){
            one += s.charAt(i) - '0';
            if (i <= 30){
                lo <<= 1;
                lo += (s.charAt(i) - '0');
            }
        }
        int[] ans = new int[query.length];
        for (int i = 0; i < query.length; i++){
            if (query[i].equals("count")){
                ans[i] = one;
            }else{
                ans[i] = Integer.numberOfTrailingZeros(~(lo++));
                one += 1 - ans[i];
            }
        }
        return ans;
    }
```


###### Another Better Solution [Accepted]
```
No idea how I coded up the simulation solution without realizing a technique that I used in that simulation solution would have made the bitset bruteforce solution basically optimal.

flip() is tough, let bitset flip() do it for you.
Find the first "0" is tough, let bitset nextClearBit() do it for you.
cardinality() will get you TLE with too many "count" queries, so we observe that if we flip i, we gain 1 - ans[i] 1s.
Time O(30Q + N)
Space O(less than N)
```


```java
private static int[] brute(String s, String[] query){
      int[] ans = new int[query.length];
      BitSet bit = new BitSet();
      int one = 0;
      for (int i = 0; i < s.length(); i++){
          if (s.charAt(i) == '1'){
              bit.set(i);
              one++;
          }
      }
      for (int i = 0; i < query.length; i++){
          if (query[i].equals("count")){
              ans[i] = one;
          }else{
              int idx = bit.nextClearBit(0);
              bit.flip(0, idx+1);
              ans[i] = idx;
              one += 1 - ans[i];
          }
      }
      return ans;
  }
    ```
