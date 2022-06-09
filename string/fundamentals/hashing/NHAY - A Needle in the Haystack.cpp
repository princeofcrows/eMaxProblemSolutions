#include <bits/stdc++.h>

using namespace std;

#define MAXN 10005
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

#include <string>
using namespace std;


vector<int> computeHash(string const& s, string const& t) {
	const int p = 31;
	const int m = 1e9 + 9;

	long long hashValue[s.length()];
	long long pPow = 1;

	for (int i=0; i<s.length(); i++) {
		char c = s[i];
		hashValue[i] = ((i ? hashValue[i-1] : 0 )+ (c - 'a' + 1) * pPow) % m;
		pPow = (pPow * p) % m;
	}

	pPow = 1;
	long long hashT = 0;
	vector<int> res;

	for(auto c: t) {
		hashT = (hashT + (c - 'a' + 1) * pPow) % m;
		pPow = (pPow * p) % m;
	}

	for (int i=0; i + t.length()<=s.length(); i++) {
		long long hashS = ((hashValue[i + t.length() - 1] - (i==0 ? 0 : hashValue[i-1])) + m)%m;

		if(hashS == hashT) {
			res.pb(i);
		}

		hashT = (hashT * p)%m;
	}

	return res;
}

void printRes(vector<int> v) {
	for(auto u: v) cout << u << "\n";
	if( v.size() == 0) cout << "\n";
}

void solve(string s, string t) {
	printRes(computeHash(s, t));
}


int main() {
	//read();
	// write();
	int n;

	while(cin >> n) {
		string s, t;
		cin >> t >> s;
		solve(s, t);
	}
}
