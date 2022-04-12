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

long long binPow(long long a, long long b) {
	if (b == 0) return 1;

	long long res = binPow(a, b / 2);

	if (b % 2) {
		return res * res * a;
	}
	else {
		return res * res;
	}
}


int32_t main(){
	//read();
	//write();
	//fst;
	long long n;
	while(sil(n) != EOF) {
		long long ans = 0;

		for(int i=1; i<n; i++) {
			int rest = n - 2, co = 1;
			if(i!=1) {
				rest--;
				co *= 3;
			}

			if(i!=n-1) {
				rest--;
				co *= 3;
			}

			ans = ans + binPow(4, rest)* 4 * co;
		}
		// 4 * (n-1) * 3 ^ (n-2)
		cout << ans << endl;
	}
	return 0;
}
