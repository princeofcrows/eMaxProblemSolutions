# include <iostream>
#include <vector>
#include <queue>

#define read() freopen("in.txt", "r", stdin)

using namespace std;
#define MAXN 100005

int n;
vector<int> g[MAXN];
bool used[MAXN];
vector<int> comp;
vector<vector<int> > compCol;

void init(int n) {
	for (int i = 1; i <= n ; ++i) {
		used [i] = false;
	}
}

void dfs(int v) {
	used[v] = true;
	comp.push_back(v);

	for (auto to: g[v]) {
		if (!used[to]) {
			dfs(to);
		}

	}
}

void findComps() {
	init(n);

	for (int i = 1; i <= n ; ++i) {
		if (!used[i]) {
			comp.clear();
			dfs(i);
			compCol.push_back(comp);
		}
	}

	cout << ((int)compCol.size()) - 1 << endl;

	for(int i=1; i<compCol.size(); i++) {
		cout << compCol[i-1].front() << " " << compCol[i].front() << "\n";
	}

}


int32_t main(){
	//read();
	//write();

	int m;
	cin >> n >> m;

	for(int i=0; i<m; i++) {
		int u, v;
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}

	findComps();
	return 0;
}
