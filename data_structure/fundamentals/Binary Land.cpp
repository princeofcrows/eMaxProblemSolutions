//Unsolved

#include <deque>
#include <iostream>
#include <vector>
#define mod 1000000007
#define read() freopen("in.txt", "r", stdin)
using namespace std;

deque<vector<vector<int> > > q;
deque<string> binLand;

void add(string L, int n){
	if(q.empty()) {
		vector<vector<int> > res(n);

		for(int i=0; i<n; i++) {
			vector<int> dp(n, 0);
			dp[i] = 1;
			res[i] = dp;
		}

		q.push_back(res);
		binLand.push_back(L);

		return;
	}

	vector<vector<int> > res(n);

	for(int i=0; i<n; i++) {
		vector<int> dp(n, 0);

		for(int j=0; j<n; j++) {
			dp[j] = q.back()[i][j];
			if(j+1 < n) dp[j] = (dp[j] + q.back()[i][j+1]) % mod;
			if(j-1 >= 0) dp[j] = (dp[j] + q.back()[i][j-1]) % mod;
		}

		res[i] = dp;
	}

	q.push_back(res);
	binLand.push_back(L);

	return;
}

void remove() {
	q.pop_front();
	binLand.pop_front();
}

int solve(int x, int y) {
	if(binLand.front()[x-1] != binLand.back()[y-1]) return 0;
	return (q.back()[x-1][y-1] - q.front()[x-1][x-1] + 1 + mod) % mod;
}

int main() {
	read();
	int n, q;
	cin >> n >> q;

	while(q--) {
		string typ;
		cin >> typ;
		if(typ == "add") {
			string L;
			cin >> L;
			add(L, n);
		} else if(typ == "remove") {
			remove();
		} else {
			int x, y;
			cin >> x >> y;
			cout << solve(x, y) << "\n";
		}
	}
}
