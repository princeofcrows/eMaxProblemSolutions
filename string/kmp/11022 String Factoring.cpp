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

int dp[88][88];
string str;

vector<int> prefixFunction(string s) {
	int n = (int)s.length();

	vector<int> pi(n);

	for (int i = 1; i < n; i++) {
		int j = pi[i-1];
		while (j > 0 && s[i] != s[j])
			j = pi[j-1];
		if (s[i] == s[j])
			j++;
		pi[i] = j;
	}

	return pi;
}

int solve(int s, int e) {
	if(dp[s][e] != -1) return dp[s][e];
	if(s == e) return 1;

	dp[s][e] = mod;
	for(int i=s; i<e; i++) {
		dp[s][e] = min(dp[s][e], solve(s, i) + solve(i+1, e));
	}

	int n = e - s + 1;
	vector<int> p = prefixFunction(str.substr(s, n));
	int m = n - p.back();

	if(n % m == 0 && n != m) dp[s][e] = min(dp[s][e], solve(s, s + m - 1 ));

	return dp[s][e];
}

int32_t main(){
	//read();
	//write();
	fst;

	while(cin >> str) {
		if(str == "*") break;

		mem(dp, -1);

		int n = str.length();

		cout << solve(0, n-1) << "\n";
	}
	return 0;
}
