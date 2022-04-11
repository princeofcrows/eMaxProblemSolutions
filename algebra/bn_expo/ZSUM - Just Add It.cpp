#include <bits/stdc++.h>

using namespace std;

#define mx 400005
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

long long binpow(long long a, long long b) {
	long long res = 1;

	while (b > 0) {
		if (b & 1) {
			res = (res * a) % mod;
		}

		a = ( a * a) % mod;
		b >>= 1;
	}

	return res % mod;
}


int32_t main(){
	//read();
	//write();
	//fst;
	long long n, k;
	while(scanf("%lld%lld", &n, &k)!= EOF) {
		if(n == 0 && k == 0) break;

		cout <<
		    (2* binpow(n-1, k) +
		     binpow(n, k) +
		     binpow(n, n) +
		     2 * binpow(n-1, n-1)
		    )%mod << endl;
	}
	return 0;
}
