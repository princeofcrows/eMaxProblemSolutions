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

int res[mx], idx[mx][2];
bool vis[mx];
vector<vector<int> > v;

int gcd(int a, int b) {
	return b ? gcd(b, a%b) : a;
}

long long lcm (int a, int b) {
	long long res = a / gcd(a, b);
	res *= b;
	return res;
}


int32_t main(){
	//read();
	//write();
	//fst;
	int t;
	cin >> t;

	while(t--) {
		int a, b;
		cin >> a >> b;
		cout << gcd(a, b) << " " << lcm(a, b) << endl;
	}

	return 0;
}
