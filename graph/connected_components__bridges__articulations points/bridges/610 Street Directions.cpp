#include <bits/stdc++.h>

using namespace std;

#define MAXN 10005
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

int n; // number of nodes
vector<vector<int> > adj(MAXN); // adjacency list of graph

vector<bool> visited;
vector<int> tin, low;
int timer;
int roads[1004][1004];

void dfs(int v, int p = -1) {
	visited[v] = true;
	tin[v] = low[v] = timer++;

	for (int to : adj[v]) {
		if (to == p) continue;

		if (visited[to]) {
			low[v] = min(low[v], tin[to]);

			if(!roads[to][v]) {
				roads[v][to] = 1;
			}
		} else {
			dfs(to, v);
			low[v] = min(low[v], low[to]);

			if (low[to] > tin[v]) {
				roads[to][v] = roads[v][to] = 1;
			} else if(!roads[to][v]) {
				roads[v][to] = 1;
			}

		}
	}
}

void findBridges() {
	timer = 0;
	visited.assign(n+1, false);

	tin.assign(n+1, -1);
	low.assign(n+1, -1);

	for (int i = 1; i <= n; ++i) {
		if (!visited[i])
			dfs(i);
	}
}

void gen(int m) {
	while(m--) {
		int u, v;
		cin >> u >> v;

		adj[u].push_back(v);
		adj[v].push_back(u);
	}
}

void clear() {
	for(int i=1; i<=n; i++) adj[i].clear();
	mem(roads, 0);
	tin.clear();
	low.clear();
	visited.clear();
}

void print(int cs) {
	cout << cs << "\n\n";

	for(int i=1; i<=n; i++)
		for(int j=1; j<=n; j++)
			if(roads[i][j]) cout << i << " " << j <<  endl;

	cout << "#\n";
}


int main() {
	// read();
	// write();

	int cs = 1;
	int m;

	while(cin >> n >> m) {
		if(!n && !m) break;

		gen(m);

		findBridges();

		print(cs++);

		clear();
	}
}
