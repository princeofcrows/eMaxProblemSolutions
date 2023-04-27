#include <bits/stdc++.h>

using namespace std;

#define mx 100005
//#define int long long
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

int dp[5005][5005];

string str;
int ara[5005][5005], sz[5005][5005], cnt[5005], res[5005], z[5005];

int nCr(int n, int r){
	if(n==r) return dp[n][r] = 1;
	if(r==0) return dp[n][r] = 1;
	if(r==1) return dp[n][r] = n % mod;
	if(dp[n][r]) return dp[n][r];
	return dp[n][r] = (nCr(n-1,r) + nCr(n-1,r-1))%mod;
}

void initset(int n){
	for(int i = 1; i<=n; i++) {
		for(int j=1; j<=n; j++) {
			ara[i][j] = j;
			sz[i][j] = 1;
			dp[i][j] = 0;
		}

		cnt[i] = res[i] = 0;
	}
}

int findset(int i, int idx){
	if(ara[idx][i] == i) return i;

	return ara[idx][i] = findset(ara[idx][i], idx);
}

bool issameset(int i, int j, int idx){
	return (findset(i, idx)==findset(j, idx));
}

void unionset(int i, int j, int idx){
	int a = findset(j, idx);
	int b = findset(i, idx);

	if(a==b) return;

	if(sz[idx][a]>=sz[idx][b]) {
		sz[idx][a]+=sz[idx][b];
		ara[idx][b] = a;
	}
	else{
		sz[idx][b]+=sz[idx][a];
		ara[idx][a] = b;
	}
}

void zFunction(string s) {
	int n = (int)s.size();

	for(int i = 0; i < n; i++) {
		z[i] = 0;
	}

	int l = 0, r = 0;

	for(int i = 1; i < n; i++) {
		if(i < r) {
			z[i] = min(r - i, z[i - l]);
		}

		while(s[z[i]] == s[i + z[i]]) {
			z[i]++;
		}

		if(i + z[i] > r) {
			l = i;
			r = i + z[i];
		}
	}
}

int actualIdx(int n, int j) {
	return n - j - 1;
}

void solve(string s, int n) {
	string t = "";
	initset(n);

	for(int i=0; i<n; i++) {
		t = t + s[i];
		string c = t;

		reverse(c.begin(), c.end());

		zFunction(c);

		int id = -1, m = 0;

		for(int j=0; j<c.size(); j++) {
			if(z[j] > m) {
				id = j;
				m = max(m, z[j]);
			}

		}

		for(int j=m; j>0; j--) {
			unionset(i+1, actualIdx(c.length(), id) + 1, j);
		}
	}

	for(int i=0; i<n; i++) {
		bool vis[n+1];
		mem(vis, false);

		for(int j=i; j<n; j++) {
			int grp = findset(j+1, i+1);

			if(!vis[grp]) {
				vis[grp] = true;
				cnt[sz[i+1][grp]]++;
			}
		}
	}

	for(int i=1; i<=n; i++) {
		//cout << cnt[i] << " ";
		for(int j=1; j<=i; j++) {
			long long jt = ((long long)cnt[i] * (long long)nCr(i, j)) % mod;
			res[j] = (res[j] + jt) %mod;
		}
	}
}

int32_t main(){
	//read();
	//write();
	fst;
	int t;
	cin >> t;

	while(t--) {
		int n, q;
		string str;

		cin >> n >> q >> str;

		solve(str, n);

		while(q--) {
			int k;
			cin >> k;

			if(k > n) printf("0\n");
			else printf("%d\n", res[k]);
		}
	}

	return 0;
}
