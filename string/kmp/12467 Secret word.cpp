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

int dp[88][88];
string str;

vector<int> prefixFunction(string s) {
	int n = (int)s.length();

	vector<int> pi(n);

	for (int i = 1; i < n; i++) {
		int j = pi[i-1];
		while (j > 0 && s[i] != s[j])
			j = pi[j-1];
		if (s[i] == s[j])
			j++;
		pi[i] = j;
	}

	return pi;
}

vector<int> kmpPatternSearch(string p, string s){
	int m = p.length();
	int n = s.length();

	vector<int> pi = prefixFunction(p);
	vector<int> res;

	int i = 0;
	int j = 0;

	while (i < n) {
		if (p[j] == s[i]) {
			j++; i++;
		}

		if (j == m) {
			res.push_back(i - j);
			j = pi[j - 1];
		}

		else if (i < n && p[j] != s[i]) {
			if (j != 0)
				j = pi[j - 1];
			else
				i = i + 1;
		}
	}

	return res;
}




void solve(string s, string p) {
	std::vector<int> v = kmpPatternSearch(p, s);

	if(v.size() == 0) cout << "Not Found\n\n";
	else {
		cout << v.size() << "\n";

		for(auto u: v) cout << u + 1 << " ";

		cout << "\n\n";
	}
}

int32_t main(){
	//read();
	//write();

	fst;
	int t;
	cin >> t;

	while(t--) {
		string s, p;
		cin >> s >> p;

		solve(s, p);
	}
	return 0;
}
