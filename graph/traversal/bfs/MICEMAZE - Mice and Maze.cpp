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

std::vector<pii> g[105];
priority_queue <pii, vector<pii>, greater<pii> > q;
int d[105];

int djk(int n, int s, int T) {
	for(int i=1; i<=n; i++) d[i] = mod;

	d[s] = 0;
	q.push({0, s});

	while(!q.empty()) {
		pii p = q.top();
		q.pop();

		if(d[p.se] != p.fi) continue;

		for(auto u: g[p.se]) {
			int dis = u.se + p.fi;

			if(d[u.fi] > dis) {
				d[u.fi] = dis;
				q.push({dis, u.fi});
			}
		}
	}

	int ans =0;
	for(int i=1; i<=n; i++) ans += (d[i] <= T);

	return ans;
}

int32_t main(){
	//read();
	//write();
	//fst;
	int n, e, T, m;
	cin >> n >> e >> T >> m;

	for(int i=1; i<=m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		g[b].pb({a, c});
	}

	cout << djk(n, e, T) << endl;

	for(int i=1; i<=n; i++) g[i].clear();

	return 0;
}
