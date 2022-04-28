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

using namespace std;

vector<int> g[MAXN];
bool used[MAXN];


void init(int n) {
	for (int i = 1; i <= n ; ++i) {
		used [i] = false;
	}
}

void dfs(int v) {
	used[v] = true;

	for (auto to: g[v]) {
		if (!used[to]) {
			dfs(to);
		}

	}
}

int findComps(int n) {
	init(n);
	int ans = 0;

	for (int i =  1; i <= n ; ++i) {
		if (!used[i]) {
			ans++;
			dfs(i);
		}
	}

	return ans;
}


int32_t main(){
	//read();
	//write();
	fst;
	int n, m;
	cin >> n >> m;

	for(int i=0; i<m; i++) {
		int u, v;
		cin >> u >> v;
		g[u].pb(v);
		g[v].pb(u);
	}

	cout << findComps(n) << endl;
	return 0;
}
