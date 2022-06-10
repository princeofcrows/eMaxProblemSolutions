#include <bits/stdc++.h>

using namespace std;

#define mx 100005
#define int long long
#define pii pair <int, int>
#define piii pair <int, pii>
#define fi first
#define se second
#define mod 998244353
#define inf 1e18+19
#define pb push_back
#define mem(ara, x) memset(ara, x, sizeof ara)
#define read() freopen("in.txt", "r", stdin)
#define write() freopen("out.txt", "w", stdout)
#define fst ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int fhash[2][5005], res[5005], bhash[2][5005], smod[5005], revsmod[5005];
int dp[5002][5002];
string str;

int bm(int a, int b){
	if(!b) return 1%mod;
	int c = bm(a, b/2);
	c = (c*c)%mod;
	if(b%2) c = (c*a)%mod;
	return c;
}

int32_t main(){
	//read();
	fst;
	int n;
	while(cin >> str) {
		n = str.length();
		int ran = 0;
		int seed = 457;
		smod[0] = 1;
		revsmod[0] = 1;
		for(int i=1; i<=n; i++) {
			smod[i] = (smod[i-1]*seed)%mod;
			revsmod[i] = bm(smod[i], mod-2);
		}

		bhash[0][0] = bhash[1][0] = fhash[1][0] = fhash[0][0] = bhash[0][n+1] = bhash[1][n+1] = 0;
		for(int i=n-1; i>=0; i--) {
			bhash[0][i+1] = (ran + ((int) str[i])*smod[n-i-1] )%mod;
			bhash[1][i+1] = bm(bhash[0][i+1], mod-2);
			ran = bhash[0][i+1];
		}

		ran = 0;
		for(int i=0; i<n; i++) {
			fhash[0][i+1] = (ran + ((int) str[i])*smod[i])%mod;
			fhash[1][i+1] = bm(fhash[0][i+1], mod-2);
			ran = fhash[0][i+1];
		}

		mem(dp, 0);
		mem(res, 0);

		for(int i=1; i<=n; i++) {
			for(int j=0; j<n-i+1; j++) {
				int a = (fhash[0][i+j] - fhash[0][j] + mod)%mod;
				a = (a*revsmod[j])%mod;

				int b = (bhash[0][j+1] - bhash[0][i+j+1] + mod)%mod;
				b = (b*revsmod[n-j-i])%mod;
				//cout << a << " " << b << " " << i << " " << j << endl;

				if(a==b) {
					int l = j + i/2;
					dp[j+1][i+j] = dp[j+1][l] + 1;
					res[dp[j+1][i+j]]++;
				}
			}
		}

		for(int i=n; i>=1; i--) res[i] = res[i+1] + res[i];
		for(int i=1; i<=n; i++) cout << res[i] << " ";
		cout << endl;
	}
	return 0;
}
