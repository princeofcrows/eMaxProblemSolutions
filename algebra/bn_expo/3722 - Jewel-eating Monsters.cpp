// Unfinished and wrong answer
// a and c are not co prime so mod inverse wont work
// a^n + a^(n-1) + .... + a^2 + a := need a log(n) sol for that

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

long long binpow(long long a, long long b, long long c) {
	long long res = 1;

	while (b > 0) {
		if (b & 1) {
			res = (res * a) % c;
		}

		a = ( a * a) % c;
		b >>= 1;
	}

	return res % c;
}


int32_t main(){
	//read();
	//write();
	//fst;
	long long x, a, n, c;
	while(scanf("%lld%lld%lld%lld", &x, &a, &n, &c)!= EOF) {
		if(x == 0 && a == 0 && n ==0 && c == 0) break;

		// x
		// a * (x - 1) = ax - a
		// a * (ax - a - 1) = xa^2 - a^2 - a
		// xa^n - (a^(n+1) - 1) /(a - 1)) + 1

		long long neo = (binpow(a, n+1, c) - (a) % c + c)%c;
		long long den = binpow((a - 1), c - 2, c);
		long long co = (neo * den)%c;
		long long ans = ((binpow(a, n, c)*x)%c - co + c)%c;
		printf("%lld\n", ans);
	}
	return 0;
}
