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

void solve() {
	std::vector<int> pi = prefixFunction(str);

	// for(auto u: pi) cout << u << " "; cout <<  endl;
	// for(auto u: str) cout << u << " "; cout <<  endl;

	for(int i=pi.back(); i<pi.back()+8; i++) {
		str += str[i];
		cout << str[i];
	}

	cout << "...\n";
}

int32_t main(){
	//read();
	//write();
	fst;
	int t;
	cin >> t;
	while(t--) {
		cin >> str;

		solve();
	}
	return 0;
}
