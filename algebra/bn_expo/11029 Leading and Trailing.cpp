#include <bits/stdc++.h>

using namespace std;

#define mx 400005
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

void binpow(long long x, long long y) {
	long long res = 1;
	long long a = x, b = y;

	while (b > 0) {
		if (b & 1) {
			res =( res * a)%1000;
		}

		a = (a * a)%1000;
		b >>= 1;
	}

	double c = y*log10(x);
	long long d = pow(10.0, c - floor(c) + 2);
	printf("%03lld...%03lld\n", d, res);
}


int32_t main(){
	//read();
	//write();
	//fst;
	int t; si(t);
	long long x, y;
	while(scanf("%lld%lld", &x, &y)!= EOF) {
		binpow(x, y);
	}
	return 0;
}
