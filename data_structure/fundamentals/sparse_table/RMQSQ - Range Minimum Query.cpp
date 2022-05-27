#include <bits/stdc++.h>

using namespace std;

#define MAXN 1000005
#define int long long
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
#define K 22

int table[MAXN][K], ara[MAXN];

int callBackFn(int a, int b) {
	return min(a, b);
}

void initSparseTable(int n){
	mem(table, inf);

	for (int i=0; i<n; i++) {
		table[i][0] = ara[i];
	}

	for(int j = 1; j <= K; j++) {
		for(int i = 0; i <= n - (1 << j); i++)
			table[i][j] = callBackFn(table[i][j - 1], table[i + (1 << (j - 1))][j - 1]);
	}
}

int query(int L, int R, int n){
	int ans = inf;

	for(int j = K; j >= 0; j--) {
		if(L + (1<<j) - 1 <= R) {
			ans = callBackFn(ans, table[L][j]);
			L += 1 << j;
		}
	}
	return ans;
}


int32_t main() {
	//read();
	// write();
	int n;
	cin >> n;
	for(int i=0; i<n; i++) {
		cin >> ara[i];
	}
	initSparseTable(n);

	int q;
	cin >> q;

	while(q--) {
		int x, y;
		cin >> x >> y;
		cout << query(x, y, n) << endl;
	}
}
