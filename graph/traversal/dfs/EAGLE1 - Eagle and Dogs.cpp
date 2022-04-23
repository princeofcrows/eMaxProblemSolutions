

#include <bits/stdc++.h>

using namespace std;


#define MAXN 100005
#define pii pair <int, long long>
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

long long d[3][MAXN];
bool vis[MAXN];
int dIdx;


void dfs(int u) {
	vis[u] = true;
	for(auto p: adj[u]) {
		if(!vis[p.fi]) {
			d[dIdx][p.fi] = d[dIdx][u] + p.se;
			dfs(p.fi);

		}
	}
}

void init(int n) {
	for(int i=1; i<=n; i++) {
		vis[i] = false;
		d[dIdx][i] = 0;
	}
}

void solve(int n) {
	dIdx = 0;
	init(n);

	dfs(1);

	long long m = -1;
	int idx = -1, idx2 = -1;

	for(int i=1; i<=n; i++) {
		if(d[0][i] > m) {
			m = d[0][i];
			idx = i;
		}
	}

	dIdx = 1;
	init(n);

	dfs(idx);

	m = -1;
	for(int i=1; i<=n; i++) {
		if(d[1][i] > m) {
			m = d[1][i];
			idx2 = i;
		}
	}

	dIdx = 2;
	init(n);

	dfs(idx2);

	for(int i=1; i<=n; i++) {
		printf("%lld", max(d[1][i], d[2][i]));
		if(i!=n) printf(" ");
	}
	printf("\n");

}

void clr(int n) {
	for(int i=1; i<=n; i++) adj[i].clear();
}


int32_t main(){
	read();
	//write();
	//fst;

	int t;
	si(t);
	while(t--) {
		int n;
		si(n);

		for(int i=1; i<=n-1; i++) {
			int u, v; long long dis;
			si(u); si(v); sil(dis);

			adj[u].pb({v, dis});
			adj[v].pb({u, dis});
		}

		solve(n);

		clr(n);
	}
	return 0;
}
