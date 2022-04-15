// Unsolved WA on test 32

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

vector<int> adj[MAXN];

vector<int> bfs(int n, int s) {
	queue<int> q;
	vector<bool> used(n+1, false);
	vector<int> d(n+1, -1);

	q.push(s);
	used[s] = true;
	d[s] = 0;

	while (!q.empty()) {
		int v = q.front();
		q.pop();

		for (int u : adj[v]) {
			if (!used[u]) {
				used[u] = true;
				q.push(u);
				d[u] = d[v] + 1;
			}
		}
	}

	return d;
}

int solve(int n, int s, int f, int r) {
	vector<int> dS = bfs(n, s);
	vector<int> dF = bfs(n, f);
	vector<int> dR = bfs(n, r);

	map <int, int> res;

	for(int i=1; i<=n; i++) {
		if(dS[i] == -1 || dF[i] == -1 || dR[i] == -1) continue;

		if(dS[i] + dF[i] == dS[f]) {
			res[dS[i]] = max(res[dS[i]], dR[i]);
		}
	}

	int ans = mod;

	for(auto u: res) {
		ans = min(u.se, ans);
	}

	return ans;
}


int32_t main(){
	read();
	//write();
	fst;
	int n, m, s, f, r;
	cin >> n >> m;

	for(int i=0; i<m; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].pb(v);
		adj[v].pb(u);
	}

	cin >> s >> f >> r;

	cout << solve(n, s, f, r) << endl;
	return 0;
}
