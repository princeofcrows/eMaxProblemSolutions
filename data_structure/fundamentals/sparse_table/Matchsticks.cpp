#include <bits/stdc++.h>

using namespace std;

#define MAXN 1000005
#define pii pair <int, int>
#define piii pair <int, pii>
#define fi first
#define se second
#define mod 1000000007
#define inf 1e18+19
#define pb push_back
#define sil(x) scanf("%lld", &x)
#define si(x) scanf("%d", &x)
#define mem(ara, x) memset(ara, x, sizeof ara)
#define read() freopen("in.txt", "r", stdin)
#define write() freopen("out.txt", "w", stdout)
#define fst ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define K 22

int table[2][MAXN][K], ara[MAXN];

int callBackFn(int a, int b, int isMx) {
	return isMx ?  max(a, b) : min(a, b);
}

void initSparseTable(int n){
	for(int idx=0; idx<2; idx++) {
		for (int i=0; i<n; i++) {
			table[idx][i][0] = ara[i];
		}

		for(int j = 1; j <= K; j++) {
			for(int i = 0; i <= n - (1 << j); i++)
				table[idx][i][j] = callBackFn(
					table[idx][i][j - 1],
					table[idx][i + (1 << (j - 1))][j - 1],
					idx
					);
		}
	}
}

int query(int L, int R, int n, int isMx){
	int ans = mod * (1 - isMx);

	for(int j = K; j >= 0; j--) {
		if(L + (1<<j) - 1 <= R) {
			ans = callBackFn(ans, table[isMx][L][j], isMx);
			L += 1 << j;
		}
	}

	return ans;
}


int32_t main() {
	// read();
	// write();

	int n, q;
	while(cin >> n) {
		for(int i=0; i<n; i++) {
			cin >> ara[i];
		}
		initSparseTable(n);

		cin >> q;
		while(q--) {
			int l, r;
			cin >> l >> r;

			int a = query(l, r, n, 0);
			int b = l > 0 ? query(0, l-1, n, 1) : 0;
			int c = r < n-1 ? query(r+1, n-1, n, 1) : 0;
			int d = query(l, r, n, 1);

			double ans = a*1.0 + max(max(b, c) * 1.0, ((d - a) * 1.0 )/2.0);

			cout << fixed;
			cout << setprecision(1) << ans << endl;
		}

	}

}
