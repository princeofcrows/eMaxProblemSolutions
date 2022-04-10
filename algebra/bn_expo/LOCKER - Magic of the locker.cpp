#include <bits/stdc++.h>

using namespace std;

#define sil(x) scanf("%lld", &x)
#define mod 1000000007
#define read() freopen("in.txt", "r", stdin)

long long binPow(long long a, long long b) {
	if (b == 0) return 1;

	long long res = binPow(a, b / 2);

	if (b % 2) {
		return (((res * res) %mod)  * a )%mod;
	}
	else {
		return (res * res)%mod;
	}
}


int32_t main(){
	//read();
	//write();
	//fst;
	long long t;
	sil(t);
	while(t--) {
		long long n;
		sil(n);
		if(n == 1) {
			cout << 1 << endl;
			continue;
		}
		long long po3 = n / 3, po2 = (3LL ^ (n%3))%3;

		if(po2 == 2) po3--;

		long long ans = (binPow(3, po3) * binPow(2, po2))%mod;
		cout << ans << endl;
	}
	return 0;
}
