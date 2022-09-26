```
The test was conducted on CodeSignal. I got the test link by applying through referral.

Question 1 :-

You are standing at the start of a very long straight road. On the road, there are n cupcakes present. You are given the distance of each cupcake from the start of the road. Each of these distances is an integer, and multiple cupcakes can be present at the same distance from the start of the road.

You have to select 2 intervals of length k on the road and collect all the cupcakes that lie inside either of the intervals. The intervals are allowed to intersect.
For example, for k = 3, the interval [1, 4] is a valid interval of length 3, and by
choosing that interval, you can collect all the cupcakes that lie at a distance of 1, 2, 3 or 4 from the start of the road.

Find the maximum number of cupcakes that you can collect by picking 2 intervals as described above.

Sample Test Cases

n = 6

k = 1

distance = [ 1, 1, 2, 6, 8, 9 ]

expected output = 5

Explanation : -

We can pick the 2 intervals [1, 2] and [8, 9]. Both these intervals have length of 1 and there are a total of 5 cupcakes that lie in these intervals.

[execution time limit] 1 seconds (cpp)

[input] integer n

The number of cupcakes : -

  1 <= n <= 2 * (10 ^ 5)
[input] integer k

the length of the intervals that you can pick :-

  1 <= k <= 10^9
[input] array.integer distance

Array of n integers. The i th integer describes the distance of the i th cupcake from the start of the road.

1 <= Ai <= 10^9, where Ai is the i th element in the array. All the Ai S are NOT NECESSARILY DISTINCT.

[output] integer

The maximum number of cupcakes you can collect.

Question 2 :-

Given two non-empty strings str1 and str2, both the strings consist of only lowercase Latin letters. Your task is to calculate the number of different pairs of (a b) such that a is a substring of str1, b is a subsequence of str2, and the content of a and b are the same.

A string s is called a substring of str, if you can form s from str by removing. characters from the start and end of str. Two substrings str[x1...y1] and str[x2...y2] are considered different if x1 != x2 or y1 != y2.
For example - "uber" and "eats" are two different substrings of "ubereats" whellas
"ubee" is not a substring.

A string s is called a subsequence of str, if you can form s from str by removing characters at any position of str. Two subsequences p and q are considered different if at least one character present in p has a different position in the original string for the corresponding character in q.
For example - "ubee" and "ubea" are two different subsequences of "ubereats" whereas "uby" is not a subsequence.

Sample Input

str1 = "aa"
str2 = "aa"
Sample Output

5
Explanation

Following are the valid (a b) pairs (str1[1..1] str2[1.11)
(str1 [1 . . 1] str2[1 . . 1)
(str1[1 . . 1] str2[2 . . 2])
(str1 [2..2] str2[1. .1])
(str1 [2..2] str2 [2. .21)
(str1 [1..21 str2 [1..21)
[execution time limit] 1 seconds (cpp)

[input] string str1

The First Input string consists of lowercase Latin letters [1 <= length(str1) <= 20001]

[input] string str2

The second input string consists of lowercase Latin letters [ 1 <= length(str2) <=
2000]

[output] integer

The number of different (a b) pairs such that "a" is a substring of str1, "b" is a subsequence of str2 and the content of "a" and "b" are the same. The answer
can be large, print it modulo 1000000007 (1e9 + 7).

Question 3 : -

You are the mayor of a very old city. The city has n major tourist attractions. You are given the locations (x, y, z) for each of these tourist attractions.

To boost the tourism in your city, you plan to create new roads that connect the tourist attractions.

To create a bidirectional road between tourist attraction A (located at (x1, y1, z1) ) and B (located at (x2, y2, z2) ), you need to spend min ( |x1 - x21 , ly1 y21, 1z1 - z21) dollars. Here |x1 - x2| refers to the absolute value of x1 - ×2, and min(*, y, z) refers to the minimum value out of x, y and z.

You need to create a network of roads such that it is possible to travel between
any pair of tourist attractions using some sequence of roads. What is the minimum amount of dollars you need to spend in order to accomplish this task?

Sample Input

``n = 3``

``locations = 

[[1, 5, 7],
[2, 9, 4],
[1, 3, 9]]
Expected Output

1
Explanation

We can create 2 roads -
	1. Road connecting attraction 1 (at (1, 5, 7)) and attraction 3 (at (1, 3, 9). The cost
		of creating this road is min ( | 1 - 1 |, | 5 - 3 |, |7 - 9 |) = min (0, 2, 2) = 0.
	2. Road connecting attraction 1 (at (1; 5, 7)) and attraction 2 (at (2, 9, 4)). The cost
		of creating this road is min (1 1 - 2 |, | 5 - 9 |, 17 - 4 |) = min (1,4,3) = 1.
Creating these two roads enables us to travel between any pair of tourist attractions.
The total cost of creating these roads is 1 dollar.
[execution time limit] 1 seconds (cpp)

The number of major tourist attractions in the city.

1 <= n <= 100000

[input] array.array.integer.locations

A matrix consisting of n rows. Each row has 3 integers - xi, Yi, zi - which describe the location of the i th attraction.

All coordinates are integers, and
-100000 <- Xi, Yi, Zi <= 100000 forall i.

[output] integer64

The minimum amount in dollars that you need to spend in order to build the road
network.

I was able to solve 2 out the three questions, but haven't recieved any further updates regarding the opportunity.

Do share any updates if you made it to the further rounds.
```
