#include <bits/stdc++.h>

using namespace std;

#define mx 100005
//#define int long long
#define pii pair <int, int>
#define piii pair <int, pii>
#define fi first
#define se second
#define mod 1000000007
#define inf 1e18+19
#define pb push_back
#define sil(x) scanf("%lld", &x)
#define si(x) scanf("%d", &x)
#define mem(ara, x) memset(ara, x, sizeof ara)
#define read() freopen("in.txt", "r", stdin)
#define write() freopen("out.txt", "w", stdout)
#define fst ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int dp[85][85];

vector<int> zFunction(string s) {
	int n = s.size();
	vector<int> z(n);

	int l = 0, r = 0;

	for(int i = 1; i < n; i++) {
		if(i < r) {
			z[i] = min(r - i, z[i - l]);
		}

		while(s[z[i]] == s[i + z[i]]) {
			z[i]++;
		}

		if(i + z[i] > r) {
			l = i;
			r = i + z[i];
		}
	}

	return z;
}

int rec(int i, int j, string &s) {
	if(i > j) return 0;
	if(dp[i][j] != -1) return dp[i][j];

	vector <int> z = zFunction(s.substr(i, j - i + 1));
	int n = j - i + 1;

	int ret = n;

	for(int l=1; l<n; l++) {
		if(z[l] + l == n && n % l == 0) {
			ret = min(ret, rec(i, i+l-1, s));
		}
	}

	for(int l=i+1; l<=j; l++) {
		ret = min(ret, rec(i, l-1, s) + rec(l, j, s));
	}

	//cout << i << " " << j << " " << ret << endl;

	return dp[i][j] = ret;
}

void solve(string s) {
	mem(dp, -1);

	cout << rec(0, s.length() - 1, s) << "\n";
}


int32_t main(){
	//read();
	//write();
	fst;
	string str;

	while(cin >> str) {
		if(str == "*") break;

		solve(str);
	}

	return 0;
}
