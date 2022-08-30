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

```java
private static int solve(String s, char a, char b){ // Java
      int aCount = (int)s.chars().filter(o -> o == a).count();
      int bCount = (int)s.chars().filter(o -> o == b).count();
      int must = 0, option1 = 0, option2 = 0, left = 0;
      for (char ch : s.toCharArray()){
          if (ch == a){
              aCount--;
              option1 += bCount;
              left++;
          }else if (ch == b){
              bCount--;
              option2 += aCount;
              left++;
          }else{
              must += Math.min(aCount+bCount, left);
          }
      }
      return must + Math.min(option1, option2);
  }
    ```
