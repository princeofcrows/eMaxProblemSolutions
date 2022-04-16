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

string str[55];
int dp[55][55];
int h, w;

bool isInside(int x, int y, int n, int m) {
	return x >= 0 && y >= 0 && x < n && y < m;
}

int dfs(int i, int j) {
	if(dp[i][j] != -1) return dp[i][j];

	int ret = 1;

	for(int dx=-1; dx<=1; dx++) {
		for(int dy=-1; dy<=1; dy++) {
			if(dx==0 && dy==0) continue;

			int x = dx + i;
			int y = dy + j;

			if(isInside(x, y, h, w)) {
				if((str[i][j] + 1 ) == (str[x][y])) {
					ret = max(ret, dfs(x, y) + 1);
				}
			}
		}
	}

	return dp[i][j] = ret;
}


int32_t main(){
	//read();
	//write();
	fst;
	int cs = 1;
	while(cin >> h >> w) {
		if(!h && !w) break;

		for(int i=0; i<h; i++) cin >> str[i];

		mem(dp, -1);
		int ans = 0;

		for(int i=0; i<h; i++) {
			for(int j=0; j<w; j++) {
				if(str[i][j] == 'A')
					ans = max(ans, dfs(i, j));
			}
		}

		cout << "Case " << cs++ << ": " << ans << endl;
	}
	return 0;
}
