#include <bits/stdc++.h>

using namespace std;

#define mx 300005
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

int res[mx], idx[mx][2];
bool vis[mx];
vector<vector<int> > v;

int gcd(int a, int b) {
	return b ? gcd(b, a%b) : a;
}

void solve(int n, int k) {
	for(int i=1; i<=n; i++) {
		vis[i] = false;
	}


	for(int i=1; i<=n; i++) {
		if(vis[i]) continue;

		int x = i;
		vector<int> cycle;

		while(!vis[x]) {
			idx[x][0] = v.size();
			idx[x][1] = cycle.size();

			cycle.pb(x);
			vis[x] = true;

			if(x%2) x = (x + 1)/2;
			else x = n/2 + x/2;
		}

		v.pb(cycle);
	}

	int lcm = 1;
	for(int i=1; i<v.size(); i++) {
		int num = v[i].size();
		lcm = (lcm * num) / gcd(num, lcm);
	}

	k %= lcm;

	for(int i=1; i<=n; i++) {
		int j = (idx[i][1] + k) % (v[idx[i][0]].size());
		res[v[idx[i][0]][j]] = i;
	}

	for(int i=1; i<=n; i++) cout << res[i] << " ";
	cout << endl;

	v.clear();
}


int32_t main(){
	//read();
	//write();
	//fst;
	int t;
	cin >> t;

	while(t--) {
		int n, k;
		cin >> n >> k;
		solve(n, k);
	}

	return 0;
}
