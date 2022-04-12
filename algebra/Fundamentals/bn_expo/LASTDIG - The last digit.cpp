#include <bits/stdc++.h>

using namespace std;

#define sil(x) scanf("%lld", &x)

long long binPow(long long a, long long b) {
	if (b == 0) return 1;

	long long res = binPow(a, b / 2);

	if (b % 2) {
		return (res * res * a)%10;
	}
	else {
		return (res * res)%10;
	}
}


int32_t main(){
	//read();
	//write();
	//fst;
	long long t;
	sil(t);
	while(t--) {
		long long a, b;
		sil(a); sil(b);
		long long ans = binPow(a, b);
		cout << ans << endl;
	}
	return 0;
}
