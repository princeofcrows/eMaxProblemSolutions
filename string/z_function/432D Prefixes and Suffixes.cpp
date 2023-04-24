#include <bits/stdc++.h>

using namespace std;

#define mx 100005
//#define int long long
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



vector<int> zFunction(string s) {
	int n = (int)s.size();
	vector<int> z(n);

	int l = 0, r = 0;

	for(int i = 1; i < n; i++) {
		if(i < r) {
			z[i] = min(r - i, z[i - l]);
		}

		while(s[z[i]] == s[i + z[i]]) {
			z[i]++;
		}

		if(i + z[i] > r) {
			l = i;
			r = i + z[i];
		}
	}

	return z;
}

void solve(string s) {
	vector<int> z = zFunction(s);
	int n = s.length();
	vector<int> cnt(n);

	for(int i=1; i<n; i++) {
		cnt[z[i]]++;
	}

	for(int i=n-2; i>0; i--) cnt[i] += cnt[i+1];

	vector <int> res;

	for(int i=1; i<n; i++) {
		if(z[n - i] == i) {
			res.pb(i);
		}
	}

	cout << res.size() + 1 << "\n";
	for(auto u: res) cout << u << " " << cnt[u] + 1 << "\n";
	cout << n << " " << 1 << endl;
}


int32_t main(){
	//read();
	//write();
	fst;
	string str;

	while(cin >> str) {
		solve(str);
	}

	return 0;
}
