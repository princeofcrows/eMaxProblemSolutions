#include <bits/stdc++.h>

using namespace std;

#define MAXN 1000005
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

vector<int>adj[MAXN];
vector<bool> used(MAXN, false);
vector<int> p(MAXN, -1);
vector<pii> ks(MAXN);
int n, m, r;


bool bfs() {
	bool res = true;

	for(int i=0; i<m; i++) {
		queue <pii> q;
		q.push(ks[i]);

		if(used[ks[i].fi] && p[ks[i].fi] != i) {
			res = false;
			break;
		}

		used[ks[i].fi] = true;
		p[ks[i].fi] = i;

		while (!q.empty()) {
			pii v = q.front();
			q.pop();

			if(v.se == 0) continue;

			for (int u : adj[v.fi]) {
				if (!used[u]) {
					used[u] = true;
					q.push({u, v.se-1});
					p[u] = i;
				} else if(p[u] != i) {
					res = false;
					break;
				}
			}
		}

		if(!res) break;
	}


	for(int i=1; i<=n; i++) {
		res = res && used[i];
	}

	return res;
}

void init() {
	si(n); si(r); si(m);
	for(int i=1; i<=n; i++) used[i] = false;

	for(int i=0; i<r; i++) {
		int u, v;
		si(u); si(v);

		adj[u].pb(v);
		adj[v].pb(u);
	}

	for(int i=0; i<m; i++) {
		int k, s;

		si(k); si(s);

		ks[i] = {k, s};
	}
}

void clr() {
	for(int i=1; i<=n; i++) adj[i].clear();
}


int32_t main(){
	//read();
	//write();
	//fst;
	int t;
	si(t);
	while(t--) {
		init();

		bfs() ? printf("Yes\n") : printf("No\n");

		clr();
	}

	return 0;
}
