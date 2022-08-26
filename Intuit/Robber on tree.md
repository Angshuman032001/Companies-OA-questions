```
Robber on Tree!
You are given a rooted tree of N nodes, numbered 1 to N, with root as 1. Each node in the tree has some number of coins denoted by Ci representing the number of coins the ith node has.

At time t = 0, you are at the root node and there's a robber at one of the leaf nodes R. At each step, both you and robber take one step each and move to an adjacent node.

To prevent chaos, there's some restriction on both your and robber's movement. You have to choose a leaf node and take the shortest path to that leaf node and stop once you reach that leaf node. The robber has to take the shortest path to the root node and stop once the robber reaches the root node.

A person reaching a node first gets to take all the coins in the node leaving it empty for anyone who visits it after that time. If 2 people reach the node at the same time, they each get half of the coins in that node.

What's the maximum number of coins that you can aim to get in this process?

2<= N <= 100,000
-10000 <= Ci <= 10000

The number of coins in each node is even.

Input format:

First line contains two integers N, R representing the number of nodes in the tree and the position of the robber at t = 0.

Next N-1 lines contain two integers A, B denoting that there's an Undirected edge between nodes A and B.

The next line contains N space separated integers which represent the coins in each node.

Output Format:

The maximum no. of coins you can get.

Sample Input:
7 7
1 2
1 3
2 4
2 5
3 6
3 7
2 4 6 2 2 6 8

Sample Output:
11
```
