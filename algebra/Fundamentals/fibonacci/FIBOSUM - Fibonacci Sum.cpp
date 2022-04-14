#include <bits/stdc++.h>

using namespace std;

#define MAXN 1000005
#define int long long
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

using namespace std;

pair<int, int> fiboFastDoubling (int n) {
	if (n == 0)
		return {0, 1};

	auto p = fiboFastDoubling(n >> 1LL);
	int c = (p.first * ((2 * p.second - p.first) % mod + mod) % mod ) % mod;
	int d = (p.first * p.first + p.second * p.second) % mod;

	if (n & 1LL)
		return {d, c + d};
	else
		return {c, d};
}


int32_t main(){
	//read();
	//write();
	//fst;
	int t;
	cin >> t;
	while(t--) {
		int n, m;
		cin >> n >> m;

		pii Fn = fiboFastDoubling(n+1);
		pii Fm = fiboFastDoubling(m+2);

		int ans = (Fm.fi - Fn.fi + mod) % mod;

		cout << ans << endl;
	}

	return 0;
}
