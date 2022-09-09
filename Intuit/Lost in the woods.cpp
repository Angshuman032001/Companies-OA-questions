# include <bits/stdc++.h>
using namespace std;

string solve(vector<char>& board, int n) {
	string res;

	int i = 1;

	while(i < n-1) {
		if(board[i] == '_') {
			res.push_back('W');
		}
		else {
			res.push_back('J');
			while(i < n-1 && board[i] == '*') {
				i++;
			}
		}
		i++;
	}

	return res;
}

int main(){
	int n;
	cin >> n;
	vector<char> board;

	for(int i = 0; i < n; i++) {
		char temp;
		cin >> temp;
		board.push_back(temp);
	}

	cout << solve(board, n);

	return 0;
}
