#include <bits/stdc++.h>

using namespace std;

#define MAXN 1000005
#define int long long
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

using namespace std;


int32_t main(){
	//read();
	//write();
	//fst;
	int t;
	cin >> t;
	while(t--) {
		int n, ans = 0;
		cin >> n;

		int F1 = 1, F0 = 0;

		for(int i=2; i<=200; i++) {
			int temp = F1;
			F1 = F1 + F0;
			F0 = temp;

			if(F1 > n) break;
			if(F1%2==0) ans = (ans + F1);
		}
		cout << ans << endl;
	}

	return 0;
}
