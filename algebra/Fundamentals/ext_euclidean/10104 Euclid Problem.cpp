#include <bits/stdc++.h>

using namespace std;

#define mx 300005
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

int exEuclid(int a, int b, int& x, int& y) {
	if (b == 0) {
		x = 1;
		y = 0;
		return a;
	}

	int x1, y1;
	int d = exEuclid(b, a % b, x1, y1);
	x = y1;
	y = x1 - y1 * (a / b);
	return d;
}


int32_t main(){
	//read();
	//write();
	//fst;
	int a, b;
	while(cin >> a >> b) {
		int x, y;
		int g = exEuclid(a, b, x, y);
		cout << x << " " << y << " " << g << endl;
	}

	return 0;
}
