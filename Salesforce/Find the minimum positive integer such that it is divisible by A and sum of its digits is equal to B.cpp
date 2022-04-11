//https://leetcode.com/discuss/interview-question/1931976/Salesforce-India-oror-AMTS-(2022-Graduate)-oror-Online-Assessment-oror-Off-Campus
//https://www.geeksforgeeks.org/find-the-minimum-positive-integer-such-that-it-is-divisible-by-a-and-sum-of-its-digits-is-equal-to-b/

// C++ implementation of the approach
#include <bits/stdc++.h>
using namespace std;

// Array that stores visited digits
int visited[501][5001];

// Structure for queue Node.
struct Node {
	int a, b;
	string str;
};

// Function to return the minimum number such that it is
// divisible by 'a' and sum of its digits is equals to 'b'
int findNumber(int a, int b)
{
	// Create queue
	queue<Node> q;

	// Initially queue is empty
	Node temp = Node{ 0, 0, "" };

	// Initialize visited to 1
	visited[0][0] = 1;

	// Push temp in queue
	q.push(temp);

	// While queue is not empty
	while (!q.empty()) {

		// Get the front of the queue and pop it
		Node u = q.front();
		q.pop();

		// If popped element is the required number
		if (u.a == 0 && u.b == b)

			// Parse int from string and return it
			return std::stoi(u.str);

		// Loop for each digit and check the sum
		// If not visited then push it to the queue
		for (int i = 0; i < 10; i++) {
			int dd = (u.a * 10 + i) % a;
			int ss = u.b + i;
			if (ss <= b && !visited[dd][ss]) {
				visited[dd][ss] = 1;
				q.push(Node{ dd, ss, u.str + char('0' + i) });
			}
		}
	}

	// Required number not found return -1.
	return -1;
}

// Driver code.
int main()
{
	int a = 25, b = 1;
	cout << findNumber(a, b);
	return 0;
}
