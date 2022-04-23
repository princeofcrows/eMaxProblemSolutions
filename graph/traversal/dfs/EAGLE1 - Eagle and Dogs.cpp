#include <bits/stdc++.h>

using namespace std;

#define MAXN 300005
#define pii pair <int, int>
#define piii pair <int, pii>
#define fi first
#define se second
#define mod 10000007
#define inf 1e18+19
#define pb push_back
#define sil(x) scanf("%lld", &x)
#define si(x) scanf("%d", &x)
#define mem(ara, x) memset(ara, x, sizeof ara)
#define read() freopen("in.txt", "r", stdin)
#define write() freopen("out.txt", "w", stdout)
#define fst ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

vector<pii> adj[MAXN];


void dfs(int u, vector<long long>& v, long long d, int par) {
	v[u] = d;
	for(auto p: adj[u]) {
		if(par!=p.fi) dfs(p.fi, v, d+p.se, u);
	}
}

void solve(int n) {
	vector <long long> d0(n+1, 0);
	vector <long long> d1(n+1, 0);
	vector <long long> d2(n+1, 0);

	dfs(1, d0, 0, -1);

	long long m = 0;
	int idx = -1, idx2 = -1;

	for(int i=1; i<=n; i++) {
		if(d0[i] > m) {
			m = d0[i];
			idx = i;
		}
	}

	dfs(idx, d1, 0, -1);

	m = 0;
	for(int i=1; i<=n; i++) {
		if(d1[i] > m) {
			m = d1[i];
			idx2 = i;
		}
	}

	dfs(idx2, d2, 0, -1);

	for(int i=1; i<=n; i++) {
		cout << max(d1[i], d2[i]) << " ";
	} cout << '\n';

}

void clr(int n) {
	for(int i=1; i<=n; i++) adj[i].clear();
}


int32_t main(){
	//read();
	//write();
	fst;
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;

		for(int i=0; i<n-1; i++) {
			int u, v, d;
			cin >> u >> v >> d;
			adj[u].pb({v, d});
			adj[v].pb({u, d});
		}

		solve(n);

		clr(n);
	}
	return 0;
}
