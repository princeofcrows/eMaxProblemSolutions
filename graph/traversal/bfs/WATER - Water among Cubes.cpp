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

int g[105][105], vis[105][105];
priority_queue <piii, vector<piii>, greater<piii> > q;

void init(int n, int m) {
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=m; j++) {
			vis[i][j] = 0;
		}
	}

	for(int i=1; i<=m; i++) {
		q.push({g[1][i], {1, i}});
		q.push({g[n][i], {n, i}});

		vis[1][i] = g[1][i];
		vis[n][i] = g[n][i];
	}

	for(int i=1; i<=n; i++) {
		q.push({g[i][1], {i, 1}});
		q.push({g[i][m], {i, m}});

		vis[i][1] = g[i][1];
		vis[i][m] = g[i][m];
	}
}

bool isInside(int x, int y, int n, int m) {
	return x >= 1 && y >= 1 && x <= n && y <= m;
}

bool isOnBorder(int x, int y, int n, int m) {
	return x == 1 || x == n || y == 1 || y == m;
}

int bfs(int n, int m) {
	init(n, m);

	while(!q.empty()) {
		piii p = q.top();
		q.pop();

		if(vis[p.se.fi][p.se.se] != p.fi) continue;

		for(int dx=-1; dx<=1; dx++) {
			for(int dy=-1; dy<=1; dy++ ) {
				if((dx && dy) || (!dx && !dy)) {
					continue;
				}

				int x = p.se.fi + dx;
				int y = p.se.se + dy;

				if(isInside(x, y, n, m)) {
					if(!vis[x][y]) {
						if(g[x][y] <= vis[p.se.fi][p.se.se]) {
							vis[x][y] = p.fi;
						} else {
							vis[x][y] = g[x][y];
						}

						q.push({vis[x][y], {x, y}});
					}
				}
			}
		}
	}

	int ans = 0;
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=m; j++) {
			ans += (-g[i][j] + vis[i][j]);
		}
	}

	return ans;
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

		for(int i=1; i<=n; i++) {
			for(int j=1; j<=m; j++) {
				cin >> g[i][j];
			}
		}

		cout << bfs(n, m) << endl;
	}

	return 0;
}
